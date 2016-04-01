#include <iostream>

int cout() // declares "cout" function
{
	return 5;	
}

int main(int argc, char *argv[])
{
	using namespace std;  // makes std::cout accessible as "cout"
	cout << "Hello, world!";  // uh oh! Which cout do we want here?

    return 0;	
}
