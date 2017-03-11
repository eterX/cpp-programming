#include <iostream>

void change_value(int &reference)
{
    reference = 66;
}

int main(int argc, const char *argv[])
{
    int value = 5;
	std::cout << "previous value: " << value << "\n";
	change_value(value);
	std::cout << "current value: " << value << "\n";

	return 0;
}
