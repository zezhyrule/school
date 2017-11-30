#include <iostream>
#include "MyFriend.h"

void printObject(const myFriend& obj)
{
	std::cout << obj.value1 << ", " << obj.value2 << std::endl;
}

int main(int argc, char** argv)
{
	myFriend object1(2, -4.5);
	printObject(object1);

	return 0;
}
