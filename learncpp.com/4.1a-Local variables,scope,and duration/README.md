
# 4.1a - Local variables, scope, and duration

The following section builds on section 1.4b -- **a first look at local scope**.

When discussing variables, it’s useful to separate out the concepts of scope and duration. A variable’s **scope** determines where a variable is accessible. A variable’s duration determines where it is created and destroyed. The two concepts are often linked.

Variables defined inside a block are called **local variables**. Local variables have **automatic duration**, which means they are created when the block they are part of is entered, and destroyed when the block they are part of is exited. Local variables have block scope (also called **local scope**), which means they are visible only within the block that they are defined in.

Consider this simple function:

```
int main()
{ // start main block, i and d created here

    int i(5); // i initialized here
    double d(4.0); // d initialized here

    return 0;

} // i and d destroyed here
```

Because i and d were defined inside the block that defines the main function, they are both destroyed when main() is finished executing.

Variables defined inside nested blocks are destroyed as soon as the inner block ends:

```
int main() // outer block, n created here
{
    int n(5); // n initialized here

    { // begin nested block, d created here
        double d(4.0); // d initialized here
    } // d destroyed here

    // d can not be used here because it was already destroyed!

    return 0;
} // n destroyed here
```

Variables defined inside a block can only be seen within that block. Because each function has its own block, variables in one function can not be seen from another function:

```
void someFunction()
{
    int value(4); // value defined here

    // value can be seen and used here

} // value destroyed here

int main()
{
    // value can not be seen or used inside this function.

    someFunction();

    // value still can not be seen or used inside this function.

    return 0;
}
```

This means functions can have variables or parameters with the same names as other functions. This is a good thing, because it means we don’t have to worry about naming collisions between two independent functions. In the following example, both functions have variables named x and y. These variables in each function are unaware of the existence of other variables with the same name in other functions.

```
#include <iostream>

// add's x can only be seen/used within function add()
int add(int x, int y) // add's x is created here
{
    return x + y;
} // add's x is destroyed here

// main's x can only be seen/used within function main()
int main() // main's x is created here
{
    int x = 5;
    int y = 6;
    std::cout << add(x, y) << std::endl; // the value from main's x is copied into add's x
    return 0;
} // main's x is destroyed here
```

Nested blocks are considered part of the outer block in which they are defined. Consequently, variables defined in the outer block can be seen inside a nested block:

```
int main()
{ // start outer block

    int x(5);

    { // start nested block
        int y(7);
        // we can see both x and y from here
        std::cout << x << " + " << y << " = " << x + y;
    } // y destroyed here

    // y can not be used here because it was already destroyed!

    return 0;
} // x is destroyed here
```

Note that variables inside nested blocks can have the same name as variable inside outer blocks. When this happens, the nested variable “hides” the outer variable. This is called name hiding or shadowing.

```
#include <iostream>

int main()
{ // outer block
    int apples(5);

    if (apples >= 5)
    { // nested block
        int apples(10); // hides previous variable named apples

        // apples now refers to the nested block apples
        // the outer block apples is hidden

        std::cout << apples;
    } // nested block apples destroyed

    // apples now refers to the outer block apples
    std::cout << apples;

    return 0;
} // outer block apples destroyed
```

If you run this program, it prints:

10
5

This is generally something that should be avoided, as it is quite confusing!

Variables should be defined in the most limited scope in which they are used. For example, if a variable is only used within a nested block, it should be defined inside that nested block:

```
#include <iostream>

int main()
{
    // do not define y here
    {
        // y is only used inside this block, so define it here
        int y(5);
        cout << y;
    }
    // otherwise y could still be used here

    return 0;
}
```

By limiting the scope of a variable, you reduce the complexity of the program because the number of active variables is reduced. Further, it makes it easier to see where variables are used. A variable defined inside a block can only be used within that block (or nested sub-blocks). This can make the program easier to understand.

Rule: Define variables in the smallest scope that they are used.
Rule: Avoid using nested variables with the same names as variables in an outer block.

## Function parameters

Although function parameters are not defined inside the block belonging to the function, in most cases, they can be considered to have block scope.

```
int max(int x, int y) // x and y defined here
{
    // assign the greater of x or y to max
    int max = (x > y) ? x : y; // max defined here
    return max;
} // x, y, and max all die here
```

The exception case is for function-level exceptions, which we’ll cover in a future section.

## Summary

Variables defined inside blocks are called local variables. These variables can only be accessed inside the block in which they are defined (including nested blocks), and they are destroyed as soon as the block ends.

Define variables in the smallest scope that they are used. If a variable is only used within a nested block, define it within the nested block.

## Quiz

1) Write a program that asks the user to enter two integers, the second larger than the first. If the user entered a smaller integer for the second integer, use a block and a temporary variable to swap the smaller and larger values. Then print the value of the smaller and larger variables. Add comments to your code indicating where each variable dies.

The program output should match the following:

    Enter an integer: 4
    Enter a larger integer: 2
    Swapping the values
    The smaller value is 2
    The larger value is 4

2) What’s the difference between a variable’s scope and duration? By default, what kind of scope and duration do local variables have (and what do those mean)?
