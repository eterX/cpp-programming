# 1.8 - Programs with multiple files

As programs get larger, it is not uncommon to split them into multiple files for organizational or reusability purposes. One advantage of working with an IDE is they make working with multiple files much easier. You already know how to create and compile single-file projects. Adding new files to existing projects is very easy.

## Adding files to your project in Visual Studio

In Visual Studio, right click on “Source Files” in the Solution Explorer window on the left, and choose Add -> New Item. Make sure you have “C++ File (.cpp)” selected. Give the new file a name, and it will be added to your project.

Note: If you create a new file from the File menu instead of from your project in the Solution Explorer, the new file won’t be added to your project automatically. You’ll have to add it to the project manually. To do so, right click on “Source Files” in the Solution Explorer, choose Add -> Existing Item, and then select your file.

When you compile your program, the new file will be automatically included, since it’s part of your project.

## Adding files to your project from the command line

From the command line, you can create the additional file yourself, using your favorite editor, and give it a name. When you compile your program, you’ll need to include all of the relevant code files on the compile line. For example: “g++ main.cpp add.cpp -o main”, where main.cpp and add.cpp are the names of your code files, and main is the name of the output file.

## A multi-file example

Now, consider the following multi-file program:

**add.cpp**

```
//#include "stdafx.h" // uncomment if using Visual Studio

int add(int x, int y)
{
    return x + y;
}
```

**main.cpp**

```
//#include "stdafx.h" // uncomment if using Visual Studio
#include <iostream>

int main()
{
    using namespace std;
    cout << "The sum of 3 and 4 is: " << add(3, 4) << endl;
    return 0;
}
```

Try compiling this program for yourself. You will note that it doesn’t compile, and it gives the same compiler error as the program in the previous lesson where the functions were declared in the wrong order:

```
add.cpp(10) : error C3861: 'add': identifier not found
add.cpp(15) : error C2365: 'add' : redefinition; previous definition was 'formerly unknown identifier'
```

When the compiler is compiling a code file, it does not know about the existence of functions that live in any other files. This limited visibility is intentional, so that files may have functions or variables that have the same names as those in other files without causing a naming conflict.

However, in this case, we want main.cpp to know about (and use) the add() function that lives in add.cpp. To give main.cpp access to the add function, we can use a forward declaration:

main.cpp with forward declaration:

```
//#include "stdafx.h" // uncomment if using Visual Studio
#include <iostream>

int add(int x, int y); // needed so main.cpp knows that add() is a function declared elsewhere

int main()
{
    using namespace std;
    cout << "The sum of 3 and 4 is: " << add(3, 4) << endl;
    return 0;
}
```

Now, when the compiler is compiling main.cpp, it will know what add() is. Using this method, we can give files access to functions that live in another file.

Try compiling add.cpp and the main.cpp with the forward declaration for yourself. If you get a linker error, make sure you’ve added add.cpp to your project or compilation line properly.

## Something went wrong!

There are plenty of things that can go wrong the first time you try to work with multiple files. If you tried the above example and ran into an error, check the following:

A. If you get a compiler error about add() not being defined in main(), you probably forgot the forward declaration in main.

B. If you get a linker error about add not being defined, e.g.

```
unresolved external symbol "int __cdecl add(int,int)" (?add@@YAHHH@Z) referenced in function _main
```

  - a. …the most likely reason is that add.cpp is not added to your project correctly. If you’re using Visual Studio or Code::Blocks, you should see add.cpp listed in the Solution Explorer/project pane on the left side of the IDE. If you don’t, right click on your project, and add the file, then try compiling again. If you’re compiling on the command line, don’t forget to include both main.cpp and add.cpp in your compile command.

  - b. …it’s possible that you added add.cpp to the wrong project.

  - c. …it’s possible that the file is set to not compile or link. Check the file properties and ensure the file is configured to be compiled/linked. In Code::Blocks, compile and link are separate checkboxes that should be checked. In Visual Studio, there’s an “exclude from build” option that should be set to “no” or left blank.

C. If you’re using Visual Studio with precompiled headers, every code file needs to #include “stdafx.h”. This includes both main.cpp and add.cpp.

D. Do not #include “add.cpp” from main.cpp. This will cause the compiler to insert the contents of add.cpp directly into main.cpp instead of treating them as separate files. While it may compile and run for this simple example, you will encounter problems down the road using this method.

## Conclusion

We will begin working with multiple files a lot once we get into object-oriented programming, so now’s as good a time as any to make sure you understand how to add and compile multiple file projects.

Reminder: Whenever you create a new code (.cpp) file, you will need to add it to your project so that it gets compiled.
