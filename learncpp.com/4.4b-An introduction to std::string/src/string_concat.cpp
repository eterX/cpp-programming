#include <string>
#include <iostream>

int main()
{
     std::string a("45");
	 std::string b("11");

	 std::cout << a + b << "\n";  // a and b will be appended, not added
	 a += " volts";
	 std::cout << a;

	 return 0;
}
