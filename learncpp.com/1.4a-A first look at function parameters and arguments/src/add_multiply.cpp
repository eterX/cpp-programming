#include <iostream>

int add(int x, int y)
{
    return x + y;
}

int multiply(int z, int w)
{
    return z * w;
}

int main(int argc, const char * argv[])
{
    using namespace std;
	cout << add(4, 5) << endl;  // within add(), x=4, y=5, so x+y=9
	cout << multiply(2, 3) << endl;  // within multiply(), z=2, w=3, so z*w=6

	// We can pass the value of expressions
	cout << add(1 + 2, 3 * 4) << endl;

	// We can pass the value of variables
	int a = 5;
	cout << add(a, a) << endl;  // evaluates ( 5 + 5)
	cout << add(1, multiply(2, 3)) << endl;  // evaluates 1 + (2 * 3)
	cout << add(1, add(2, 3)) << endl; // evaluates 1 + (2 + 3)

	return 0;
}
