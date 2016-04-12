#include <iostream>

enum Foo {
	Foo_cat,
	Foo_dog,
	Foo_fox,
	Foo_duck
};


int main(int argc, char *argv[])
{
	Foo foo(Foo_fox);	
	std::cout << foo;
    return 0;
}
