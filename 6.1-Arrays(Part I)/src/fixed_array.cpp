#include <iostream>

int main(int argc, const char *argv[])
{
    // using a literal constant
	int array_1[5];   // ok

	// using a macro symbolic constant
    #define ARRAY_SIZE 5
	int array_2[ARRAY_SIZE];  // Syntactically okay, but don't do this

	// using a symbolic constant
	const int arraySize = 5;
	int array_3[arraySize];     // ok

	// using an enumerator
	enum ArrayElements
	{
	    MAX_ARRAY_SIZE = 5
	};
	int array_4[MAX_ARRAY_SIZE];

	/*
	 *
	// using a non-const variable
	int size;
	std::cin >> size;
	int array_5[size];    // Not ok -- size is not a compile-time constant!

	// using a runtime const variable
	int temp = 5;
	const int size = temp;
	int array_6[size];    // Not ok -- size is a runtime constant, not a compile-time constant!
	*/

	return 0;
}
