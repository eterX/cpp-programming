
# 4.8 - The auto keyword

## Auto prior to C++11

Prior to C++11, the auto keyword was probably the least used keyword in C++. In lesson 4.1a -- Local variables and local scope, you learned that local variables have automatic duration (they’re created when the block they are part of is entered, and destroyed when the block they are part of is exited).

The auto keyword was a way to explicitly specify that a variable should have automatic duration:

```
int main()
{
    auto int foo(5); // explicitly specify that foo should have automatic duration.

    return 0;
}
```

However, since all variables in modern C++ default to automatic duration unless otherwise specified, the auto keyword was entirely obsolete.


## Automatic type deduction in C++11

In C++11, the meaning of the the auto keyword has changed, and it is now a useful addition to your C++ vocabulary.
Consider the following statement:

```
double d = 5.0;
```

If C++ already knows 5.0 is a double literal, why do we have to explicitly specify that d is actually a double? Wouldn’t it be nice if we could tell a variable to just assume the proper type based on the value we’re assigning to it?

Starting with C++11, the auto keyword does just that. When initializing a variable, the auto keyword can be used in place of the variable type to tell the compiler to infer the variable’s type from the assignment’s type. This is called automatic type deduction.

For example:

```
auto d = 5.0; // 5.0 is a double literal, so d will be type double
auto i = 1 + 2; // 1 + 2 evaluates to an integer, so i will be type int
```

This even works with the return values from functions:

```
int add(int x, int y)
{
    return x + y;
}

int main()
{
    auto sum = add(5, 6); // add() returns an int, so sum will be type int
    return 0;
}
```

Note that this only works when initializing a variable upon creation. Variable created without initialization values can not use this feature (as C++ has no context from which to deduce the type).

While using auto in place of fundamental data types only saves a few (if any) keystrokes, in future lessons we will see examples where the types get complex and lengthy. In those cases, using auto can be very nice.

## Automatic type deduction for function in C++14

In C++ 14, the auto keyword was extended to be able to auto-deduce a function's return type. Consider:

```
auto add(int x, int y)
{
    return x + y;
}
```

Since x + y evaluates to an integer, the compiler will deduce this function should have a return type of int.

While this may seem neat, we recommend that this syntax be avoided for functions that return a fixed type. The return type of a function is of great use in helping to document a function. When a specific type isn’t specified, the user may not know what is expected.

(Side note: Interested readers may wonder why using auto when initializing variables is okay, but not recommended for function return types. A good rule of thumb is that auto is okay to use within the boundaries of a statement, because the type being inferred often doesn’t matter, and if it does, the actual type information is generally at hand. However, across statement boundaries, it’s better for documentation and maintenance to make types explicit.)


## Trailing return type syntax in C++

C++11 also added the ability to use a trailing return syntax, where the return type is specified after the rest of the function prototype.

C++11 also added the ability to use a trailing return syntax, where the return type is specified after the rest of the function prototype.

Consider the following function declaration:

```
int add(int x, int y);
```

In C++11, this could be equivalently written as:

```
auto add(int x, int y) -> int;
```

In this case, auto does not perform automatic type deduction -- it is just part of the syntax to use a trailing return type.

Why would you want to use this?

One nice thing is that it makes all of your function names line up:

```
auto add(int x, int y) -> int;
auto divide(double x, double y) -> double;
void printSomething();
auto calculateThis(int x, double d) -> std::string;
```

But it is of more use when combined with some advanced C++ features, such as classes and the decltype keyword. We’ll talk more about the other auto uses when we cover the decltype keyword.

For now, we recommend the continued use of the traditional function return syntax.


## Summary

Starting with C++11, the auto keyword can be used in place of a variable's type when doing an initialization in order to perform automatic type deduction.

## Summary

Starting with C++11, the auto keyword can be used in place of a variable's type when doing an initialization in order to perform automatic type deduction.

Other uses of the auto keyword should generally be avoided except on an as-needed basis.
