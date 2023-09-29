#pragma once
#include <string>

class DBConnection;

class ClassThatUsesDB
{
public:
	ClassThatUsesDB() {};
	~ClassThatUsesDB() {};
	void openConnection(DBConnection*);
	void useConnection(DBConnection*, std::string&);
	void closeConnection(DBConnection*);
};