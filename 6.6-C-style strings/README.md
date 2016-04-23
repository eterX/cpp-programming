
# 6.6 - C style strings

In lesson 4.4b -- An introduction to std::string, we defined a string as a collection of sequential characters, such as “Hello, world!”. Strings are the primary way in which we work with text in C++, and std::string makes working with strings in C++ easy.

Modern C++ supports two different types of strings: std::string (as part of the standard library), and C-style strings (natively, as inherited from the C language). It turns out that std::string is implemented using C-style strings. In this lesson, we’ll take a closer look at C-style strings.

## C-style strings

A C-style string is simply an array of characters that uses a null terminator. A null terminator is a special character (‘\0’, ascii code 0) used to indicate the end of the string. More generically, A C-style string is called a **null-terminated string**.

To define a C-style string, simply declare a char array and initialize it with a string literal:

```
char mystring[] = "string";
```

Although “string” only has 6 letters, C++ automatically adds a null terminator to the end of the string for us (we don’t need to include it ourselves). Consequently, mystring is actually an array of length 7!

We can see the evidence of this in the following program, which prints out the length of the string, and then the ASCII values of all of the characters:


```
#include <iostream>

int main()
{
    char mystring[] = "string";
    std::cout << mystring << " has " << sizeof(mystring) << " characters.\n";
    for (int index = 0; index < sizeof(mystring); ++index)
        std::cout << static_cast<int>(mystring[index]) << " ";

    return 0;
}
```

This produces the result:

```
string has 7 characters.
115 116 114 105 110 103 0
```

That 0 is the ASCII code of the null terminator that has been appended to the end of the string.

When declaring strings in this manner, it is a good idea to use [] and let the compiler calculate the size of the array. That way if you change the string later, you won’t have to manually adjust the array size.

One important point to note is that C-style strings follow all the same rules as arrays. This means you can initialize the string upon creation, but you can not assign values to it using the assignment operator after that!

```
char mystring[] = "string"; // ok
mystring = "rope"; // not ok!
```

This would be the conceptual equivalent of the following nonsensical example:

```
int array[] = { 3, 5, 7, 9 }; // ok
array = 8; // what does this mean?
```

Since C-style strings are arrays, you can use the [] operator to change individual characters in the string:

```
#include <iostream>

int main()
{
    char mystring[] = "string";
    mystring[1] = 'p';
    std::cout << mystring;

    return 0;
}
```

This program prints:

```
spring
```

When printing a C-style string, std::cout prints characters until it encounters the null terminator. If you accidentally overwrite the null terminator in a string (e.g. by assigning something to mystring[6]), you’ll not only get all the characters in the string, but std::cout will just keep printing everything in adjacent memory slots until it happens to hit a 0!

Note that it’s fine if the array is larger than the string it contains:

```
#include <iostream>

int main()
{
    char name[20] = "Alex"; // only use 5 characters (4 letters + null terminator)
    std::cout << "My name is: " << name << '\n';

    return 0;
}
```

In this case, the string “Alex” will be printed, and std::cout will stop at the null terminator. The rest of the characters in the array are ignored.

## C-style strings and std::cin

There are many cases where we don’t know in advance how long our string is going to be. For example, consider the problem of writing a program where we need to ask the user to enter their name. How long is their name? We don’t know until they enter it!

In this case, we can declare an array larger than we need:

```
#include <iostream>

int main()
{
    char name[255]; // declare array large enough to hold 255 characters
    std::cout << "Enter your name: ";
    std::cin >> name;
    std::cout << "You entered: " << name << '\n';

    return 0;
}
```

In the above program, we’ve allocated an array of 255 characters to name, guessing that the user will not enter this many characters. Although this is commonly seen in C/C++ programming, it is poor programming practice, because nothing is stopping the user from entering more than 255 characters (either unintentionally, or maliciously).

The recommended way of reading strings using cin is as follows:

```
#include <iostream>
int main()
{
    char name[255]; // declare array large enough to hold 255 characters
    std::cout << "Enter your name: ";
    std::cin.getline(name, 255);
    std::cout << "You entered: " << name << '\n';

    return 0;
}
```

This call to cin.getline() will read up to 254 characters into name (leaving room for the null terminator!). Any excess characters will be discarded. In this way, we guarantee that we will not overflow the array!

## Manipulating C-style strings

C++ provides many functions to manipulate C-style strings as part of the <cstring> library. Here are a few of the most useful:

strcpy() allows you to copy a string to another string. More commonly, this is used to assign a value to a string:

```
char source[] = "Copy this!";
char dest[50];
strcpy(dest, source);
cout << dest; // prints "Copy this!"
```

However, strcpy() can easily cause array overflows if you’re not careful! In the following program, dest isn’t big enough to hold the entire string, so array overflow results.

```
char source[] = "Copy this!";
char dest[4]; // note that the size of dest is only 4 chars!
strcpy(dest, source); // overflow!
cout << dest;
```

It is better to use strncpy(), which takes a length parameter to prevent overflow:

```
char source[] = "Copy this!";
char dest[50];
strncpy(dest, source, 49); // copy at most 49 characters (indices 0-48)
dest[49] = 0; // ensures the last character is a null terminator
cout << dest; // prints "Copy this!"
```

Another useful function is the strlen() function, which returns the length of the C-style string (without the null terminator).

```
#include <iostream>
#include <cstring>

int main()
{
    char name[20] = "Alex"; // only use 5 characters (4 letters + null terminator)
    std::cout << "My name is: " << name << '\n';
    std::cout << name << " has " << strlen(name) << " letters.\n";
    std::cout << name << " has " << sizeof(name) << " characters in the array.\n";

    return 0;
}
```

The above example prints:

```
My name is: Alex
Alex has 4 letters.
Alex has 20 characters in the array.
```

Note the difference between strlen() and sizeof(). strlen() prints the number of characters before the null terminator, whereas sizeof() returns the size of the entire array, regardless of what’s in it.

Other useful functions:
- strcat() -- Appends one string to another (dangerous)
- strncat() -- Appends one string to another (with buffer length check)
- strcmp() -- Compare two strings (returns 0 if equal)
- strncmp() -- Compare two strings up to a specific number of characters (returns 0 if equal)

Here’s an example program using some of the concepts in this lesson:

```
#include <iostream>
#include <cstring>

int main()
{
    // Ask the user to enter a string
    char buffer[255];
    cout << "Enter a string: ";
    cin.getline(buffer, 255);

    int spacesFound = 0;
    // Loop through all of the characters the user entered
    for (int index = 0; index < strlen(buffer); ++index)
    {
        // If the current character is a space, count it
        if (buffer[index] == ' ')
            spacesFound++;
    }

    std::cout << "You typed " << spacesFound << " spaces!\n";

    return 0;
}
```

## Don't use C-style strings

It is important to know about C-style strings because they are used in a lot of code. However, now that we’ve explained how they work, we’re going to recommend that you avoid them altogether whenever possible! Unless you have a specific, compelling reason to use C-style strings, use std::string instead. std::string is easier, safer, and more flexible.

Rule: Use std::string instead of C-style string.
