#include <iostream>


class IntArray
{
private:
  int m_array[10];

public:
  void setValue(int index, int value)
  {
      if (index < 0 || index >= 10)
      {  return; }

      m_array[index] = value;
  }

  int getValue(int index)
  {
      if (index < 0 || index >= 10)
      { return 255;}

      return m_array[index];
  }
};


int main(int argc, const char *argv[])
{
    IntArray array;
    array.setValue(0, 1);
    array.setValue(1, 2);
    array.setValue(2, 3);

    std::cout << array.getValue(0) << std::endl;
    std::cout << array.getValue(1) << std::endl;
    std::cout << array.getValue(2) << std::endl;

    return 0;
}
