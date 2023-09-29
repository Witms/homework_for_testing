#pragma once
#include <gtest/gtest.h>
#include "ClassThatUsesDB.h"
#include "MockDBConnection.h"

class SomeTestSuite : public ::testing::Test
{
protected:
    void SetUp()
    {
        UserClass = new ClassThatUsesDB();
        Mock = new MockDBConnection();
        str = new std::string{ "TEST" };
    }

    void TearDown()
    {
        delete UserClass;
        delete Mock;
        delete str;
    }

protected:
    ClassThatUsesDB* UserClass;
    MockDBConnection* Mock;
    std::string* str;
};