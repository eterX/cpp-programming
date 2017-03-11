# 1.4 - A first look at functions and return values

A **function** is a reusable sequence of statements designed to do a particular job. You already know that every program must have a function named main() (which is the where the program starts execution). However, most programs use many functions.

Often, your program needs to interrupt what it is doing to temporarily do something else. You do this in real life all the time. For example, you might be reading a book when you remember you need to make a phone call. You put a bookmark in your book, make the phone call, and when you are done with the phone call, you return to your book where you left off.

C++ programs work the same way. A program will be executing statements sequentially inside one function when it encounters a function call. A **function call** is an expression that tells the CPU to interrupt the current function and execute another function. The CPU “puts a bookmark” at the current point of execution, and then **calls** (executes) the function named in the function call. When the called function terminates, the CPU goes back to the point it bookmarked, and resumes execution.

The function initiating the function call is called the caller, and the function being called is the callee or called function.

Here is a sample program that shows how new functions are defined and called:

```
//#include <stdafx.h> // Visual Studio users need to uncomment this line
#include <iostream> // for std::cout and std::endl

// Definition of function doPrint()
void doPrint() // doPrint() is the called function in this example
{
    std::cout << "In doPrint()" << std::endl;
}

// Definition of function main()
int main()
{
    std::cout << "Starting main()" << std::endl;
    doPrint(); // Interrupt main() by making a function call to doPrint().  main() is the caller.
    std::cout << "Ending main()" << std::endl;
    return 0;
}
```

This program produces the following output:

```
Starting main()
In doPrint()
Ending main()
```

This program begins execution at the top of function main(), and the first line to be executed prints Starting main(). The second line in main() is a function call to the function doPrint(). At this point, execution of statements in main() is suspended, and the CPU jumps to doPrint(). The first (and only) line in doPrint prints In doPrint(). When doPrint() terminates, the caller (main()) resumes execution where it left off. Consequently, the next statement executed in main prints Ending main().

Note that function calls are made by using the function name, plus a parameter list enclosed in parenthesis (). In this case, since none of our functions use parameters, the list is empty. We’ll talk more about function parameters in the next lesson. If you forget the parameters list, the function will not be called!

## Return values

If you remember, when the main() function finishes executing, it returns an integer value back to the operating system (the caller) by using a return statement.

Functions you write can return a single value to their caller as well. We do this by setting the return type of the function in the function’s definition. The return type is the type declared before the function name.

A return type of void means the function does not return a value. A return type of int means the function returns an integer value to the caller.

```
// void means the function does not return a value to the caller
void returnNothing()
{
    // This function does not return a value so no return statement is needed
}

// int means the function returns an integer value to the caller
int return5()
{
    return 5; // this function returns an integer, so a return statement is needed
}
```

Let’s use these functions in a program:

```
#include <iostream>

// void means the function does not return a value to the caller
void returnNothing()
{
    // This function does not return a value so no return statement is needed
}

// int means the function returns an integer value to the caller
int return5()
{
    return 5; // this function returns an integer, so a return statement is needed
}

int main()
{
    std::cout << return5() << std::endl; // prints 5
    std::cout << return5() + 2 << std::endl; // prints 7

    returnNothing(); // okay: function returnNothing() is called, no value is returned
    return5(); // okay: function return5() is called, return value is discarded

    std::cout << returnNothing(); // This line will not compile.  You'll need to comment it out to continue.

    return 0;
}
```


In the first function call, return5() is executed. The function returns the value of 5 back to the caller, which passes that value to cout.

In the second function call, return5() is executed and returns the value of 5 back to the caller. The expression 5 + 2 is then evaluated to 7. The value of 7 is passed to cout.

In the third function call, returnNothing() is executed. The function does nothing and returns nothing, so control returns to main().

In the fourth function call, return5() is executed. The value 5 is returned to main(), but main() does nothing with the return value so the return value is discarded.

In the fifth function call, returnNothing() returns void. It is not valid to pass void to cout, and the compiler will give you an error when you try to compile this line. You’ll need to comment out this line of code in order to make your code compile.

```
src [master●] g++ function_return_noreturn.cpp
function_return_noreturn.cpp:25:12: error: invalid operands to binary expression ('ostream' (aka 'basic_ostream<char>') and 'void')
        std::cout << returnNothing();  // This line will not compile. You'll need to comment it out to continue.
        ~~~~~~~~~ ^  ~~~~~~~~~~~~~~~
/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/../include/c++/v1/ostream:191:20: note: candidate function not viable: cannot convert argument of incomplete type
      'void' to 'std::__1::basic_ostream<char> &(*)(std::__1::basic_ostream<char> &)'
    basic_ostream& operator<<(basic_ostream& (*__pf)(basic_ostream&));
                   ^
/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/../include/c++/v1/ostream:192:20: note: candidate function not viable: cannot convert argument of incomplete type
      'void' to 'basic_ios<char_type, traits_type> &(*)(basic_ios<char_type, traits_type> &)' (aka 'basic_ios<char, std::__1::char_traits<char> > &(*)(basic_ios<char, std::__1::char_traits<char> > &)')
    basic_ostream& operator<<(basic_ios<char_type, traits_type>&
                   ^
/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/../include/c++/v1/ostream:194:20: note: candidate function not viable: cannot convert argument of incomplete type
      'void' to 'std::__1::ios_base &(*)(std::__1::ios_base &)'
    basic_ostream& operator<<(ios_base& (*__pf)(ios_base&));
                   ^
/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/../include/c++/v1/ostream:195:20: note: candidate function not viable: cannot convert argument of incomplete type
      'void' to 'bool'
    basic_ostream& operator<<(bool __n);
                   ^
/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/../include/c++/v1/ostream:196:20: note: candidate function not viable: cannot convert argument of incomplete type
      'void' to 'short'
    basic_ostream& operator<<(short __n);
                   ^
/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/../include/c++/v1/ostream:197:20: note: candidate function not viable: cannot convert argument of incomplete type
      'void' to 'unsigned short'
    basic_ostream& operator<<(unsigned short __n);
                   ^
/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/../include/c++/v1/ostream:198:20: note: candidate function not viable: cannot convert argument of incomplete type
      'void' to 'int'
    basic_ostream& operator<<(int __n);
                   ^
/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/../include/c++/v1/ostream:199:20: note: candidate function not viable: cannot convert argument of incomplete type
      'void' to 'unsigned int'
    basic_ostream& operator<<(unsigned int __n);
                   ^
/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/../include/c++/v1/ostream:200:20: note: candidate function not viable: cannot convert argument of incomplete type
      'void' to 'long'
    basic_ostream& operator<<(long __n);
                   ^
/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/../include/c++/v1/ostream:201:20: note: candidate function not viable: cannot convert argument of incomplete type
      'void' to 'unsigned long'
    basic_ostream& operator<<(unsigned long __n);
                   ^
/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/../include/c++/v1/ostream:202:20: note: candidate function not viable: cannot convert argument of incomplete type
      'void' to 'long long'
    basic_ostream& operator<<(long long __n);
                   ^
/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/../include/c++/v1/ostream:203:20: note: candidate function not viable: cannot convert argument of incomplete type
      'void' to 'unsigned long long'
    basic_ostream& operator<<(unsigned long long __n);
                   ^
/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/../include/c++/v1/ostream:204:20: note: candidate function not viable: cannot convert argument of incomplete type
      'void' to 'float'
    basic_ostream& operator<<(float __f);
                   ^
/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/../include/c++/v1/ostream:205:20: note: candidate function not viable: cannot convert argument of incomplete type
      'void' to 'double'
    basic_ostream& operator<<(double __f);
                   ^
/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/../include/c++/v1/ostream:206:20: note: candidate function not viable: cannot convert argument of incomplete type
      'void' to 'long double'
    basic_ostream& operator<<(long double __f);
                   ^
/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/../include/c++/v1/ostream:207:20: note: candidate function not viable: cannot convert argument of incomplete type
      'void' to 'const void *'
    basic_ostream& operator<<(const void* __p);
                   ^
/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/../include/c++/v1/ostream:208:20: note: candidate function not viable: cannot convert argument of incomplete type
      'void' to 'basic_streambuf<char_type, traits_type> *' (aka 'basic_streambuf<char, std::__1::char_traits<char> > *')
    basic_ostream& operator<<(basic_streambuf<char_type, traits_type>* __sb);
                   ^
/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/../include/c++/v1/ostream:785:1: note: candidate function
      [with _CharT = char, _Traits = std::__1::char_traits<char>] not viable: cannot convert argument of incomplete type 'void' to 'char'
operator<<(basic_ostream<_CharT, _Traits>& __os, char __cn)
^
/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/../include/c++/v1/ostream:818:1: note: candidate function [with _Traits = std::__1::char_traits<char>] not viable:
      cannot convert argument of incomplete type 'void' to 'char'
operator<<(basic_ostream<char, _Traits>& __os, char __c)
^
/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/../include/c++/v1/ostream:825:1: note: candidate function [with _Traits = std::__1::char_traits<char>] not viable:
      cannot convert argument of incomplete type 'void' to 'signed char'
operator<<(basic_ostream<char, _Traits>& __os, signed char __c)
^
/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/../include/c++/v1/ostream:832:1: note: candidate function [with _Traits = std::__1::char_traits<char>] not viable:
      cannot convert argument of incomplete type 'void' to 'unsigned char'
operator<<(basic_ostream<char, _Traits>& __os, unsigned char __c)
^
/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/../include/c++/v1/ostream:846:1: note: candidate function
      [with _CharT = char, _Traits = std::__1::char_traits<char>] not viable: cannot convert argument of incomplete type 'void' to 'const char *'
operator<<(basic_ostream<_CharT, _Traits>& __os, const char* __strn)
^
/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/../include/c++/v1/ostream:892:1: note: candidate function [with _Traits = std::__1::char_traits<char>] not viable:
      cannot convert argument of incomplete type 'void' to 'const char *'
operator<<(basic_ostream<char, _Traits>& __os, const char* __str)
^
/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/../include/c++/v1/ostream:899:1: note: candidate function [with _Traits = std::__1::char_traits<char>] not viable:
      cannot convert argument of incomplete type 'void' to 'const signed char *'
operator<<(basic_ostream<char, _Traits>& __os, const signed char* __str)
^
/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/../include/c++/v1/ostream:907:1: note: candidate function [with _Traits = std::__1::char_traits<char>] not viable:
      cannot convert argument of incomplete type 'void' to 'const unsigned char *'
operator<<(basic_ostream<char, _Traits>& __os, const unsigned char* __str)
^
/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/../include/c++/v1/ostream:1086:1: note: candidate function
      [with _CharT = char, _Traits = std::__1::char_traits<char>] not viable: cannot convert argument of incomplete type 'void' to 'const std::__1::error_code'
operator<<(basic_ostream<_CharT, _Traits>& __os, const error_code& __ec)
^
/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/../include/c++/v1/ostream:778:1: note: candidate template ignored: deduced conflicting types for parameter '_CharT'
      ('char' vs. 'void')
operator<<(basic_ostream<_CharT, _Traits>& __os, _CharT __c)
^
/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/../include/c++/v1/ostream:839:1: note: candidate template ignored: could not match 'const _CharT *' against 'void'
operator<<(basic_ostream<_CharT, _Traits>& __os, const _CharT* __str)
^
/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/../include/c++/v1/ostream:1077:1: note: candidate template ignored: could not match
      'basic_string<type-parameter-0-0, type-parameter-0-1, type-parameter-0-2>' against 'void'
operator<<(basic_ostream<_CharT, _Traits>& __os,
^
/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/../include/c++/v1/ostream:1094:1: note: candidate template ignored: could not match
      'shared_ptr<type-parameter-0-2>' against 'void'
operator<<(basic_ostream<_CharT, _Traits>& __os, shared_ptr<_Yp> const& __p)
^
/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/../include/c++/v1/ostream:1101:1: note: candidate template ignored: could not match 'bitset<_Size>' against 'void'
operator<<(basic_ostream<_CharT, _Traits>& __os, const bitset<_Size>& __x)
^
1 error generated.

```

One commonly asked question is, “Can my function return multiple values using a return statement?”. The answer is no. Functions can only return a single value using a return statement. However, there are ways to work around the issue, which we will discuss when we get into the in-depth section on functions.


## Returning to main

You now have the conceptual tools to understand how the main() function actually works. When the program is executed, the operating system makes a function call to main(). Execution then jumps to the top of main. The statements in main are executed sequentially. Finally, main returns a integer value (usually 0) back to the operating system. This is why main is defined as int main().

Why return a value back to the operating system? This value is called a status code, and it tells the operating system (and any other programs that called yours) whether your program executed successfully or not. By consensus, a return value of 0 means success, and a positive return value means failure.

Note that the C++ standard explicitly specifies that main() must return an int. However, if you do not provide a return statement in main, the compiler will return 0 on your behalf. However, it is generally a good idea to explicitly return a value from main, both to show your intent, and for consistency with other functions (which will not let you omit the return value).

For now, you should also define your main() function at the bottom of your code file. We’ll talk about why shortly, in section 1.7 -- Forward Declarations.


## Reusing functions

The same function can be called multiple times, which is useful if you need to do something more than once.

```
//#include <stdafx.h> // Visual Studio users need to uncomment this line
#include <iostream>

// getValueFromUser will read a value in from the user, and return it to the caller
int getValueFromUser()
{
    std::cout << "Enter an integer: ";
    int a;
    std::cin >> a;
    return a;
}

int main()
{
    int x = getValueFromUser(); // first call to getValueFromUser
    int y = getValueFromUser(); // second call to getValueFromUser

    std::cout << x << " + " << y << " = " << x + y << std::endl;

    return 0;
}

```

This program produces the following output:

```
Enter an integer: 5
Enter an integer: 7
5 + 7 = 12
```

In this case, main() is interrupted 2 times, once for each call to getValueFromUser(). Note that in both cases, the value read into variable a is passed back to main() via the function’s return value and then assigned to variable x or y!

Note that main() isn’t the only function that can call other functions. Any function can call another function!

```
//#include <stdafx.h> // Visual Studio users need to uncomment this line
#include <iostream>

void printA()
{
    std::cout << "A" << std::endl;
}

void printB()
{
    std::cout << "B" << std::endl;
}

// function printAB() calls both printA() and printB()
void printAB()
{
    printA();
    printB();
}

// Definition of main()
int main()
{
    std::cout << "Starting main()" << std::endl;
    printAB();
    std::cout << "Ending main()" << std::endl;
    return 0;
}
```

This program produces the following output:


```
Starting main()
A
B
Ending main()
```

## Nested functions

Functions can not be defined inside other functions (called nesting) in C++. The following program is not legal:

```
#include <iostream>

int main()
{
    int foo() // this function is nested inside main(), which is illegal.
    {
        std::cout << "foo!";
        return 0;
    }

    foo();
    return 0;
}
```

The proper way to write the above program is:

```
#include <iostream>

int foo() // no longer inside of main()
{
    std::cout << "foo!";
    return 0;
}

int main()
{
    foo();
    return 0;
}
```
