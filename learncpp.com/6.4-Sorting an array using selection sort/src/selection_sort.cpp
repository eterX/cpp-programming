#include <iostream>
#include <algorithm>

int main(int argc, const char * argv[])
{
    const int size = 5;
	int array[size] = { 30, 50, 20, 10, 40 };

	// Step through each element of the array
	for (int startIndex = 0; startIndex < size; ++startIndex)
	{
        // smallestIndex is the index of the smallest element we've encountered so far.
		int smallestIndex = startIndex;

	    // Look for smallest element remaining in the array (starting at startIndex+1)
		for (int currentIndex = startIndex + 1; currentIndex < size; ++currentIndex)
		{
		    // If the current element is smaller than our previously found smallest
			if (array[currentIndex] < array[smallestIndex])
			{
			    // This is the new smallest number for this iteration
				smallestIndex = currentIndex;
			}
		}

		// Swap our start element with our smallest element
		std::swap(array[startIndex], array[smallestIndex]);
	}

	// Now print our sorted array as proof it works
	for (int index = 0; index < size; ++index)
	{
	    std::cout << array[index] << ' ';
	}

	return 0;
}
