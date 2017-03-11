#include <iostream>

int main(int argc, const char * argv[])
{
LoopLabel:
    std::cout << "Please enter a number: ";
    int x;
    std::cin >> x;

    if (x < 10)
	{
	    goto LoopLabel;
	}
	else
	{
	    std::cout << "number is " << x << std::endl;
	}

    return 0;
}

