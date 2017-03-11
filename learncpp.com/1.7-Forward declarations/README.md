# 1.7 - Forward declarations

Take a look at this seemingly innocent sample called add.cpp:

```
#include <iostream>

int main()
{
    using namespace std;
    cout << "The sum of 3 and 4 is: " << add(3, 4) << endl;
    return 0;
}

int add(int x, int y)
{
    return x + y;
}
```

You would expect this program to produce the result:

```The sum of 3 and 4 is: 7```

But in fact, it doesn’t compile at all! Visual Studio 2005 Express produces the following compile errors:

```
add.cpp(6) : error C3861: 'add': identifier not found
add.cpp(10) : error C2365: 'add' : redefinition; previous definition was 'formerly unknown identifier'
```

The reason this program doesn’t compile is because the compiler reads files sequentially. When the compiler reaches the function call to add() on line 6 of main(), it doesn’t know what add is, because we haven’t defined add() until line 10! That produces the first error (“identifier not found”).

When Visual Studio 2005 gets to the actual declaration of add() on line 10, it also complains about add being redefined. This is somewhat misleading, given that it wasn’t ever defined in the first place. Later versions of Visual Studio correctly omit this additional error message.

Despite the redundancy of the second error, it’s useful to note that it is fairly common for a single error to produce (often redundant) multiple compiler errors or warnings.

Rule: When addressing compile errors in your programs, always resolve the first error produced first.

To fix this problem, we need to address the fact that the compiler doesn’t know what add is. There are two common ways to address the issue.

Option 1: Reorder the function calls so add() is defined before main():

```
#include <iostream>

int add(int x, int y)
{
    return x + y;
}

int main()
{
    using namespace std;
    cout << "The sum of 3 and 4 is: " << add(3, 4) << endl;
    return 0;
}
```

That way, by the time main() calls add(), the compiler will already know what add() is. Because this is such a simple program, this change is relatively easy to do. However, in a larger program, it can be tedious trying to figure out which functions call which other functions (and in what order) so they can be declared sequentially.

Furthermore, this option is not always possible. Let’s say we’re writing a program that has two functions A and B. If function A calls function B, and function B calls function A, then there’s no way to order the functions in a way that they will both be happy. If you define A first, the compiler will complain it doesn’t know what B is. If you define B first, the compiler will complain that it doesn’t know what A is.

## Function prototypes and forward declaration functions

Option 2: Use a forward declaration.

A **forward declaration** allows us to tell the compiler about the existence of an identifier before actually defining the identifier.

In the case of functions, this allows us to tell the compiler about the existence of a function before we define the function’s body. This way, when the compiler encounters a call to the function, it’ll understand that we’re making a function call, and can check to ensure we’re calling the function correctly, even if it doesn’t yet know how or where the function is defined.

To write a forward declaration for a function, we use a declaration statement called a **function prototype**. The function prototype consists of the function’s return type, name, parameters, but no function body (the part between the curly braces). And because the function prototype is a statement, it ends with a semicolon.

Here’s a function prototype for the add() function:

```
int add(int x, int y); // function prototype includes return type, name, parameters, and semicolon.  No function body!
```

Now, here’s our original program that didn’t compile, using a function prototype as a forward declaration for function add():

```
#include <iostream>

int add(int x, int y); // forward declaration of add() (using a function prototype)

int main()
{
    using namespace std;
    cout << "The sum of 3 and 4 is: " << add(3, 4) << endl; // this works because we forward declared add() above
    return 0;
}

int add(int x, int y) // even though the body of add() isn't defined until here
{
    return x + y;
}
```

Now when the compiler reaches add() in main, it will know what add() looks like (a function that takes two integer parameters and returns an integer), and it won’t complain.

It is worth noting that function prototypes do not need to specify the names of the parameters. In the above code, you can also forward declare your function like this:

```
int add(int, int);
```

However, we prefer to name our parameters, because it allows you to understand what the function parameters are just by looking at the prototype. Otherwise, you’ll have to locate the actual function definition.

Tip: You can easily create function prototypes by using copy/paste on your function declaration. Don’t forget the semicolon on the end.

## Forgetting the function body

One question many new programmers have is: what happens if we forward declare a function but do not define it?

The answer is: it depends. If a forward declaration is made, but the function is never called, the program will compile and run fine. However, if a forward declaration is made, the function is called, but the program never defines the function, the program will compile okay, but the linker will complain that it can’t resolve the function call.

Consider the following program:

```
#include <iostream>

int add(int x, int y); // forward declaration of add() using function prototype

int main()
{
    using namespace std;
    cout << "The sum of 3 and 4 is: " << add(3, 4) << endl;
    return 0;
}
```

In this program, we forward declare add(), and we call add(), but we never define add() anywhere. When we try and compile this program, Visual Studio 2005 Express produces the following message:

```
Compiling...
add.cpp
Linking...
add.obj : error LNK2001: unresolved external symbol "int __cdecl add(int,int)" (?add@@YAHHH@Z)
add.exe : fatal error LNK1120: 1 unresolved externals
```

As you can see, the program compiled okay, but it failed at the link stage because int add(int, int) was never defined.

## Other types of forward declarations

Forward declarations are most often used with functions. However, forward declarations can also be used with other identifiers in C++, such as variables and user-defined types. Other types of identifiers (e.g. user-defined types) have a different syntax for forward declaration.

We’ll talk more about how to forward declare other types of identifiers in future lessons.

## Declarations vs. definitions

In C++, you’ll often hear the words “declaration” and “definition” used. What do they mean? You now have enough of a framework to understand the difference between the two.

A **definition** actually implements or instantiates (causes memory to be allocated for) the identifier. Here are some examples of definitions:

```
int add(int x, int y) // defines function add()
{
    return x + y;
}

int x; // instantiates (causes memory to be allocated for) an integer variable named x
```

You can only have one definition per identifier. A definition is needed to satisfy the linker.

A **declaration** is a statement that defines an identifier (variable or function name) and its type. Here are some examples of declarations:

```
int add(int x, int y); // declares a function named "add" that takes two int parameters and returns an int.  No body!
int x; // declares an integer variable named x
```

A declaration is all that is needed to satisfy the compiler. This is why using a forward declaration is enough to keep the compiler happy. However, if you forget to include the definition for the identifier, the linker will complain.

You’ll note that “int x” appears in both categories. In C++, all definitions also serve as declarations. Since “int x” is a definition, it’s by default a declaration too. This is the case with most declarations.

However, there are a small subset of declarations that are not definitions, such as function prototypes. These are called pure declarations. Others types of pure declarations include forward declarations for variables, class declarations, and type declarations (you will encounter these in future lessons, but don’t need to worry about them now). You can have as many pure declarations for an identifier as you desire (although having more than one is typically redundant).

## Quiz

1) What’s the difference between a function prototype and a forward declaration?

2) Write the function prototype for this function:

```
int doMath(int first, int second, int third, int fourth)
{
     return first + second * third / fourth;
}
```

3) For each of the following programs, state whether they fail to compile, fail to link, or compile and link. If you are not sure, try compiling them!

```
#include <iostream>
int add(int x, int y);

int main()
{
    using namespace std;
    cout << "3 + 4 + 5 = " << add(3, 4, 5) << endl;
    return 0;
}

int add(int x, int y)
{
    return x + y;
}
```

4)

```
#include <iostream>
int add(int x, int y);

int main()
{
    using namespace std;
    cout << "3 + 4 + 5 = " << add(3, 4, 5) << endl;
    return 0;
}

int add(int x, int y, int z)
{
    return x + y + z;
}
```

5)

```
#include <iostream>
int add(int x, int y);

int main()
{
    using namespace std;
    cout << "3 + 4 + 5 = " << add(3, 4) << endl;
    return 0;
}

int add(int x, int y, int z)
{
    return x + y + z;
}
```

6)

```
#include <iostream>
int add(int x, int y, int z);

int main()
{
    using namespace std;
    cout << "3 + 4 + 5 = " << add(3, 4, 5) << endl;
    return 0;
}

int add(int x, int y, int z)
{
    return x + y + z;
}
```
