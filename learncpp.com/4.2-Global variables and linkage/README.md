
# 4.2 - Global variables and linkage

In the last lesson, you learned that variables declared inside a block are called local variables. Local variables have block scope (they are only visible within the block they are declared), and have automatic duration (they are created when the block is entered and destroyed when the block is exited).

Variables declared outside of a block are called global variables. Global variables have **static duration**, which means they are created when the program starts and are destroyed when it ends. Global variables have **global scope** (also called “global namespace scope” or “file scope”), which means they are visible until the end of the file in which they are declared.

## Defining global variables

By convention, global variables are declared at the top of a file, below the includes, but above any code. Here’s an example of a couple of global variables being defined.

```
#include <iostream>

// Variables declared outside of a block are global variables
int g_x; // global variable g_x
const int g_y(2); // global variable g_y

int doSomething()
{
    // global variables can be seen and used everywhere in program
    g_x = 3;
    std::cout << g_y << "\n";
}

int main()
{
    // global variables can be seen everywhere in program
    g_x = 5;
    std::cout << g_y << "\n";

    return 0;
}
```

Similar to how variables in an inner block with the same name as a variable in an outer block hides the variable in the outer block, local variables with the same name as a global variable hide the global variable inside the block that the local variable is declared in. However, the global scope operator (::) can be used to tell the compiler you mean the global version instead of the local version.

```
#include <iostream>
int value(5); // global variable

int main()
{
    int value = 7; // hides the global variable value
    value++; // increments local value, not global value
    ::value--; // decrements global value, not local value

    std::cout << "global value: " << ::value << "\n";
    std::cout << "local value: " << value << "\n";
    return 0;
} // local value is destroyed
```

The code prints:

global value: 4
local value: 8

However, having local variables with the same name as global variables is usually a recipe for trouble, and should be avoided whenever possible. By convention, many developers prefix global variable names with “g_” to indicate that they are global. This both helps identify global variables as well as avoids naming conflicts with local variables.

## Internal and external linkage via the static and extern keywords

In addition to scope and duration, variables have a third property: linkage. A variable’s linkage determines whether it can be referenced by other files.

A variable with internal linkage is called an internal variable (or static variable), and it can only be used within the file it is defined in. A variable with external linkage is called an external variable, and it can be used both in the file it is defined in, as well as in other files.

If we want to make a global variable internal (able to be used only within a single file), we can use the static keyword to do so:

```
static int g_x; // g_x is static, and can only be used within this file

int main()
{
    return 0;
}
```

Similarly, if we want to make a global variable external (able to be used anywhere in our program), we can use the extern keyword to do so:

```
extern double g_y(9.8); // g_y is external, and can be used by other files

int main()
{
    return 0;
}
```

By default, non-const variables declared outside of a block are assumed to be external. However, const variables declared outside of a block are assumed to be internal.


## Variable forward declarations via the extern keyword
In the section on programs with multiple files, you learned that in order to use a function declared in another file, you have to use a function forward declaration.

Similarly, in order to use an external global variable that has been declared in another file, you have to use a variable forward declaration. For variables, creating a forward declaration is also done via the extern keyword.

Here is an example of using a variable forward declaration:

global.cpp:

```
// define two global variables
int g_x;
int g_y(2);
// in this file, g_x and g_y can be used anywhere beyond this point
```

main.cpp:

```
extern int g_x; // forward declaration for g_x -- g_x can be used beyond this point in this file

int main()
{
    extern int g_y; // forward declaration for g_y -- g_y can be used beyond this point in main()

    g_x = 5;
    std::cout << g_y; // should print 2

    return 0;
}
```

If the forward declaration is declared outside of a block, it applies for the whole file. If the forward declaration is declared inside a block, it applies within that block only.

If a variable is declared as static, trying to use a forward declaration to access it will not work:


constants.cpp:

```
static const double g_gravity(9.8);
```

main.cpp:

```
#include <iostream>

extern const double g_gravity; // will not find g_gravity in constants.cpp because g_gravity has internal linkage.

int main()
{
    std:: cout << g_gravity; // will cause compile error because g_gravity has not been defined as far as main.cpp knows
    return 0;
}
```

Note that if you want to define an uninitialized non-const global variable, do not use the extern keyword, otherwise C++ will think you’re trying to make a forward declaration for the variable.

## Side note on function linkages

Functions have the same linkage property that variables do. Functions always default to external linkage, but can be set to internal linkage via the static keyword:

```
// This function is declared as static, and can now be used only within this file
// Attempts to access it via a function prototype will fail
static int add(int x, int y)
{
    return x + y;
}
```

Function forward declarations don’t need the extern keyword. C++ is able to tell whether you’re defining a function or a function prototype by whether you supply a function body or not.

## Global symbolic constants

In section 2.9 -- Symbolic constants and the const keyword, we introduced the concept of symbolic constants, and defined them like this:

constants.h:

```
#ifndef CONSTANTS_H
#define CONSTANTS_H

// define your own namespace to hold constants
namespace Constants
{
    const double pi(3.14159);
    const double avogadro(6.0221413e23);
    const double my_gravity(9.2); // m/s^2 -- gravity is light on this planet
    // ... other related constants
}
#endif
```

While this is simple (and fine for smaller programs), every time constants.h gets #included, each of these variables is copied into the including code file. If constants.h gets included 20 times, each of these variables is duplicated 20 times. That’s not too much of a problem here, but if this list of constants were large, and/or included memory-intensive variables, it could lead to code bloat.

We can avoid this problem by turning these constants into const global variables, and making the header file hold only the variable forward declarations:

constants.cpp:

```
namespace Constants
{
    // actual global variables
    extern const double pi(3.14159);
    extern const double avogadro(6.0221413e23);
    extern const double my_gravity(9.2); // m/s^2 -- gravity is light on this planet
}
```

constants.h:

```
#ifndef CONSTANTS_H
#define CONSTANTS_H

namespace Constants
{
    // forward declarations only
    extern const double pi;
    extern const double avogadro;
    extern const double my_gravity;
}

#endif
```

Use in the code file stays the same:

```
#include "constants.h"
double circumference = 2 * radius * Constants::pi;
```

Now the symbolic constants will get instantiated only once (in constants.cpp), instead of once every time constants.h is #included, and the other uses will simply refer to the version in constants.cpp.

Because global symbolic constants should be namespaced and are read-only, the use of the g_ prefix is not necessary.

## A word of caution about (non-const) global variables

New programmers are often tempted to use lots of global variables, because they are easy to work with, especially when many functions are involved. However, use of non-const global variables should generally be avoided altogether! We’ll discuss why in the next section.

## Summary

Global variables have global scope, and can be used anywhere in the program. Like functions, you must use a forward declaration (via keyword extern) to use a global variable defined in another file.

By default, non-const global variables have external linkage. You can use the static keyword to explicitly make them internal if desired.
By default, const global variables have internal linkage. You can use the extern keyword to explicitly make them external if desired.

Use a g_ prefix to help identify your non-const global variables.

Here’s a summary chart of the use of the extern keyword for non-const and const variable use cases:

```
// Uninitialized definition:
int g_x;       // defines uninitialized global variable (external linkage)
const int g_x; // not allowed: const variables must be initialized

// Forward declaration via extern keyword:
extern int g_z;       // forward declaration for global variable defined elsewhere
extern const int g_z; // forward declaration for const global variable defined elsewhere

// Initialized definition:
int g_y(1);       // defines initialized global variable (external linkage)
const int g_y(1); // defines initialized static variable (internal linkage)

// Initialized definition w/extern keyword:
extern int g_w(1);       // defines initialized global variable (external linkage, extern keyword is redundant in this case)
extern const int g_w(1); // defines initialized const global variable (external linkage)
```

## Quiz

1) What’s the difference between a variable’s scope, duration, and linkage? What kind of scope, duration, and linkage do global variables have?
