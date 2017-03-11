#include <iostream>

int main(int argc, const char *argv[])
{
	int ary[] = {9, 7, 5, 3, 1};
	for (auto &refer: ary)
	{
	    std::cout << "number is " << refer << "\n";
	}

	// Rule: Use references or const references for your declaration in for-each loops for performance reasons
	for (const auto &refer: ary)
	{
	    std::cout << "number is " << refer << "\n";
	}
    return 0;
}
