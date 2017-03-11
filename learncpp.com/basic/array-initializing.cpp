// Copyright [2016] <Vex Woo>

#include <iostream>


void print_array(int array_length, int int_array[]) {
  for (int i = 0; i < array_length; ++i) {
      std::cout << i << std::endl;
  }
}
int main(void) {
    int int_array1[5] = { 0, 1, 2, 3, 4 };
    int int_array2[] = { 0, 1, 2, 3, 4 };
    int int_array3[] { 0, 1, 2, 3, 4 };

    print_array(5, int_array1);
    print_array(2, int_array2);
    print_array(2, int_array3);

    for (auto i : int_array1) {
        std::cout << i << std::endl;
    }
    return 0;
}


// Compile: g++ -std=c++11 array-initializing.cpp
