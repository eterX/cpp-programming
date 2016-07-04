
# 7.3 - Passing arguments by reference

While pass by value is suitable in many cases, it has a couple of limitations. First, when passing a large struct or class to a function, pass by value will make a copy of the argument into the function parameter. In many cases, this is a needless preformance hit, as the original argument would have sufficed. Second, when passing arguments by value, the only way to return a value back to the caller is via the function's return value. While this is often suitable, there are cases where it would be more clear and efficient to have the function modify the argument passed in. Pass by reference solves both of these issues.

## Pass by reference

To pass a variable by reference, we simply declare the function parameters as references rather than as normal variables:

```
void addOne(int &y)  // y is a reference variable
{
    y = y + 1;
}
```

When the function is called, y will become a reference to the argument. Since a reference to a variable is treated exactly the same as the variable itself, any changes made to the reference are passed through to the argument!

The following example shows this in action:

```
void foo(int &value)
{
    value = 6;
}

int main()
{
    int value = 5;

    cout << "value = " << value << '\n';
    foo(value);
    cout << "value = " << value << '\n';
    return 0;
}
```

The program is the same as the one we used for the pass by value example, except foo's parameter is now a reference instead of a normal variable. When we call foo(x), y becomes a reference to x. This snippet produces the output:

value = 5
value = 6

Note that the value of argument x was changed by the function.

## Returning multiple values via out parameters

Sometimes we need a function to return multiple values. However, functions can only have one return value. One way to return multiple values is using reference parameters:

```
#include <iostream>
#include <math.h>    // for sin() and cos()

void getSinCos(double degrees, double &sinOut, double &cosOut)
{
    // sin() and cos() take radians, not degrees, so we need to convert
    static const double pi = 3.14159265358979323846; // the value of pi
    double radians = degrees * pi / 180.0;
    sinOut = sin(radians);
    cosOut = cos(radians);
}

int main()
{
    double sin(0.0);
    double cos(0.0);

    // getSinCos will return the sin and cos in variables sin and cos
    getSinCos(30.0, sin, cos);

    std::cout << "The sin is " << sin << '\n';
    std::cout << "The cos is " << cos << '\n';
    return 0;
}
```

This function takes one parameter (by value) as input, and "return" two parameters (by reference) as output. Parameters that are only used for returning values back to the caller are called **out parameters**. We've named  these out parameters with the suffix “out” to denote that they’re out parameters. This helps remind the caller that the initial value passed to these parameters doesn’t matter, and that we should expect them to be rewritten.

## Pass by const reference

As mentioned in the introduction, one of the major disadvantages of pass by value is that all arguments passed by value are copied into the function parameters. When the arguments are large structs or classes, this can take a lot of time. References provide a way to avoid this penalty. When an argument is passed by reference, a reference is created to the actual argument (which takes minimal time) and no copying of values takes place. This allows us to pass large structs and classes with a minimum performance penalty.

However, this also opens us up to potential trouble. References allow the function to change the value of the argument, which is undesirable when we want an argument be read-only. If we know that a function should not change the value of an argument, but don’t want to pass by value, the best solution is to pass by const reference.

You already know that a const reference is a reference that does not allow the variable being referenced to be changed through the reference. Consequently, if we use a const reference as a parameter, we guarantee to the caller that the function will not change the argument!

The following function will produce a compiler error:

```
void foo(const int &x) // x is a const reference
{
    x = 6;  // compile error: a const reference cannot have its value changed!
}
```

Using const is useful for several reasons:

 - It enlists the compilers help in ensuring values that shouldn’t be changed aren’t changed (the compiler will throw an error if you try, like in the above example).
 - It tells the programmer that the function won't change the value of the argument. This can help with debugging.
 - You can't pass a const argument to a non-const reference parameter. Using const parameters ensures you can pass both non-const and const arguments to the function.

 Rule: When passing an argument by reference, always use a const references unless you need to change the value of the argument

## Summary

Advantages of passing by reference:

 - It allows a function to change the value of the argument, which is sometimes useful. Otherwise, const references can be used to guarantee the function won't change the argument.
 - Because a copy of the argument is not made, it is fast, even when used with large structs or classes.
 - References can be used to return multiple values from a function.
 - References must be initialized, so there’s no worry about null values.

Disadvantages of passing by reference:

 - Because a non-const reference cannot be made to an rvalue (e.g. a literal or an expression), reference arguments must be normal variables.
 - It can be hard to tell whether a parameter passed by non-const reference is meant to be input, output, or both. Judicious use of const and a naming suffix for out variables can help.
 - It’s impossible to tell from the function call whether the argument may change. An argument passed by value and passed by reference looks the same. We can only tell whether an argument is passed by value or reference by looking at the function declaration. This can lead to situations where the programmer does not realize a function will change the value of the argument.

When to use pass by reference:

 - When passing structs or classes (use const if read-only).
 - When you need the function to modify an argument.

When not to use pass by reference:

 - When passing fundamental types (use pass by value).
