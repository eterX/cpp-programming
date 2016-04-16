#include <iostream>

enum Result
{
	LE = -1,
	EQ = 0,
    GE = 1
};

Result num_compare(int x, int y)
{
    if (x > y)
	{		
        std::cout << x << " is more than " << y << std::endl;			
		return GE;
	}
	else if (x == y)
	{
        std::cout << x << " is equal than " << y << std::endl;			
		return EQ;
	}
	else
	{
        std::cout << x << " is less than " << y << std::endl;			
		return LE;
	}
}

int main(int argc, const char * argv[])
{
	std::cout << num_compare(2, 3) << std::endl;
    return 0;
}
