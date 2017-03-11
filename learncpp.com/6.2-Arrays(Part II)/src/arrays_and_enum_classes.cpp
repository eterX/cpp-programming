#include <iostream>

enum class StudentNames
{
    KENNY, // 0
	KYLE,  // 1
	STAN,  // 2
	BUTTERS,      // 3
	CARTMAN,      // 4
	WENDY,        // 5
	MAX_STUDENTS  // 6
};


int main(int argc, const char * argv[])
{
    // int testScores[StudentNames::MAX_STUDENTS];   // allocate 6 integers
    // testScores[StudentNames::STAN] = 76;	

    int testScores[static_cast<int>(StudentNames::MAX_STUDENTS)];   // allocate 6 integers
    testScores[static_cast<int>(StudentNames::STAN)] = 76;	
    return 0;
}
