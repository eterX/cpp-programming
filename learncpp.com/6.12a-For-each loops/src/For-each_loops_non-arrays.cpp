#include <iostream>
#include <vector>

int main(int argc, const char *argv[])
{
	std::vector<int> demo = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34}; 
	for (const auto &num: demo)
	{
	    std::cout << num << " ";
	}
    return 0;
}
