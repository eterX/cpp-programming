# 2.3 - Variable sizes and the sizeof operator

As you learned in the lesson 2.1 -- basic addressing and variable definition, memory on modern machines is typically organized into byte-sized units, with each unit having a unique address. Up to this point, it has been useful to think of memory as a bunch of cubbyholes or mailboxes where we can put and retrieve information, and variables as names for accessing those cubbyholes or mailboxes.

However, this analogy is not quite correct in one regard -- most variables actually take up more than 1 byte of memory. Consequently, a single variable may use 2, 4, or even 8 consecutive memory addresses. The amount of memory that a variable uses is based on its data type. Fortunately, because we typically access memory through variable names and not memory addresses, the compiler is largely able to hide the details of working with different

There are several reasons it is useful to know how much memory a variable takes up.

First, the more memory a variable takes up, the more information it can hold. Because each bit can only hold a 0 or a 1, we say that bit can hold 2 possible values.

2 bits can hold 4 possible values:

| ** bit 0 ** | ** bit 1 ** |
|-:-|-:-|
| 0 | 0 |
| 0 | 1 |
| 1 | 0 |
| 1 | 1 |


3 bits can hold 8 possible values:

| ** bit 0 ** | ** bit 1 ** | ** bit 2 ** |
|-:-|-:-|-:-|
| 0 | 0 | 0 |
| 0 | 0 | 1 |
| 0 | 1 | 0 |
| 0 | 1 | 1 |
| 1 | 0 | 0 |
| 1 | 0 | 1 |
| 1 | 1 | 0 |
| 1 | 1 | 1 |

To generalize, a variable with n bits can hold 2n (2 to the power of n, also commonly written 2^n) possible values. Because a byte is 8 bits, a byte can store 28 (256) possible values.

The size of the variable puts a limit on the amount of information it can store -- variables that utilize more bytes can hold a wider range of values. We will address this issue further when we get into the different types of variables.

Second, computers have a finite amount of free memory. Every time we declare a variable, a small portion of that free memory is used as long as the variable is in existence. Because modern computers have a lot of memory, this often isn’t a problem, especially if only declaring a few variables. However, for programs that need a large amount of variables (eg. 100,000), the difference between using 1 byte and 8 byte variables can be significant.

However, you may find on your system that the variables are larger (particularly for int, which is often 4 bytes).

## The size of C++ basic data types

The obvious next question is “how much memory do variables of different data types take?”. You may be surprised to find that the size of a given data type is dependent on the compiler and/or the computer architecture!

C++ guarantees that the basic data types will have a minimum size:


| **Category** | **Type** | **Mininum Size** | **Note** |
|-:-|-:-|-:-|-:-|
| boolean | bool | 1 byte | |
| character | char | 1 byte | May be signed or unsigned |
| | wchar_t | 1 byte | |
| | char16_t | 2 bytes | C++ 11 type |
| | char32_t | 4 bytes | C++ 11 type |
| integer | short | 2 bytes | |
| | int | 2 bytes | |
| | long | 4 bytes | |
| | long long | 8 bytes | C99/C++11 type |
| floating point | float | 4 bytes | |
| | double | 8 bytes | |
| | long double | 8 bytes | |


However, the actual size of the variables may be different on your machine. In order to determine the size of data types on a particular machine, C++ provides an operator named sizeof. The sizeof operator is a unary operator that takes either a type or a variable, and returns its size in bytes. You can compile and run the following program to find out how large some of your data types are:

```
#include <iostream>

int main()
{
    using namespace std;
    cout << "bool:\t\t" << sizeof(bool) << " bytes" << endl;
    cout << "char:\t\t" << sizeof(char) << " bytes" << endl;
    cout << "wchar_t:\t" << sizeof(wchar_t) << " bytes" << endl;
    cout << "char16_t:\t" << sizeof(char16_t) << " bytes" << endl; // C++11, may not be supported by your compiler
    cout << "char32_t:\t" << sizeof(char32_t) << " bytes" << endl; // C++11, may not be supported by your compiler
    cout << "short:\t\t" << sizeof(short) << " bytes" << endl;
    cout << "int:\t\t" << sizeof(int) << " bytes" << endl;
    cout << "long:\t\t" << sizeof(long) << " bytes" << endl;
    cout << "long long:\t" << sizeof(long long) << " bytes" << endl; // C++11, may not be supported by your compiler
    cout << "float:\t\t" << sizeof(float) << " bytes" << endl;
    cout << "double:\t\t" << sizeof(double) << " bytes" << endl;
    cout << "long double:\t" << sizeof(long double) << " bytes" << endl;
    return 0;
}
```

Here is the output from the author’s x64 machine (in 2015), using Visual Studio 2013:

```
bool:           1 bytes
char:           1 bytes
wchar_t:        2 bytes
char16_t:       2 bytes
char32_t:       4 bytes
short:          2 bytes
int:            4 bytes
long:           4 bytes
long long:      8 bytes
float:          4 bytes
double:         8 bytes
long double:    8 bytes
```

Your results may vary if you are using a different type of machine, or a different compiler. Note that you can not take the sizeof the void type, since it has no size (doing so will cause a compile error).

If you’re wondering what ‘\t’ is in the above program, it’s a special symbol that inserts a tab (in the example, we’re using it to align the output columns). We will cover ‘\t’ and other special symbols when we talk about the char data type.

Interestingly, the sizeof operator is one of only three operators in C++ that are a word instead of a symbol. The other two are new and delete.

You can also use the sizeof operator on a variable name:

```
int x;
cout << "x is " << sizeof(x) << " bytes"<<endl;
```

x is 4 bytes
We’ll discuss the size of different types in the upcoming lessons, as well as a summary table at the end.
