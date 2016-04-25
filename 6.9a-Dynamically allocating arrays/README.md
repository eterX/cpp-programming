
# 6.9a - Dynamically allocating arrays

In addition to dynamically allocating single values, we can also dynamically allocate arrays of variables. Unlike a fixed array, where the array size must be fixed at compile time, dynamically allocating an array allows us to choose an array length at runtime.

To allocate an array dynamically, we use the array form of new and delete (often called new[] and delete[]):

```
#include <iostream>

int main()
{
    std::cout << "Enter a positive integer: ";
    int size;
    std::cin >> size;

    int *array = new int[size]; // use array new.  Note that size does not need to be constant!

    std::cout << "I just allocated an array of size " << size << '\n';

    array[0] = 5; // set element 0 to value 5

    delete[] array; // use array delete to deallocate array
    array = 0; // use nullptr instead of 0 in C++11

    return 0;
}
```

Because we are allocating an array, C++ knows that it should use the array version of new instead of the scalar version of new. Essentially, the new[] operator is called, even though the [] isn’t placed next to the new keyword.

Note that because this memory is allocated from a different place than the memory used for fixed arrays, the size of the array can be quite large. You can run the program above and allocate an array of length 1,000,000 (or probably even 100,000,000) without issue. Try it! Because of this, programs that need to allocate a lot of memory in C++ typically do so dynamically.


## Dynamically deleting arrays

When deleting a dynamically allocated array, we have to use the array version of delete, which is delete[]. This tells the CPU that it needs to clean up multiple variables instead of a single variable. One of the most common mistakes that new programmers make when dealing with dynamic memory allocation is to use delete instead of delete[] when deleting a dynamically allocated array. Using the scalar version of delete on an array can cause data corruption, memory leaks, or other problems.

## Dynamic arrays are almost identical to fixed arrays

In lesson 6.8 -- Pointers and arrays, you learned that a fixed arrays holds the memory address of the first array element. You also learned that a fixed array can decay into a pointers that points to the first element of the array. In this decayed form, the size of the fixed array is not available, but otherwise there is little difference.

A dynamic array starts its life as a pointer that points to the first element of the array. Consequently, it does not know the size of the array it points to. But otherwise, it works identically to a decayed fixed array, except that the program itself is responsible for deallocating it.

Note that because a dynamic array does not know the size of the array it points to, a dynamic array won’t work inside a for each loop. Pity, that.


## Initializing dynamically allocated arrays

If you want to initialize a dynamically allocated array to 0, the syntax is quite simple:

```
int *array = new int[size]();
```

Prior to C++11, there’s no easy way to initialize a dynamic array to a non-zero value (initializer lists only work for fixed arrays). This means you have to loop through the array and assign element explicitly.

```
int *array = new int[5];
array[0] = 9;
array[1] = 7;
array[2] = 5;
array[3] = 3;
array[4] = 1;
```

Super annoying!

However, starting with C++11, it’s now possible to initialize dynamic arrays using initializer lists!

```
int fixedArray[5] = { 9, 7, 5, 3, 1 }; // initialize a fixed array in C++03
int *array = new int[5] { 9, 7, 5, 3, 1 }; // initialize a dynamic array in C++11
```

Note that this syntax has no operator= between the array size and the initializer list.

For consistency, in C++11, fixed arrays can also be initialized using this operator= free syntax:

```
int fixedArray[5] { 9, 7, 5, 3, 1 }; // initialize a fixed array in C++11
char fixedArray[14] { "Hello, world!" }; // initialize a fixed array in C++11
```

One caveat, in C++11 you can not initialize a dynamically allocated char array from a C-style string:

```
char *array = new char[14] { "Hello, world!" }; // doesn't work in C++11, works in C++14
```

However, this was fixed in C++14.


## Resizing arrays

Dynamically allocating an array allows you to set the array size at the time of allocation. However, C++ does not provide a built-in way to resize an array that has already been allocated. It is possible to work around this limitation by dynamically allocating a new array, copying the elements over, and deleting the old array. However, this is error prone, especially when the element type is a class (which have special rules governing how they are created).

Consequently, we recommend avoiding doing this yourself.

Fortunately, if you need this capability, C++ provides a resizable array as part of the standard library called std::vector. We’ll introduce std::vector shortly.


## Quiz

1) Write a program that:
* Asks the user how many names they wish to enter.
* Asks the user to enter each name.
* Calls a function to sort the names (modify the selection sort code from lesson 6.4 -- Sorting an array using selection sort)
* Prints the sorted list of names.

Hint: Use a dynamic array of std::string to hold the names.
Hint: std::string supports comparing strings via the comparison operators < and >

Your output should match this:

How many names would you like to enter? 5
Enter name #1: Jason
Enter name #2: Mark
Enter name #3: Alex
Enter name #4: Chris
Enter name #5: John

Here is your sorted list:
Name #1: Alex
Name #2: Chris
Name #3: Jason
Name #4: John
Name #5: Mark
