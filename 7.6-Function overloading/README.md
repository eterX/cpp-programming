# 7.6 - Function overloading

**Function overloadig** is a feature of C++ that allows us to create multiple functions with the same name, so long as they have different parameters. Consider th following function:

```
int add(int x, int y)
{
    return x + y;
}
```

This trivial function adds two integers. However, what if we also need to add two floating point numbers? This function is not at all suitable, as any floating point parameters would be converted to integers, causing the floating point arguments to lose their fractional values.

One way to work around this issue is to define multiple functions with slightly different names:

```
int addInteger(int x, int y)
{
    return x + y;
}

double addDouble(double x, double y)
{
    return x + y;
}
```

However, for best effect, this requires that you define a consistent naming standard, remember the name of all the different flavors of the function, and call the correct one.

Function overloading provides a better solution. Using function overloading, we can simply declare another add() function that takes double parameters:

```
double add(double x, double y)
{
    return x + y;
}
```

We now have two version of add():

```
int add(int x, int y); // integer version
double add(double x, double y); // floating point version
```

Which version of add() gets called depends on the arguments used in the call -- if we provide two ints, C++ will know we mean to call add(int, int). If we provide two floating point numbers, C++ will know we mean to call add(double, double). In fact, we can define as many overloaded add() functions as we want, so long as each add() function has unique parameters.

Consequently, it’s also possible to define add() functions with a differing number of parameters:

```
int add(int x, int y, int z)
{
    return x + y + z;
}
```

Even though this add() function has 3 parameters instead of 2, because the parameters are different than any other version of add(), this is valid.


## Function return types are not considered for uniqueness

Note that the function’s return type is NOT considered when overloading functions. Consider the case where you want to write a function that returns a random number, but you need a version that will return an int, and another version that will return a double. You might be tempted to do this:

```
int getRandomValue();
double getRandomValue();
```

But the compiler will flag this as an error. These two functions have the same parameters (none), and consequently, the second getRandomValue() will be treated as an erroneous redeclaration of the first. Consequently, these functions will need to be given different names.

## Typedefs are not distinct

Since declaring a typedef does not introduce a new type, the following two declarations of Print() are considered identical:

```
typedef char *string;
void print(string value);
void print(char *value);
```

## How function calls are matched with overloaded functions

Making a call to an overloaded function results in one of three possible outcomes:

1) A match is found. The call is resolved to a particular overloaded function.
2) No match is found. The arguments can not be matched to any overloaded function.
3) An ambiguous match is found. The arguments matched more than one overloaded function.

When an overloaded function is called, C++ goes through the following process to determine which version of the function will be called:

1) First, C++ tries to find an exact match. This is the case where the actual argument exactly matches the parameter type of one of the overloaded functions. For example:

```
void print(char *value);
void print(int value);

print(0); // exact match with print(int)
```

Although 0 could technically match print(char*) (as a null pointer), it exactly matches print(int). Thus print(int) is the best match available.

2) If no exact match is found, C++ tries to find a match through promotion. In lesson 4.4 -- type conversion and casting, we covered how certain types can be automatically promoted via internal type conversion to other types. To summarize,

  - Char, unsigned char, and short is promoted to an int.
  - Unsigned short can be promoted to int or unsigned int, depending on the size of an int
  - Float is promoted to double
  - Enum is promoted to int

For example:

```
void print(char *value);
void print(int value);

print('a'); // promoted to match print(int)
```

In this case, because there is no print(char), the char ‘a’ is promoted to an integer, which then matches print(int).

3) If no promotion is possible, C++ tries to find a match through standard conversion. Standard conversions include:

  - Any numeric type will match any other numeric type, including unsigned (eg. int to float)
  - Enum will match the formal type of a numeric type (eg. enum to float)
  - Zero will match a pointer type and numeric type (eg. 0 to char*, or 0 to float)
  - A pointer will match a void pointer

For example:

```
struct Employee; // defined somewhere else
void print(float value);
void print(Employee value);

print('a'); // 'a' converted to match print(float)
```

In this case, because there is no print(char), and no print(int), the ‘a’ is converted to a float and matched with print(float).

Note that all standard conversions are considered equal. No standard conversion is considered better than any of the others.

4) Finally, C++ tries to find a match through user-defined conversion. Although we have not covered classes yet, classes (which are similar to structs) can define conversions to other types that can be implicitly applied to objects of that class. For example, we might define a class X and a user-defined conversion to int.

```
class X; // with user-defined conversion to int

void print(float value);
void print(int value);

X value; // declare a variable named value of type class X
print(value); // value will be converted to an int and matched to print(int)
```

Although value is of type class X, because this particular class has a user-defined conversion to int, the function call print(value) will resolve to the Print(int) version of the function.

We will cover the details on how to do user-defined conversions of classes when we cover classes.

If every overloaded function has to have unique parameters, how is it possible that a call could result in more than one match? Because all standard conversions are considered equal, and all user-defined conversions are considered equal, if a function call matches multiple candidates via standard conversion or user-defined conversion, an ambiguous match will result. For example:

```
void print(unsigned int value);
void print(float value);

print('a');
print(0);
print(3.14159);
```

In the case of `print('a')`, C++ can not find an exact match. It tries promoting ‘a’ to an int, but there is no print(int) either. Using a standard conversion, it can convert ‘a’ to both an unsigned int and a floating point value. Because all standard conversions are considered equal, this is an ambiguous match.

`print(0)` is similar. 0 is an int, and there is no print(int). It matches both calls via standard conversion.

`print(3.14159)` might be a little surprising, as most programmers would assume it matches print(float). But remember that all literal floating point values are doubles unless they have the ‘f’ suffix. 3.14159 is a double, and there is no print(double). Consequently, it matches both calls via standard conversion.

Ambiguous matches are considered a compile-time error. Consequently, an ambiguous match needs to be disambiguated before your program will compile. There are two ways to resolve ambiguous matches:

1) Often, the best way is simply to define a new overloaded function that takes parameters of exactly the type you are trying to call the function with. Then C++ will be able to find an exact match for the function call.

2) Alternatively, explicitly cast the ambiguous parameter(s) to the type of the function you want to call. For example, to have print(0) call the print(unsigned int), you would do this:

```
print(static_cast<unsigned int>(0)); // will call print(unsigned int)
```

## Matching for functions with multiple arguments

If there are multiple arguments, C++ applies the matching rules to each argument in turn. The function chosen is the one for which each argument matches at least as well as all the other functions, with at least one argument matching better than all the other functions. In other words, the function chosen must provide a better match than all the other candidate functions for at least one parameter, and no worse for all of the other parameters.

In the case that such a function is found, it is clearly and unambiguously the best choice. If no such function can be found, the call will be considered ambiguous (or a non-match).

## Conclusion

Function overloading can lower a programs complexity significantly while introducing very little additional risk. Although this particular lesson is long and may seem somewhat complex (particularly the matching rules), in reality function overloading typically works transparently and without any issues. The compiler will flag all ambiguous cases, and they can generally be easily resolved.
