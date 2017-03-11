#include <iostream>
#include <random>

int main(int argc, const char *argv[])
{
    std::random_device rd;         // Use a hardware entropy source if available, otherwise use PRNG
	std::mt19937 mersenne(rd());   // initialize our mersenne twister with a random seed

	// Note: Due to a bug in theh Code::Blocks compiler, if using Code::Blocks on Windows, delete the two lines above and uncomment this line:
	// std::mt19937 mersenne(static_cast<unsigned int>(time(0)));   // initialize our mersenne twister with a random seed
	
	// Print a bunch of random numbers
	for (int count = 0; count < 48; ++count)
	{
	    std::cout << mersenne() << "\t";

		// If we've printed 4 numbers, start a new row
		if ((count + 1) % 4 == 0)
		{
		    std::cout << "\n";
		}
	}
}
