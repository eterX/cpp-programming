#include <iostream>

// compile: clang++ -std=c++11 compare_diff_enum_class.cpp
//


int main(int argc, const char * argv[])
{
    enum class Color
	{
	    RED,
		BLUE
	};

	Color color = Color::RED;

	if (color == Color::RED)  // it's okay
	    std::cout << "The color is red!\n";
    else if (color == Color::BLUE)
		std::cout << "The color is blue!\n";

    return 0;	
}
