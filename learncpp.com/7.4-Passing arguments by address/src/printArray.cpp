#include <iostream>

void printArray(int *array, int length)
{
    for (int index=0; index < length; ++index)
        std::cout << array[index] << ' ';
}

int main(int argc, const char *argv[])
{
    // int array[6] = {6, 5, 4, 3, 2, 1}; // remember, arrays decay into pointers
    int array[] = {6, 5, 4, 3, 2, 1}; // remember, arrays decay into pointers
    printArray(array, 6);   // so array evaluates to a pointer to the first element of the array here, no & needed
}
