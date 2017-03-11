# 2.6 - Boolean values and an introduction to if statements.

The next data type we're going to look at is the boolean data type. Boolean variables only have two possible values: true(1) and false(0)

To declare a boolean variable, we use the keyword **bool**.

```
bool b;
```

When assigning values to boolean variables, we use the keywords **true** and **false**.

```
bool b1 = true;   // explicit initialization
bool b2(false);   // implicit initialization
bool b3 { true }; // uniform initialization
```

Just as the unary minus operator (-) can be used to make an integer negative, the logical NOT operator (!) can be used to flip a boolean value from true to false, or false to true:

```
bool b1 = !true;  // b1 will have the value false
bool b2(!false);  // b2 will have the value true
```

When boolean values are evaluates, they actually don't evaluate to true or false. They evaluate to the integers 0 (false) or 1 (true). Consequently, when we print their values with cout, it prints 0 for false, and 1 for true.

```
#include <iostream>

int main()
{
    bool b(true);
    std::cout << b << std::endl;
    std::cout << !b << std::endl;

    bool b2(false);
    std::cout << b2 << std::endl;
    std::cout << !b2 << std::endl;
    return 0;
}
```

If you want cout to print "true" or "false" instead of 0 or 1, you can use std::boolalpha:

```
#include <iostream>

int main()
{
    std::cout << true << std::endl;
    std::cout << false << std::endl;
    std::cout << std::boolalpha; // print bools as true or false
    std::cout << true << std::endl;
    std::cout << false << std::endl;
    return 0;
}
```

This prints:
1
0
true
false

## A first look at booleans in if-statements

One of the most common uses for boolean variables is inside if statements. If statements take the following form:

```
if (condition) statement
```

or

```
if (condition) statement
else statement2;
```

In both forms, condition is evaluated. If condition evaluates to true (non-zero), then statement is executed. In the second form, if condition evaluates to false, then statement2 is executed instead.

```
bool b(true);
if (b)
    std::cout << "b is true" << std::endl;
else
    std::cout << "b is false" << std::endl;
```

prints

```
b is true
```

Boolean values are also useful as the return values for functions that check whether something is true or not. Such functions are typically named starting with the word is (e.g. isEqual) or has (e.g. hasCommonFactor).

In the following example, we use the equality operator (==) to test if two values are equal. Operator== returns true if the operands are equal, and false if they are not.

Note that in C++, a single equals (=) is the assignment operator, whereas a double equals (==) is a comparison operator to test for equality.

```
#include <iostream>

// returns true if x and y are equal, false otherwise
bool isEqual(int x, int y)
{
    return (x == y); // operator== returns true if x equals y, and false otherwise
}

int main()
{
    std::cout << "Enter an integer: ";
    int x;
    std::cin >> x;

    std::cout << "Enter another integer: ";
    int y;
    std::cin >> y;

    bool equal = isEqual(x, y);
    if (equal)
        std::cout << x << " and " << y << " are equal" << std::endl;
    else
        std::cout << x << " and " << y << " are not equal" << std::endl;
    return 0;
}
```

In this case, because we only use equal in one place, there’s really no need to assign it to a variable. We could do this instead:

```
if (isEqual(x, y))
    std::cout << x << " and " << y << " are equal" << std::endl;
else
    std::cout << x << " and " << y << " are not equal" << std::endl;
```

Boolean variables are quite refreshing in their simplicity!

One additional note: when converting integers to booleans, the integer zero resolves to boolean false, whereas non-zero integers all resolve to true.

## Quiz

1) A prime number is a whole number greater than 1 that can only be divided evenly by 1 and itself. Write a program that asks the user to enter a single digit integer. If the user enters a single digit that is prime (2, 3, 5, or 7), print “The digit is prime”. Otherwise, print “The digit is not prime”.

Hint: Use if statements to compare the number the user entered to the prime numbers. Use a boolean to keep track of whether the user entered a prime number or not.
