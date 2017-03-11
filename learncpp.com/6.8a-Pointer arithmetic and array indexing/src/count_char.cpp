#include <iostream>

int count(char *char_array, int array_size)
{
	int num(0);

	for (char *ptr = char_array;  ptr < char_array + array_size; ++ptr)
	{
		switch (*ptr)
		{
			case 'a':
				num++;
		}
	}
	return num;
}

int main(int argc, const char *argv[])
{
    // const int array_size = 12;
	char name[] = "Mollieaaaaa";
	int array_size = sizeof(name);
    
	std::cout << name << " length is " << array_size << "\n";
    std::cout << count(name, array_size) << "\n";
	return 0;
}
