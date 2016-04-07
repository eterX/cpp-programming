#include <iostream>

int main(int argc, const char *argv[])
{
    double zero = 0.0;
	double posinf = 5.0 / zero;  // positive infinity
	std::cout << posinf << std::endl;

	double neginf = -5.0 / zero; // negative onfinity
    std::cout << neginf << std::endl;

    double nan = zero / zero;    // not a number (mathematically invalid)
    std::cout << nan << std::endl;

    return 0;	
}
