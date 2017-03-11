// Copyright [2016] <Vex Woo>

#include <iostream>


int main(int argc, const char *argv[]) {
    char char_array1[] = "Hello";
    char char_array2[] = {'H', 'e', 'l', 'l', 'o', '\0'};
    /* The above declares an array of 6 elements of type char initialized
     with the characters that from the word "Hello" plus a null character '\0'
     at the end.

     '\0' is a must.
     */

    std::cout << char_array1 << std::endl;
    std::cout << char_array2 << std::endl;

    return 0;
}
