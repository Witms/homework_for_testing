#pragma once
#include<string>

class DBConnection
{
public:
	DBConnection() {};
	virtual ~DBConnection() {};
	virtual bool open() = 0;
	virtual bool close() = 0;
	virtual std::string execQuery(std::string&) = 0;
};