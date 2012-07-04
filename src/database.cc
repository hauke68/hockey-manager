#include "database.h"

#include <assert.h>
#include <malloc.h>
#include <stdarg.h>
#include <stdlib.h>

const char *NoStringException::what() const throw() {

	return "no string";
}

// Class DBObject
DBObject::DBObject() {

	val_type     = 0;
	is_key       = 0; // This object is not a primary key
	value.sValue = NULL;

}

// copy constructor
DBObject::DBObject(const DBObject &o) {

	this->val_type = o.val_type;
	this->is_key   = o.is_key;

	switch(o.val_type) {
		case SQLITE_TEXT:
			this->value.sValue = o.value.sValue;
			break;
		case SQLITE_INTEGER:
			this->value.iValue = o.value.iValue;
			break;
		case SQLITE_FLOAT:
			this->value.fValue = o.value.fValue;
			break;
	}
}

DBObject::DBObject(string s) {

	value.sValue = (char*)s.c_str();
	val_type = SQLITE_TEXT;
}

DBObject::DBObject(const char *s) {

	value.sValue = (char*)s;
	val_type = SQLITE_TEXT;
}

DBObject::DBObject(int i) {

	value.iValue = i;
	val_type = SQLITE_INTEGER;
}

DBObject::DBObject(long int i) {

	value.iValue = i;
	val_type = SQLITE_INTEGER;
}

DBObject::DBObject(unsigned int i) {

	value.uiValue = i;
	val_type = SQLITE_UINT;
}

DBObject::DBObject(float f) {

	value.fValue = f;
	val_type = SQLITE_FLOAT;
}

DBObject::operator char*&() {

	if (val_type != SQLITE_TEXT)
		throw NoStringException();

	return value.sValue;
}

DBObject::operator int&() {

	return (int&)value.iValue;
}

DBObject::operator long int&() {

	return value.iValue;
}

DBObject::operator unsigned int&() {

	return (unsigned int&)value.iValue;
}

DBObject::operator float&() {

	return value.fValue;
}

DBObject& DBObject::operator=(const DBObject &o) {

	if (this != &o) {
		this->val_type = o.val_type;
		switch(o.val_type) {
		case SQLITE_TEXT:
			this->value.sValue = o.value.sValue;
			break;
		case SQLITE_INTEGER:
			this->value.iValue = o.value.iValue;
			break;
		case SQLITE_UINT:
			this->value.uiValue = o.value.uiValue;
			break;
		case SQLITE_FLOAT:
			this->value.fValue = o.value.fValue;
			break;
		}
	}

	return *this;
}

int DBObject::getValType() {

	return val_type;
}

string DBObject::to_str() {

	char res[512];

	switch(val_type) {
	case SQLITE_TEXT:
		return value.sValue;
		break;
	case SQLITE_INTEGER:
		snprintf(res, 512, "%ld", value.iValue);
		break;
	case SQLITE_UINT:
		snprintf(res, 512, "%d", value.uiValue);
		break;
	case SQLITE_FLOAT:
		snprintf(res, 512, "%f", value.fValue);
		break;
	default:
		return "(error)";
		break;
	}

	return (string)res;
}

char DBObject::isKey() {

	return(is_key);
}

void DBObject::setKey(char k) {

	is_key = k;
}

// Friends of DBObject
ostream& operator<< (ostream &out, DBObject &o) {

	switch(o.val_type) {
	case SQLITE_TEXT:
		out << o.value.sValue;
		break;
	case SQLITE_INTEGER:
		out << o.value.iValue;
		break;
	case SQLITE_UINT:
		out << o.value.uiValue;
		break;
	case SQLITE_FLOAT:
		out << o.value.fValue;
		break;
	}

	return out;
}

// Class Database

// Public parts
Database::Database() {

	__open((string)getenv("HOME") + "/.iceman.dat");
}

Database::Database(string name) {

	__open(name);
}

Database::~Database() {

#ifdef USE_SQLITE3
	sqlite3_close(hDB);
#endif // USE_SQLITE3

#ifdef USE_FLAT_FILES
	hDB->close();
#endif // USE_FLAT_FILES

}

int Database::Insert(string table, string fields, ...) {

	va_list ap;
	int     cnt;

}

int Database::Insert(string table, DBRow row) {

	string fields;
	string values;
	string query;

	if(!tableExists(table))
		createTable(table, row);

	// Iterate over DBRow
	for(DBRow::iterator iter = row.begin(); iter != row.end(); ++iter) {
		string f;
		string v;

		try {
			f = (string)((*iter).first);
		} catch(...) {
			f = "";
		}

		// Sometimes there are non-string values, so we handle them in catch block
		try {
			v = "'" + (string)((*iter).second) + "'";
		} catch(NoStringException &e) {
			if ((*iter).second.isKey() || (f == "id")) {
				if((int)((*iter).second) == 0) {
					continue;
				} else {
					// We better should do an update here...
					return(Update(table, row));
				}
			}

			if ((*iter).second.getValType() == SQLITE_FLOAT)
				v = "'" + (*iter).second.to_str() + "'";
			else
				v = (*iter).second.to_str();
		}

		fields += f + ",";
		values += v + ",";
	}

	// Cut off the trailing comma
	fields.erase(fields.size()-1);
	values.erase(values.size()-1);

	query = "INSERT INTO " + table + "(" + fields + ") VALUES (" + values + ");";

	return(__exec(query));
}

int Database::Update(string table, DBRow row) {

	string query;
	string settings;
	string prim_key;
	string prim_key_val;

	// Iterate over DBRow
	for(DBRow::iterator iter = row.begin(); iter != row.end(); ++iter) {
		string f;
		string v;

		try {
			f = (string)((*iter).first);
		} catch(...) {
			continue; // FIXME: If we have no index, we better should break off
		}

		// Sometimes there are non-string values, so we handle them in catch block
		try {
			v = "'" + (string)((*iter).second) + "'";
		} catch(NoStringException &e) {
			if ((*iter).second.isKey() || (f == "id")) {
				if((int)((*iter).second) != 0) {
					prim_key = f;
					prim_key_val = (*iter).second.to_str();
					continue;
				} else {
					return(Insert(table, row));
				}
			}
			if ((*iter).second.getValType() == SQLITE_FLOAT)
				v = "'" + (*iter).second.to_str() + "'";
			else
				v = (*iter).second.to_str();
		}
		settings += f + "=" + v + ",";
	}

	settings.erase(settings.size()-1);

	query = "UPDATE " + table + " SET " + settings + " WHERE " + prim_key + "=" + prim_key_val;

	return(__exec(query));
}

DBTable *Database::Load(string table) {

	DBTable *t = new(DBTable);

	__exec("SELECT * FROM " + table, t);

	return(t);
}

DBTable *Database::Load(string table, string key_name, unsigned long key_val) {

	char *s;
	DBTable *t = new(DBTable);

	s = (char*)malloc(128);
	sprintf(s, "%ld", key_val);
	__exec("SELECT * FROM " + table + " WHERE " + key_name + "=" + s, t);

	free(s);

	return(t);
}

int Database::tableExists(string name) {

	int res;

#ifdef USE_SQLITE3
	DBTable *t = new(DBTable);

	__exec("SELECT * FROM sqlite_master WHERE type='table' AND tbl_name='" + name + "';", t);

	res = t->size() > 0;
	delete t;
#endif

	return res;
}

int Database::Exec(string query, DBTable *table) {

	return(__exec(query, table));
}

// Private parts
int Database::__open(string name) {

	hDB = NULL;

#ifdef USE_SQLITE3
	if(sqlite3_open(name.c_str(), &hDB) != SQLITE_OK)
		throw exception();
#endif // USE_SQLITE3

#ifdef USE_FLAT_FILES
	hDB = new(fstream(name));
#endif // USE_FLAT_FILES

	assert(hDB != NULL);

	return 0;
}

int Database::__exec(string query, DBTable *table) {

	int   res;
	int   i;

	if(table != NULL) {
		table->clear();
	}

#ifdef USE_SQLITE3
	sqlite3_stmt *stmt;
	int          res_cols;
	string       col_name;

	// Prepare query
#ifdef DEBUG
	cout << "Query: " << query << endl;
#endif
	sqlite3_prepare(this->hDB, query.c_str(), query.length(), &stmt, NULL);
	while(sqlite3_step(stmt) == SQLITE_ROW) {
		DBRow row;
		// Get data from query if we have any data
		res_cols = sqlite3_column_count(stmt);
		for(i = 0; i < res_cols; i++) {
			DBObject o;
			col_name = sqlite3_column_name(stmt, i);
			switch(sqlite3_column_type(stmt, i)) {
			case SQLITE_TEXT:
				o = (char*)sqlite3_column_text(stmt, i);
				break;
			case SQLITE_INTEGER:
				o = (long)sqlite3_column_int64(stmt, i);
				break;
			case SQLITE_UINT:
				o = (int)sqlite3_column_int(stmt, i);
				break;
			case SQLITE_FLOAT:
				o = (float)sqlite3_column_double(stmt, i);
				break;
			}
			row.insert(DBRow::value_type((string)col_name.c_str(), o));
#ifdef DEBUG
			cout << col_name.c_str() << ": " << o << endl;
#endif
		}

#ifdef DEBUG
		cout << "We collected:" << endl;
		for(DBRow::iterator it = row.begin(); it != row.end(); it++) {
			cout << (*it).first << ": " << (*it).second << endl;
		}
#endif
		if(table != NULL) {
			table->push_back(row);
		}
	}

#ifdef DEBUG
	cout << "Stored rows: " << table->size() << endl;
	for(int h = 0; h < table->size(); h++) {
		DBRow a;
		a = table->at(h);
		for(DBRow::iterator it = a.begin(); it != a.end(); it++) {
			cout << (*it).first << ": " << (*it).second << endl;
		}
	}
#endif

	// Destroy statement and free memory
	res = sqlite3_finalize(stmt);
#endif

	return res; // > 0 means: Error!
}

int Database::createTable(string name, DBRow row) {

	string s;

#ifdef USE_SQLITE3
	DBObject     o;
	string       query = "CREATE TABLE " + name + " (";
	string       prim_key = "";

	// iterate over DBRow
	for(DBRow::iterator iter = row.begin(); iter != row.end(); ++iter) {
		o = row[(*iter).first];
		query += (*iter).first;
		switch(o.getValType()) {
		case SQLITE_TEXT:
			query += " VARCHAR(1024)";
			break;
		case SQLITE_INTEGER:
		case SQLITE_UINT:
			query += " INTEGER";
			break;
		case SQLITE_FLOAT:
			query += " DECIMAL(16,2)";
			break;
		}
		query += ",";
		if((string)((*iter).first) == (string)"id")
			prim_key = (*iter).first;
	}
	if(prim_key != "")
		query += " primary key(" + prim_key + ")";
	else
		query.erase(query.end()-1);

	query += ");";
	return(__exec(query));

#endif

}

int Database::getFieldType(string table, string fieldname) {

#ifdef USE_SQLITE3
	const char *pzDataType;
	const char *pzCollSeq;
	int  pNotNull;
	int  pPrimaryKey;
	int  pAutoInc;

	return(sqlite3_table_column_metadata(this->hDB, NULL, table.c_str(),
																			 fieldname.c_str(), &pzDataType,
																			 &pzCollSeq, &pNotNull, &pPrimaryKey,
																			 &pAutoInc));
#else
	return 0;
#endif
}
