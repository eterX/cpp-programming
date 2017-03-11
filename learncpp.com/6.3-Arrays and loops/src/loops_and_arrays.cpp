#include <iostream>

double average(int len, int array[])
{
	int totalScore = 0;
	double average_score;
       
	// use a loop to calculate totalScore
	for (int n = 0; n < len; ++n)
	{
	    totalScore += array[n];
	}

	average_score = static_cast<double>(totalScore) / len;
	return average_score;
}

int max(int len, int array[])
{
    int maxScore = 0;

	for (int n = 0; n < len; ++n)
	{
	    if (array[n] > maxScore)
		{
		    maxScore = array[n];		
		}
	}

	return maxScore;
}

int main(int argc, const char * argv[])
{
    const int numStudents = 5;
	int scores[numStudents] = { 84, 92, 76, 81, 56 };
	std::cout << "Average Score: " << average(numStudents, scores) << "\n";
    std::cout << "Max Score: " << max(numStudents, scores) << "\n";
	return 0;
}
