
# 1.10a - Header guards

## The duplicate definition problem

In lesson 1.7 -- Forward declarations and definitions, we noted that an identifier can only have one definition. Thus, a program that defines a variable identifier more than once will cause a compile error:

```
int main()
{
    int x; // this is a definition for identifier x
    int x; // compile error: duplicate definition

    return 0;
}
```

Similarly, programs that define a function more than once will also cause a compile error:

```
#include <iostream>

int foo()
{
return 5;
}

int foo() // compile error: duplicate definition
{
return 5;
}

int main()
{
    std::cout << foo();
    return 0;
}
```

While these programs are easy to fix (remove the duplicate definition), with header files, it’s quite easy to end up in a situation where a definition in a header file gets included more than once. This can happen when a header file #includes another header file (which is common).

Consider the following example:

math.h:

```
double pi = 3.14159; // this is a definition
```

geometry.h:

```
#include "math.h"
```

main.cpp:

```
#include "math.h"
#include "geometry.h"

int main()
{
    return 0;
}
```

This seemingly innocent looking program won’t compile! The root cause of the problem here is that math.h contains a definition. Here’s what’s actually happening. First, main.cpp #includes “math.h”, which copies the definition for variable pi into main.cpp. Then main.cpp #includes “geometry.h”, which #includes “math.h” itself. This copies the definition for variable pi into geometry.h, which then gets copied into main.cpp.

Thus, after resolving all of the #includes, main.cpp ends up looking like this:

```
double pi = 3.14159; // from math.h
double pi = 3.14159; // from geometry.h

int main()
{
    return 0;
}
```

Duplicate definitions and a compile error. Each file, individually, is fine. However, because main.cpp #includes two headers that #include the same definition, we’ve run into problems. If geometry.h needs this constant, and main.cpp needs both geometry.h and math.h, how would you resolve this issue?

Note that it’s not just variable definitions that can cause this issue -- it’s any kind of definition. If math.h included a function definition, or a user-defined type, we’d run into the same problem.

## Header guards

The good news is that this is actually easy to fix via a mechanism called a header guard (also called an include guard). Header guards are conditional compilation directives that take the following form:

```
#ifndef SOME_UNIQUE_NAME_HERE
#define SOME_UNIQUE_NAME_HERE

// your declarations and definitions here

#endif
```

When this header is included, the first thing it does is check whether SOME_UNIQUE_NAME_HERE has been previously defined. If this is the first time we’ve included the header, SOME_UNIQUE_NAME_HERE will not have been defined. Consequently, it #defines SOME_UNIQUE_NAME_HERE and includes the contents of the file. If we’ve included the header before, SOME_UNIQUE_NAME_HERE will already have been defined from the first time the contents of the header were included. Consequently, the entire header will be ignored.

All of your header files should have header guards on them. SOME_UNIQUE_NAME_HERE can be any name you want, but typically the name of the header file with a _H appended to it is used. For example, math.h would have the header guard:

math.h:

```
#ifndef MATH_H
#define MATH_H

double pi = 3.14159;

#endif
```

Even the standard library includes use header guards. If you were to take a look at the iostream header file from Visual Studio, you would see:

```
#ifndef _IOSTREAM_
#define _IOSTREAM_

// content here

#endif
```

## Updating our previous example with header guards


Let’s return to the math.h example, using the math.h with header guards.

math.h

```
#ifndef MATH_H
#define MATH_H

double pi = 3.14159;

#endif
```

geometry.h:

```
#include "math.h"
```

main.cpp:

```
#include "math.h"
#include "geometry.h"

int main()
{
    return 0;
}
```

Now, when main.cpp #includes “math.h”, the preprocessor will see that MATH_H hasn’t been defined yet. The contents of math.h are copied into main.cpp, and MATH_H is defined. main.cpp then #includes “geometry.h”, which #includes “math.h”. The preprocessor sees that MATH_H has previously been defined, and the contents between the header guards are skipped.

Thus, by adding the header guards, we’ve ensured that the contents of math.h are only included once in main.cpp.

For good form, we should also add header guards geometry.h.

```
#pragma once
```

Many compilers support an simpler, alternate form of header guards using the #pragma directive:


```
#pragma once

// your code here
```

#pragma once serves the same purpose as header guards, and has the added benefit of being shorter and less error-prone. The stdafx.h file that Visual Studio includes in projects that use precompiled headers makes use of this directive in place of header guards.

However, #pragma once is not an official part of the C++ language, and not all compilers support it (although most modern compilers do).

For compatibility purposes, we recommend sticking to header guards.

## Summary

Header guards are designed to ensure that the contents of a given header file is are not copied more than once into any single file, in order to prevent duplicate definitions. Note that header guards do not prevent the contents of a header file from being copied (once) into different project files. This is a good thing, because we often need to reference the contents of a header from different project files.

## Quiz

1) Using the math.h example above, add header guards to file geometry.h
