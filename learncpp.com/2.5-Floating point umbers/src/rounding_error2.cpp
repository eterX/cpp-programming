#include <iostream>
#include <iomanip>

int main(int argc, const char *argv[])
{
    std::setprecision(17);

	double d1(1.0);
	std::cout << d1 << std::endl;

	double d2(0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1);  // should equal 1.0
	std::cout << d2 << std::endl;
	return 0;
}
