#include <iostream>

// compile: clang++ --std=c++11 demo.cpp

struct Employee
{
    short id;
	int age;
	double wage;
};


int main(int argc, const char *argv[])
{
    Employee ceo;
	Employee cto = {2, 32, 60000.0};
	
	// In c++ 11, we can also use uniform initialization
	Employee cso {3, 31, 60000.0};
    return 0;
}
