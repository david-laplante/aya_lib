#include "gtest/gtest.h"

#include <aya_lib/aya_lib.hpp>

TEST(TestCaseName, TestName)
{
	EXPECT_EQ(0, aya::aya_lib_main());
}
