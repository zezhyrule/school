#include <iostream>
#include "TestTemplate.h"
#include "TestTemplate.cpp"

int main(int argc, char** argv)
{
	TestTemplate<char> t1('c');
	std::cout << t1.getVal() << std::endl;
	t1.setVal('T');
	std::cout << t1.getVal() << std::endl;

	TestTemplate<int> t2(154);
	std::cout << t2.getVal() << std::endl;
	t2.setVal(2654);
	std::cout << t2.getVal() << std::endl;

	return 0;
}
