# 1.3 — A first look at variables, initialization, and assignment

## Variables

A statement such as x = 5; seems obvious enough. As you would guess, we are assigning the value of 5 to x. But what exactly is x? x is a variable.

A **variable** in C++ is a name for a piece of memory that can be used to store information. You can think of a variable as a mailbox, or a cubbyhole, where we can put and retrieve information. All computers have memory, called RAM (random access memory), that is available for programs to use. When a variable is defined, a piece of that memory is set aside for the variable.

In this section, we are only going to consider integer variables. An **integer** is a whole number, such as 1, 2, 3, -1, -12, or 16. An integer variable is a variable that holds an integer value.

In order to define a variable, we generally use a **declaration statement**. Here’s an example of defining variable x as an integer variable (one that can hold integer values):

```
int x;
```

When this statement is executed by the CPU, a piece of memory from RAM will be set aside (called instantiation). For the sake of example, let’s say that the variable x is assigned memory location 140. Whenever the program sees the variable x in an expression or statement, it knows that it should look in memory location 140 to get the value.

One of the most common operations done with variables is assignment. To do this, we use the assignment operator, more commonly known as the = symbol. For example:

```
x = 5;
```

When the CPU executes this statement, it translates this to “put the value of 5 in memory location 140”.

Later in our program, we could print that value to the screen using std::cout:

```
std::cout << x;  // prints the value of x (memory location 140) to the console
```

## l-values and r-values

In C++, variables are a type of l-value (pronounced ell-value). An l-value is a value that has an address (in memory). Since all variables have addresses, all variables are l-values. The name l-value came about because l-values are the only values that can be on the left side of an assignment statement. When we do an assignment, the left hand side of the assignment operator must be an l-value. Consequently, a statement like 5 = 6; will cause a compile error, because 5 is not an l-value. The value of 5 has no memory, and thus nothing can be assigned to it. 5 means 5, and its value can not be reassigned. When an l-value has a value assigned to it, the current value at that memory address is overwritten.

The opposite of l-values are r-values (pronounced arr-values). An r-value refers to any value that can be assigned to an l-value. r-values are always evaluated to produce a single value. Examples of r-values are single numbers (such as 5, which evaluates to 5), variables (such as x, which evaluates to whatever value was last assigned to it), or expressions (such as 2 + x, which evaluates to the value of x plus 2).

Here is an example of some assignment statements, showing how the r-values evaluate:

```
int y;      // define y as an integer variable
y = 4;      // 4 evaluates to 4, which is then assigned to y
y = 2 + 5;  // 2 + 5 evaluates to 7, which is then assigned to y

int x;      // define x as an integer variable
x = y;      // y evaluates to 7 (from before), which is then assigned to x.
x = x;      // x evaluates to 7, which is then assigned to x (useless!)
x = x + 1;  // x + 1 evaluates to 8, which is then assigned to x.
```

Let’s take a closer look at the last assignment statement above, since it causes the most confusion.

```
x = x + 1;
```

In this statement, the variable x is being used in two different contexts. On the left side of the assignment operator, “x” is being used as an l-value (variable with an address). On the right side of the assignment operator, x is being used as an r-value, and will be evaluated to produce a value (in this case, 7). When C++ evaluates the above statement, it evaluates as:

```
x = 7 + 1;
```

Which makes it obvious that C++ will assign the value 8 back into variable x.

Programmers don’t tend to talk about l-values or r-values much, so it’s not that important to remember the terms. The key takeaway is that on the left side of the assignment, you must have something that represents a memory address (such as a variable). Everything on the right side of the assignment will be evaluated to produce a value.

## Initialization vs assignment

C++ supports two related concepts that new programmers often get mixed up: assignment and initialization.

After a variable is defined, a value may be assigned to it via the assignment operator (the = sign):

```
int x; // this is a variable definition
x = 5; // assign the value 5 to variable x
```


C++ will let you both define a variable AND give it an initial value in the same step. This is called initialization.

```
int x = 5; // initialize variable x with the value 5
```

A variable can only be initialized when it is defined.

Although these two concepts are similar in nature, and can often be used to achieve similar ends, we’ll see cases in future lessons where some types of variables require an initialization value, or disallow assignment. For these reasons, it’s useful to make the distinction now.


## Uninitialized variables

Unlike some programming languages, C/C++ does not initialize variables to a given value (such as zero) automatically (for performance reasons). Thus when a variable is assigned to a memory location by the compiler, the default value of that variable is whatever garbage happens to already be in that memory location! A variable that has not been assigned a value is called an uninitialized variable.

Note: Some compilers, such as Visual Studio, will initialize the contents of memory when you’re using a debug build configuration. This will not happen when using a release build configuration.

Uninitialized variables can lead to interesting (and by interesting, we mean unexpected) results. Consider the following short program:

```
// #include "stdafx.h" // Uncomment if Visual Studio user
#include <iostream>

int main()
{
    // define an integer variable named x
    int x;

    // print the value of x to the screen (dangerous, because x is uninitialized)
    std::cout << x;

    return 0;
}
```

In this case, the computer will assign some unused memory to x. It will then send the value residing in that memory location to cout, which will print the value. But what value will it print? The answer is “who knows!”, and the answer may change every time you run the program. When the author ran this program with the Visual Studio 2013 compiler, std::cout printed the value 7177728 one time, and 5277592 the next.

A couple of notes if you want to run this program yourself:

- Make sure you’re using a release build configuration (see section 0.6a -- Build configurations for information on how to do that). Otherwise the above program may print whatever value your compiler is initializing memory with (Visual Studio uses -858993460).

- If your compiler won’t let you run this program because it flags variable x as an uninitialized variable, a possible solution to get around this issue is noted in the comments section.

Using uninitialized variables is one of the most common mistakes that novice programmers make, and unfortunately, it can also be one of the most challenging to debug (because the program may run fine anyway if the uninitialized value happened to get assigned to a spot of memory that had a reasonable value in it, like 0).

Fortunately, most modern compilers will print warnings at compile-time if they can detect a variable that is used without being initialized. For example, compiling the above program on Visual Studio 2005 express produced the following warning:

```
c:vc2005projectstesttesttest.cpp(11) : warning C4700: uninitialized local variable 'x' used
```

A good rule of thumb is to initialize your vriables. This ensure that your variable will always have a consistent value, making it easier to debug if something goes wrong somewhere else.

## Quiz

What values does this program print?

```
#include <iostream>

int main(int argc, const char *argv[])
{
  int x = 5;
  x = x - 2;
  std::cout << x << std::endl;

  int y = x;
  std::cout << y << std::endl;

  std::cout << x + y << std::endl;
  std::cout << x << std::endl;

  int z;
  std::cout << z << std::endl;
}
```
