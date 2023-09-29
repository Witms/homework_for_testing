#include "ClassThatUsesDB.h"
#include "DBConnection.h"
#include <exception>



void ClassThatUsesDB::openConnection(DBConnection* DB)
{
	bool is_open = DB->open();
	if (!is_open)
		return throw std::exception("DataBase isn`t opened");
}


void ClassThatUsesDB::useConnection(DBConnection* DB, std::string& str)
{
	std::string result = DB->execQuery(str);
}


void ClassThatUsesDB::closeConnection(DBConnection* DB)
{
	bool is_close = DB->close();
	if (!is_close)
		return throw std::exception("DataBase isn`t closed");
}