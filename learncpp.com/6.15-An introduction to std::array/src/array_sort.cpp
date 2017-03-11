#include <iostream>
#include <array>


int
main(int argc, const char *argv[])
{
    std::array<int, 5> myarray = {3, 2, 1, 5, 4};
    std::sort(myarray.begin(), myarray.end());   // sort the array forwards

    for (const auto &element : myarray)
        std::cout << element << ' ';

    return 0;
}
