#include <iostream>
#include <iomanip>

int main(int argc, const char *argv[])
{
    double d(0.1);
	std::cout << d << std::endl;  // use default cout precious of 6
	std::cout << std::setprecision(17);
	std::cout << d << std::endl;
	return 0;
}
