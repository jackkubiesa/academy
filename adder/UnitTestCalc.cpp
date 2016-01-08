#include "stdafx.h"
#include "gtest/gtest.h"
#include "Calculator.h"

TEST(testCalc, addTest)
{
	//Calculator calc;

	//EXPECT_EQ(8, calc.add(3,5));
	EXPECT_EQ(8, adder(3, 5));
}


int main()
{
    return 0;
}
