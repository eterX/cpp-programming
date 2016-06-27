#include <iostream>
#include <vector>

// compile: clang++ -std=c++11 vector_define.cpp

int main()
{
    std::vector<int> array;
    std::vector<int> array2 = {9, 7, 5, 3, 1};   // use initializer list to initialize array
    std::vector<int> array3 {9, 7, 5, 3, 1};     // use uniform initialization to initialize array (C++11 onward)

    std::cout << array2[1] << std::endl;
    std::cout << array3.at(1) << std::endl;
}
