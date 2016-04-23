#include <iostream>

int main()
{
    char mystring[] = "string";
	std::cout << mystring << " has " << sizeof(mystring) << " characters.\n";
	for (int index=0; index < sizeof(mystring); ++index)
	{
	    std::cout << static_cast<int>(mystring[index]) << " ";
	}

	return 0;
}
