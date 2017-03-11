#include <iostream>

int main(int argc, const char *argv[])
{
  int x = 5;
  x = x - 2;
  std::cout << x << std::endl;

  int y = x;
  std::cout << y << std::endl;

  std::cout << x + y << std::endl;
  std::cout << x << std::endl;

  int z;
  std::cout << z << std::endl;
}
