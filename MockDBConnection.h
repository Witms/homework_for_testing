#pragma once
#include "DBConnection.h"
#include <gmock/gmock.h>


class MockDBConnection : public DBConnection
{
public:
	MOCK_METHOD(bool, open, (), (override));
	MOCK_METHOD(bool, close, (), (override));
	MOCK_METHOD(std::string, execQuery, (std::string&), (override));

};