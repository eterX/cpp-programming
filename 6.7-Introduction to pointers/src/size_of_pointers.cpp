#include <iostream>

int main(int argc, const char *argv[])
{
    char *p_char;    // chars are 1 byte
	int  *p_int;     // ints are usually 4 bytes
	struct st
	{
        int x;
		int y;
		int z;
	};

	st   *p_struct;  // st is probably 12 bytes

	std::cout << sizeof(p_char) << '\n';   // prints 4
	std::cout << sizeof(p_int) << '\n';    // prints 4
	std::cout << sizeof(p_struct) << '\n'; // prints 4
}
