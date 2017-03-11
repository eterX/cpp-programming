#include <iostream>

int main(int argc, const char * argv[])
{
    for (int x=0;x < 10;++x)  // ++x VS x++
	{
	    std::cout << x;
	}		
    return 0;
}
