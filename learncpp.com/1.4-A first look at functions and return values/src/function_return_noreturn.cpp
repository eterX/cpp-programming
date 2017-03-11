#include <iostream>

// void means the function does not return a value to the caller
void returnNothing()
{
    // This function does not return a value so no return statement is needed
}


// int means the function returns an integer value to the caller
int return5()
{
    return 5;  // this function returns an integer, so a return statement is needed
}


int main(int argc, const char *argv[])
{
    std::cout << return5() << std::endl;  // prints 5
	std::cout << return5() + 2 << std::endl;  // prints 7

	returnNothing(); // okay: function returnNothing() is called, no value is returned
	return5();  // okay: function return5() is called, return value is discarded

	std::cout << returnNothing();  // This line will not compile. You'll need to comment it out to continue.
}

