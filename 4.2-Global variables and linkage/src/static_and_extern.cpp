#include <iostream>
#include "extern.h"

static int g_x;    // g_x is static, and can only be used within this file
int g_y(20);       // g_y is external, and can be used by other files

int main(int argc, const char * argv[])
{
    std::cout << g_x << std::endl;
	std::cout << g_y << std::endl;
    return 0;
}
