# 1.3a - A first look at cout, cin, endl, the std namespace, and using statements

## std::cout

As noted in previous sections, the std::cout object (in the iostream library) can be used to output text to the console. As a reminder, here’s our Hello world program:

```
#include <iostream>

int main()
{
    std::cout << "Hello world!";
    return 0;
}
```

To print more than one thing on the same line, the output operator (<<) can be used multiple times. For example:

```
#include <iostream>

int main()
{
    int x = 4;
    std::cout << "x is equal to: " << x;
    return 0;
}
```

This program prints:

```x is equal to: 4```

What would you expect this program to print ?

```
#include <iostream>

int main()
{
    std::cout << "Hi!";
    std::cout << "My name is Alex.";
    return 0;
}
```

You might be surprised at the result:

```Hi!My name is Alex.```

## std::endl

If we want to print things to more than one line, we can do that by using std::endl. When used with std::cout, std::endl inserts a newline character (causing the cursor to go to the start of the next line.)

For example:

```
#include <iostream>

int main()
{
    std::cout << "Hi!" << std::endl;
    std::cout << "My name is Alex." << std::endl;
    return 0;
}
```

This prints:

```
Hi!
My name is Alex.
```


## std::cin

std::cin is the opposite of std::cout -- whereas std::cout prints data to the console using the output operator (<<), std::cin reads input from the user at the console using the input operator (>>). Now that you have a basic understanding of variables, we can use std::cin to get input from the user and store it in a variable.

```
#include <iostream>

int main()
{
    std::cout << "Enter a number: "; // ask user for a number
    int x = 0;
    std::cin >> x;  // read number from console and store it in x
    std::cout << "You entered " << x << std::endl;
    return 0;
}
```

Try compiling this program and running it for yourself. When you run the program, it will print “Enter a number: ” and then wait for you to enter one. Once you enter a number (and press enter), it will print “You entered ” followed by the number you just entered.

For example (I entered 4):

```
Enter a number: 4
You entered 4
```

This is an easy way to get input from the user, and we will use it in many of our examples going forward.

If your screen closes immediately after entering a number, please see section 0.7 -- a few common cpp problems for a solution.

(As an interesting side note, if you enter a really big number, the results may surprise you. Try it! This happens because x can only hold numbers up to a certain size. After that, it “overflows”. We’ll discuss overflow in a future section.)

## std::cin, std::cout, <<, and >>

New programmers often mix up std::cin, std::cout, << and >>. Here's an easy way to remember:

  - std::cin and cout always go on the left-hand side of the statement.
  - std::cout is used to output a value (cout = output)
  - std::cin is used to get an input value (cin = input)
  - << is used with std::cout, and shows the direction that data is moving from the r-value to the console. std::cout << 4 moves the value of 4 to the console.
  - \>\> is used with std::cin, and shows the direction that data is moving from the console into the variable. std::cin >> x moves the value from the console into x.


## the std namespace

Everything in the standard library is defined inside a special area (called a namespace) that is named std (short for standard).

It turns out that std::cout's name isn't really "std::cout". It's actually just "cout", and "std" is the name of the namespace it lives inside.

We'll talk more about namespaces in a future lesson and also teach you how to create your own. For now, the only thing you need to know about namespaces is that whenever we use something (like cout) that is part of the standard library, we need to tell the compiler that it is inside the std namespace.

## Explicit namespace qualifier std::

One way to tell the compiler that cout lives in the std namespace is by using the "std::" prefix. For example:

```
std::cout << "Hello world!";
```

This is the safest way to use cout, because there's no ambigulity about where cout lives(it's clearly in the std namespace)


However, if you're using the standard library a lot, typing "std::" before everything you use from the standard library can become repetitive and make things hard to read. C++ provides two alternatives to simplify things.

## The using declaration

One way to simplify things is to utilize a **using declaration** statement. Here's our Hello world program again, with a using declaration on line 5:

```
#include <iostream>

int main()
{
   using std::cout; // this using declaration tells the compiler that cout should resolve to std::cout
   cout << "Hello world!"; // so no std:: prefix is needed here!
   return 0;
}
```

The using declaration "using std::cout;" tells the compiler that we're going to be using the object "cout" from the std namespace. So whenever it sees "cout", it will assume that we mean "std::cout". If there's a naming conflict between std::cout and some other use of cout, std::cout will be preferred. Therefore on line 6, we can type "cout" instead of "std::cout".

This doesn't save much effort in this trivial example, but if you are using cout a lot inside of a function, a using declaration can make your code more readable. Note that you will need a separate using declaration for each name you use (e.g. one for std::cout, one for std::cin, and one for std::endl).

Although this method is less explicit than using the "std::" prefix, it's generally considered safe and acceptable.


## The using directive

Another way to simplify things is to use a **using directive** statement. Here's our Hello world program again, with a using directive on line 5:

```
#include <iostream>

int main()
{
   using namespace std; // this using directive tells the compiler that we're using everything in the std namespace!
   cout << "Hello world!"; // so no std:: prefix is needed here!
   return 0;
}
```


**The using directive "using namespace std;" tells the compiler that we want to use everything in the std namespace, so if the compiler finds a name it doesn't recognize, it will check the std namespace.** Consequently, when the compiler encounters "cout" (which it won't recognize), it'll look in the std namespace and find it there. If a naming conflict did occur, the compile would show a compile error.

There's open debate about whether this solution is good practice or not. Because using directives pull in all of the names in a namespace, the chance for a naming collisions goes up significantly (but is still relatively small).


## Using declarations and directives inside or outside of a function

If a using declaration or directive is used within a function, the names in the namespace are only directly accessible within that function. That limits the chance for naming collisions to occur just within that function. However, if a using declaration or directive is used outside of a function, the names in the namespace are directly accessible anywhere in the entire file! That can greatly increase the chance for collisions.

## A collision example

For illustrative purposes, let's take a look at an example where a using statement causes a naming collision:

```
#include <iostream>

int cout() // declares our own "cout" function
{
    return 5;
}

int main()
{
    using namespace std; // makes std::cout accessible as "cout"
    cout << "Hello, world!"; // uh oh!  Which cout do we want here?

    return 0;
}
```

```
src [master●] g++ collision.cpp
collision.cpp:11:2: error: reference to 'cout' is ambiguous
        cout << "Hello, world!";  // uh oh! Which cout do we want here?
        ^
collision.cpp:3:5: note: candidate found by name lookup is 'cout'
int cout() // declares "cout" function
    ^
/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/../include/c++/v1/iostream:54:33: note: candidate found by name lookup is 'std::__1::cout'
extern _LIBCPP_FUNC_VIS ostream cout;
                                ^
1 error generated.
```

In the above example, the compiler is unable to determine whether we meant std::cout or the cout function we've defined. In this case, it will fail to compile with an "ambiguous symbol" error. Although this example is trivial, if we had explicitly prefixed std::cout like this:

```
std::cout << "Hello World!";
```

or used a using declaration instead of a using directive:

```
using std::cout;
cout << "Hello, world!";
```

then our program wouldn't have any issues in the first place.

Many people avoid "using directives" altogether for this reason. Others find them acceptable so long as they are used only within individual functions (which limits the places where naming collisions can occur to just those functions).


## A note on using statements

In the examples beyond this page, we'll generally use the explicit qualifier method, though in certain cases, we'll opt to use "using directives" within functions when it improves readability. It is up to whether you want to follow this practice yourself, or avoid "using" staements altogether.

In either case, you should avoid "using" statements outside of a function body.
