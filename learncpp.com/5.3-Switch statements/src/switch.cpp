#include <iostream>

enum Colors
{
    COLOR_BLACK,
	COLOR_WHITE,
	COLOR_RED,
	COLOR_GREEN,
	COLOR_BLUE
};


void printColor(Colors color)
{
    switch (color)
	{
		case COLOR_BLACK:
			std::cout << "BLACK" << std::endl;
			break;
        case COLOR_WHITE:
			std::cout << "WHITE" << std::endl;
			break;
		case COLOR_RED:
			std::cout << "RED" << std::endl;
			break;
	    case COLOR_GREEN:
			std::cout << "GREEN" << std::endl;
			break;
	    case COLOR_BLUE:
			std::cout << "BLUE" << std::endl;
			break;
	    default:
			std::cout << "Who knowns" << std::endl;						 
	}
}

int main(int argc, const char * argv[])
{
    Colors color = COLOR_BLUE;
	printColor(color);
}
