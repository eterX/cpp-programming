#include <iostream>

// complie: clang++ --std=c++11 for-each_loops.cpp

int main(int argc, const char *argv[])
{
	int scores[] = { 90, 81, 72, 99, 67, 73 };
	int maxscore = 0;
	for (int score : scores)
	{
	    std::cout << score << "\n";

		if (score > maxscore) { maxscore = score; }
	}

	std::cout << "max score is : " << maxscore << "\n";

    return 0;
}
