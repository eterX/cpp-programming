
# 6.16 - An introduction to std::vector

In the previous lesson, we introduced std::array, which provides the functionality of C++'s built-in fixed arrays in a safer and more usable form.

Analogously, the C++ standard library provides functionality that makes working with dynamic arrays safer and easier. This functionality is named std::vector.

Unlike std::array, which closely follows the basic functionality of fixed arrays, std::vector comes with some additional tricks up its sleeves. These help make std::vector one of the most useful andn versatile tools to have in your C++ toolkit.

## An introduction to std::vector

Introduced in C++ 03, std::vector provides dynamic array functionality that handles its own memory management. This means you can create arrays that have their length set at runtime, without having to explicitly allocate and deallocate memory using new and delete. std::vector lives in the <vector> header.

Declaring a std::vector is simple:

```
#include <vector>

std::vector<int> array;
std::vector<int> array2 = {9, 7, 5, 3, 1};  // use initializer list to initialize array
std::vector<int> array3 {9, 7, 5, 3, 1};    // use uniforma initialization to initialize array (C++11 onward)
```

Note that in both the uninitialized and initialize case, you do not need to include the array size at compile time. This is because std::vector will dynamically allocate memory for its contents as needed.

Just like std::array, accessing array elements can be done via the [] operator (which does no bounds checking) or the at() function (which does bounds checking):

```
array[2] = 2;
array.at(3) = 3;
```

As of C++11, you can also assign values to a std::vector using an initializer-list:

```
array = {0, 1, 2, 3, 4};  // okay, array size is now 5.
array = {9, 8, 7};        // okay, array size is now 3.
```

## Self-cleanup prevents memory leaks

When a vector variable goes out of scope, it automatically deallocates the memory it controls (if necessary). This is not only handy (as you don't have to do it yourself), it also helps prevent memory leaks. Consider the following snippet:

```
void doSomething(bool earlyExit)
{
    int *array = new int[5]{9, 7, 5, 3, 1};
    if (earlyExit)
        return 0;

    // do stuff here
    delete[] array;  // never called
}
```

If earlyExit is set to true, array will never be deallocated, and the memory will be leaked.

However, if array is a vector, this won't happen, because the memory will be deallocated as soon as array goes out of scope (regardless of whether the function exits early or not).

## Vectors remember their size

Unlike built-in dynamic arrays, which don't know the size of the array they are pointing to, std::vector keeps track of its size. We can ask for the vector's size via the size() function:

```
#include <vector>
#include <iostream>

int main()
{
    std::vector<int> array {9, 7, 5, 3, 1};
    std::cout << "The size is: " << array.size() << '\n';
    return 0;
}
```

The above example prints:

The size is: 5


## Resizing an array

Resizing a built-in dynamically allocated array is complicated. Resizing a std::vector is as simple as calling the resize() function:

```
#include <vector>
#include <iostream>

int main()
{
    std::vector<int> array {0, 1, 2};
    array.resize(5);  // set size to 5

    std::cout << "The size is: " << array.size() << '\n';

    for (auto const &element: array)
        std::cout << element << ' ';

    return 0;
}
```

This prints:

The size is: 5
0 1 2 0 0

There are two things to note here. First, when we resized the array, the existing element values were preserved! Second, new elements are initialized to the default value for the type (which is 0 for integers).

Vectors may be resized to be smaller:

```
#include <vector>
#include <iostream>

int main()
{
    std::vector<int> array {0, 1, 2, 3, 4};
    array.resize(3);  // set size to 3

    std::cout << "The size is: " << array.size() << '\n';
    for (auto const &element: array)
        std::cout << element << ' ';

    return 0;
}
```

This prints:

The size is: 3
0 1 2


## Compacting bools

std::vector has another cool trick up its sleeves. There is a special implementation for std::vector of type bool that will compact 8 booleans into a byte! This happen behind the scenes, and is largely transparent to you as a programmer.

```
#include <vector>
#include <iostream>

int main()
{
    std::vector<bool> array {true, false, false, true, true};
    for (auto const &element: array)
        std::cout << element << ' ';

    return 0;
}
```

This prints:

The size is: 5

1 0 0 1 1

## More to come

Note that this is an introduction acticle intended to introduce the basics of std::vector. In a future article, we'll cover some additional capabilities of std::vector, including the difference between a vector's size and capacity, and take a deeper look into how std::vector handles memory allocation.

## Conslusion

Because variables of type std::vector handle their own memory management (which helps prevent memory leaks), remember their size, and can be easily resized, we highly recommend using std::vector in almost all cases where dynamic arrays are needed.
