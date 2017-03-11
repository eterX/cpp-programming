#include <iostream>

int getValueFromUser()
{
    std::cout << "Enter an integer: ";
	int a;
	std::cin >> a;
	return a;
}

int main(int argc, const char *argv[])
{
    int x = getValueFromUser();
	int y = getValueFromUser();

	std::cout << x << " + " << y << " = " << x + y << std::endl;

	return 0;
}
