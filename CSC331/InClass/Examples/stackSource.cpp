#include <iostream>
#include "Stack.h"

int main(int argc, char** argv)
{
	Stack s1;

	s1.push(3.14);
	s1.print();
	s1.push(10.8);
	s1.push(7.0);
	std::cout<<s1.peek()<<std::endl;
	std::cout<<s1.contains(2)<<std::endl;
	std::cout<<s1.contains(10.4)<<std::endl;
	std::cout<<s1.pop()<<std::endl;
	s1.print();

	return 0;
}
