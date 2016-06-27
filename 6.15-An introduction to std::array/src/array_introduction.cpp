#include <array>
#include <iostream>


int
main (int argc, const char *argv[])
{
  std::array<int, 5> myarray = {9, 7, 5, 3, 1};  // declare an integer array
  std::array<double, 5> myarray1 = {9.0, 7.2, 5.0, 3.0, 1.0};

  std::cout << myarray[1] << std::endl;
  std::cout << myarray1.at(1) << std::endl;
}
