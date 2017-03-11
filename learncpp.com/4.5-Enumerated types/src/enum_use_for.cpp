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
	Foo foo(Foo_fox);	
	who(foo);
    return 0;
}
