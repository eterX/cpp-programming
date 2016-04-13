#include <iostream>

int main(int argc, const char *argv[])
{
    enum class Color
	{
	    RED,  // RED is placed in the same scope as Color
		BLUE
	};

	enum class Fruit
	{
	    BANANA, // BANANA is placed in the same scope as Fruit
		APPLE
	};

	Color color = Color::RED;  // Color and RED can be accessed in the same scope (no prefix needed)
	Fruit fruit = Fruit::BANANA;  // Fruit and BANANA can be accessed in the same scope (no prefix needed)

	if (color == fruit) // The compiler will compare a and b as integers
	    std::cout << "color and fruit are equal\n";
    else
		std::cout << "color and fruit are not equal\n";
  
    return 0;
}
