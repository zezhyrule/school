#include<iostream>

using std::cout;
using std::endl;
using std::string;

struct mine
{
	int val1;
	double val2;
	string val3;
};

int main(int argc, char** argv)
{
	mine m;
	m.val1 = 10;
	m.val2 = 10.3;
	m.val3 = "hello";

	cout << m.val1 << ", " << m.val2 << ", " << m.val3 << endl;

	return 0;
}
