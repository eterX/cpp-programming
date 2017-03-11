// Copyright[2016] <Vex Woo>
#include <iostream>
#include <new>  // nothrow

/*

 Dynamic memory is allocated using operator [new].
 [new] is followed by a data type specifier and, if a sequence of more
 than one element is required, the number of these within brackets [].
 It returns a pointer to the beginning of the new block of memory allocated.

 Syntax:

     pointer = new type
     pointer = new type [number_of_elements]

 */

void demo_new() {
    int *pointer;

    pointer = new int[5];
    for (int i=0; i < 5; ++i) {
        pointer[i] = i;
    }

    for (int i=0; i < 5; ++i) {
        std::cout << *(pointer + i) << std::endl;
    }

    delete[] pointer;

    // pointer[i] = i;
    // *(pointer + i) = i;
}


/*

 C++ provides two standard memchanisms to check if the allocation was successfully:


1. One is by handling exceptions. Using this method,
   an exception of type [bad_alloc] is thrown when the allocation fails.

2. The other method is known as [nothrow], and
   what happens when it is used is that when a memory allocation fails,
   instead of throwing a bad_alloc exception or terminating the program,
   the pointer returned by new is a null pointer,
   and the program continues its execution normally.

 */

void demo_nothrow() {
    int *pointer;

    pointer = new (std::nothrow) int[5];

    if (pointer == nullptr) {
      std::cout << "error assigning memory. Take measures" << std::endl;
    }

    delete[] pointer;
}

/*

    delete pointer;
    delete[] pointer;

    1. The first statement releases the memory of a single element allocated using new,
    2. The second one releases the memory allocated for arrays of elements using new and a size in brackets ([]).
 */

int main(int argc, const char *argv[]) {
    demo_new();
    demo_nothrow();

    return 0;
}


/*

  Dynamic memory in C

  C++ integrates the operators [new] and [delete] for allocating dynamic memory.
  But these were not available in the C language; instead, it used a library solution,
  with the functions [malloc, calloc, realloc, free], defined in the header
  [cstdlib] (known as <stdlib.h> in C). The functions are also available in C++ and
  can also be used to allocate and deallocate dynamic memory.
 */
