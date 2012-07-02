#ifndef _DATABASE_H_
#define _DATABASE_H_

#include <exception>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#ifdef USE_SQLITE3
#include <sqlite3.h>
#else
#ifdef USE_FLAT_FILES
#include <fstream>
#endif // USE_FLAT_FILES
// Stolen from SQLite3 but we need it for easier hacking later!
#define SQLITE_INTEGER  1
#define SQLITE_FLOAT    2
#define SQLITE_BLOB     4
#define SQLITE_NULL     5
#ifdef SQLITE_TEXT
# undef SQLITE_TEXT
#else
# define SQLITE_TEXT    3
#endif
#define SQLITE3_TEXT    3
#endif // USE_SQLITE3

#define SQLITE_UINT 10

using namespace std;

typedef union {
	long int     iValue;
	unsigned int uiValue;
	float        fValue;
	char         *sValue;
} utValue;

// class NoStringException
class NoStringException : public exception {

 public:
	const char* what() const throw();
};

// class DBObject
class DBObject {

 private:
	utValue value;
	int     val_type;
	char    is_key;

 public:
	DBObject();
	DBObject(const DBObject&);

	DBObject(string);
	DBObject(const char*);
	DBObject(int);
	DBObject(long int);
	DBObject(unsigned int);
	DBObject(float);

	operator char*&();
	operator int&();
	operator long int&();
	operator unsigned int&();
	operator float&();
	friend ostream& operator<< (ostream &out, DBObject &o);

	DBObject& operator=(const DBObject&);

	int    getValType();
	string to_str();
	char   isKey();
	void   setKey(char);
};

typedef map<string, DBObject> DBRow;
typedef vector<DBRow> DBTable;

// class database
class Database {

 private:
#ifdef USE_SQLITE3
	sqlite3 *hDB;
#else
#ifdef USE_FLAT_FILES
	fstream *hDB;
#endif // USE_FLAT_FILES
#endif // USE_SQLITE3

	int __open(string);
	int __exec(string query, DBTable *table = NULL);

	int createTable(string, DBRow);
	int getFieldType(string, string);

 public:
	Database();
	Database(string);
	~Database();

	int Insert(string table, string fields, ...);
	int Insert(string, DBRow);
	int Update(string, DBRow);
	DBTable *Load(string);
	DBTable *Load(string, string, unsigned long);
	int tableExists(string);
	int Exec(string query, DBTable *table = NULL);
};

#endif
