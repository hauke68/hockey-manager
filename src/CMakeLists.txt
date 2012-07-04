set(SOURCES
				arena.cc
				database.cc
				league.cc
				manager.cc
				main.cc
				player.cc
				team.cc
)

find_library(libsqlite3 SHARED)

find_package(LibXml2 REQUIRED)
find_package(ClanLib REQUIRED)

if(ClanLib_FOUND)
				ADD_DEFINITIONS(-std=c++0x -DUSE_CLANLIB -I/usr/include/ClanLib-2.3 -I/usr/local/include/ClanLib-2.3)
				FIND_LIBRARY(libfreetype SHARED)
				FIND_LIBRARY(libfontconfig SHARED)
else(ClanLib_FOUND)
				message("ClanLib library not found")
endif(ClanLib_FOUND)

find_package(Sqlite3 REQUIRED)

if(SQLITE3_FOUND)
				ADD_DEFINITIONS(-DUSE_SQLITE3)
else(SQLITE3_FOUND)
				message("SQLite3 not found")
				ADD_DEFINITIONS(-DUSE_FLAT_FILES)
endif(SQLITE3_FOUND)

include_directories(${SQLITE3_INCLUDE_DIRS})
link_libraries(${SQLITE3_LIBRARIES}
								${LIBXML2_LIBRARIES}
								-lfreetype
								-lfontconfig
								-lpthread
								${ClanLib_LIBRARIES}
)

add_executable(hockey-manager ${SOURCES})

