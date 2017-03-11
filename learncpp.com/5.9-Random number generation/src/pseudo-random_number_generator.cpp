#include <iostream>

unsigned int pseudo_random_number_generator()
{
    // our initial starting seed is 5323
	static unsigned int seed = 5323;

	// Take the current seed and generate a new value from it
	// Due to our use of large constants and overflow. it would be
	// very hard for someone to predirect what the next number is 
	// going to be from the previous one.
	
	seed = (8253729 * seed + 2396403);

	// Take the seed and return a value between 0 and 32767
	return seed % 32768;
}


int main(int argc, const char * argv[])
{
    // Print 100 random numbers
	for (int count=0; count < 100; ++count)
	{
		std::cout << pseudo_random_number_generator() << "\t";

		// If we've printed 5 numbers, start a new raw
		if ((count + 1) % 5 == 0)
		{
				std::cout << "\n";	
		}	
	}
	return 0;
}
