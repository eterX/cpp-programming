#include <iostream>
#include "add.h"


int main(int argc, const char *argv[])
{
	int x = 1;
    int y = 2;	
    std::cout << x << "+" << y << "=" << add(x, y) << std::endl;
}
