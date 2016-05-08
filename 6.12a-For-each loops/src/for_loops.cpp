#include <iostream>

int main(int argc, const char *argv[])
{
    const int numStudents = 5;
	int scores[numStudents] = { 84, 92, 76, 81, 56 };
	int maxScore = 0;    // keep track of our largest score

	for (int student=0; student < numStudents; ++student)
	{
	    if (scores[student] > maxScore)
		{
		    maxScore = scores[student];
		}
	}

	std::cout << "The best score was " << maxScore << "\n";

	return 0;

}
