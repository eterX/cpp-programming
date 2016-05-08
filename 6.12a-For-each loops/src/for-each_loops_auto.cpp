#include <iostream>

int main()
{
    int ary[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89};
	for (auto num: ary)
	{
	    std::cout << num << " ";
	}

	return 0;
}
