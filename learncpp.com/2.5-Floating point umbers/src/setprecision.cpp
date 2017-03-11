#include <iostream>
#include <iomanip>   // for std::setprecision()

int main(int argc, const char * argv[])
{
	// show 16 digits	
    std::cout << std::setprecision(16);
    float f = 3.33333333333333333333333333333f;
	std::cout << f << std::endl;
    double d = 3.3333333333333333333333333333;
    std::cout << d << std::endl;
    return 0;	
}
