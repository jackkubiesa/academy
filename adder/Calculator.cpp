#include "Calculator.h"

Calculator::Calculator()
{
}


Calculator::~Calculator()
{
}


int Calculator::add(int a, int b)
{
	return a + b;
}

int adder(int a, int b)
{
	return a + b;
}

int main()
{
	Calculator calc;
	int res = calc.add(3, 4);
}
