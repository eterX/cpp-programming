#include <iostream>

int main(int argc, const char * argv[])
{
    int x;
	std::cout << "Please enter a number : ";
	std::cin >> x;

	switch (x)
	{
	    case 0:
		  	break;
		case 9:
		    return 0;
		default:
		    std::cout << "number is " << x << std::endl;	
	}

	std::cout << "return main" << std::endl;
	return 0;

}
