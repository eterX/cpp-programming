#include <iostream>

int main(int argc, const char *argv[])
{
    using std::cout;  // this using declaration tells the compiler that cout should resolve to std::cout
	cout << "Hello World!";  // so no std:: prefix is needed here!
	return 0;
}
