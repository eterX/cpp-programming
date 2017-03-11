#include <iostream>
#include <iomanip>   // for std::setprecision()

int main(int argc, const char * argv[])
{
	float f(123456789.0f);  // f has 9 significant digits	
    std::cout << std::setprecision(16);  // because we want to show all 9 significant digits in f
	std::cout << f << std::endl;  // it outputs "123456792"
    return 0;	
}
