#include <iostream>
#include <cstdlib>    // srand() / rand()
#include <ctime>      // time()

int main(int argc, const char * argv[])
{
	srand(static_cast<unsigned int>(time(0)));	 // set initial seed value to system clock

	for (int count; count < 100; ++count)
	{
		std::cout << rand() << "\t";

		// If we've printed 5 numbers, start a new row
		if ((count + 1) % 5 == 0)
		{
			std::cout << "\n";	
		}
	}
    return 0;
}
