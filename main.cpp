#include <gtest/gtest.h>
#include "ClassThatUsesDB.h"
#include "MockDBConnection.h"
#include "SomeTestSuite.h"



TEST_F(SomeTestSuite, CallsOfMethods)
{
	
	EXPECT_CALL(*Mock, open).WillOnce(::testing::Return(true));
	EXPECT_CALL(*Mock, execQuery).Times(::testing::AtLeast(2));
	EXPECT_CALL(*Mock, close).WillOnce(::testing::Return(true));

	UserClass->openConnection(Mock);
	UserClass->useConnection(Mock, *str);
	UserClass->useConnection(Mock, *str);
	UserClass->closeConnection(Mock);

}


TEST_F(SomeTestSuite, TestOfOpenConnection)
{

	EXPECT_CALL(*Mock, open).WillOnce(::testing::Return(false));
	EXPECT_CALL(*Mock, execQuery).Times(::testing::AtLeast(2));
	EXPECT_CALL(*Mock, close).WillOnce(::testing::Return(true));

	ASSERT_ANY_THROW(UserClass->openConnection(Mock));
	UserClass->useConnection(Mock, *str);
	UserClass->useConnection(Mock, *str);
	UserClass->closeConnection(Mock);

}


TEST_F(SomeTestSuite, TestOfCloseConnection)
{

	EXPECT_CALL(*Mock, open).WillOnce(::testing::Return(true));
	EXPECT_CALL(*Mock, execQuery).Times(::testing::AtLeast(2));
	EXPECT_CALL(*Mock, close).WillOnce(::testing::Return(false));

	UserClass->openConnection(Mock);
	UserClass->useConnection(Mock, *str);
	UserClass->useConnection(Mock, *str);
	ASSERT_ANY_THROW(UserClass->closeConnection(Mock));

}



int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}