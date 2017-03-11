#include <iostream>

enum Foo {
	Foo_cat,
	Foo_dog,
	Foo_fox,
	Foo_duck
};


void who(Foo animal)
{
    if (animal == Foo_cat)
        std::cout << "I'm a cat!";
    else if (animal == Foo_dog)
        std::cout << "I'm a dog!";
    else if (animal == Foo_fox)
    	std::cout << "I'm a fox!";
    else if (animal == Foo_duck)
    	std::cout << "I'm a duck!";
    else
        std::cout << "Who knows?";	
}

int main(int argc, char *argv[])
{
    int animal_number;	
    std::cout << "Please input a animal number: ";
    std::cin >> animal_number;
    who(static_cast<Foo>(animal_number));
    return 0;
}
