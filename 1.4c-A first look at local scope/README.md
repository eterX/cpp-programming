# 1.4c - A first look at local scope

You already saw in the lesson **1.3 -- a first look at variables** that when the CPU executes a statement like int x;, this causes the variable to be instantiated (created).

The natural follow-up question is, “so when is an instantiated variable destroyed?”

A variable’s **scope** determines who can see and use the variable during the time it is instantiated. Both function parameters and variables declared inside the function body have **local scope**. That is, those variables can only be seen and used within the function that declares them. Local variables are created at the top of the function, and destroyed at the end of the function.

Consider the following program:

```
#include <iostream>

int add(int x, int y) // x and y are created here
{
    // x and y are visible/usable within this function only
    return x + y;
} // x and y are destroyed here

int main() // a and b are created here
{
    int a = 5; // a is initialized here
    int b = 6; // b is initialized here
    // a and b are usable within this function only
    std::cout << add(a, b) << std::endl; // calls function add() with x=a and y=b
    return 0;
} // a and b are destroyed here
```

In function add(), parameters x and y are created when the function is called, can only be seen/used within function add(), and are destroyed at the end of the add() function.
Variable a and b are created within function main(), can only be seen/used within function main(), and are destroyed at the end of main().

To enhance your understanding, let’s trace through this program in a little more detail. The following happens, in order:

- main() is executed
- main’s variable a is created and given value 5
- main’s variable b is created and given value 6
- function add() is called with values 5 and 6 for parameters
- add’s variable x is created and given value 5
- add’s variable y is created and given value 6
- operator + adds 5 and 6 to produce the value 11
- add returns the value 11 to the caller (main)
- add’s x and y are destroyed
- main prints 11 to the console
- main returns 0 to the operating system
- main’s a and b are destroyed

And we're done.

Note that if function add() were to be called twice, parameters x and y would be created and destroyed twice -- once for each call. In a program with lots of functions, variables are created and destroyed often.

## Local scope prevents naming collisions

In the above example, it’s easy to see that variables a and b are different variables from x and y.

Now consider the following program:

```
#include <iostream>

int add(int x, int y) // add's x is created here
{
    return x + y;
} // add's x is destroyed here

int main() // main's x is created here
{
    int x = 5;
    int y = 6;
    std::cout << add(x, y) << std::endl; // the value from main's x is copied into add's x
    return 0;
} // main's x is destroyed here
```

In this example, all we’ve done is change the names of variables a and b inside of main() to x and y. This program still runs fine, even though both main() and add() now have variables named x and y. Why doesn’t this cause a naming conflict? Because x and y in main() have local scope, add() can’t see them. Neither add() nor main() know that the other has variables with the same names!

This helps prevent naming conflicts, because each function doesn’t need to know or care what other functions name their variables. This also prevents functions from being able to inadvertently (or intentionally) change the values of variables inside other functions.

We’ll talk more about local scope, and other kinds of scope, in chapter 4.

Rule: Names used for function parameters or variables declared in a function body are only visible within the function that declares them.

## Quiz

1) What does the following program print ?

```
#include <iostream>

void doIt(int x)
{
    x = 3;
    int y = 4;
    std::cout << "doIt: x = " << x << " y = " << y << std::endl;
}

int main()
{
    int x = 1;
    int y = 2;
    std::cout << "main: x = " << x << " y = " << y << std::endl;
    doIt(x);
    std::cout << "main: x = " << x << " y = " << y << std::endl;
    return 0;
}
```
