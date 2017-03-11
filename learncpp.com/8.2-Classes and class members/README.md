
# 8.2 - Classes and class members

While C++ provides a number of fundamental data types (e.g. char, int, long, float, double, etc...) that  are often sufficient for solving relatively simple problems, it can be difficult to solve complex problems using just these types. One of C++'s more useful features is the ability to define your own data types that better correspond to the problem being solved. You have already seen how **enumerated types** and **structs** can be used to create your own custom data types.

Here is an example of a struct used to hold a date:

```
struct DateStruct
{
    int year;
    int month;
    int day;
};
```

Enumerated types and data-only structs (structs that only contain variables) represent the traditional non-object-oriented programming world, as they can only hold data. In C++11, we can create and initialize this struct as follows:

```
DateStruct today {2020, 10, 14};
```

Now, if we want to print the date to the screen (something we probably want to do a lot), it makes sense to write a function to do this. Here’s a full program:

```
#include <iostream>

struct DateStruct
{
    int year;
    int month;
    int day;
};

void print(DateStruct &date)
{
    std::cout << date.year << "/" << date.month << "/" << date.day;
}

int main()
{
    DateStruct today { 2020, 10, 14 }; // use uniform initialization

    today.day = 16; // use member selection operator to select a member of the struct
    print(today);

    return 0;
}
```

This program prints:

```
2020/10/16
```

## Classes

In the world of object-oriented programming, we often want our types to not only hold data, but provide functions that work with the data as well. In C++, this is typically done via the class keyword. Using the **class** keyword defines a new user-defined type called a class.

In C++, classes are very much like data-only structs, except that classes provide much more power and flexibility. In fact, the following struct and class are effectively identical:

```
struct DateStruct
{
    int year;
    int month;
    int day;
};

class DateClass
{
public:
    int m_year;
    int m_month;
    int m_day;
};
```

Note that the only significant difference is the `public:` keyword in the class. We will discuss the function of this keyword in the next lesson.

Just like a struct declaration, a class declaration does not declare any memory. It only defines what the class looks like.

>
Warning: Just like with structs, one of the easiest mistakes to make in C++ is to forget the semicolon at the end of a class declaration. This will cause a compiler error on the next line of code. Modern compilers like Visual Studio 2010 will give you an indication that you may have forgotten a semicolon, but older or less sophisticated compilers may not, which can make the actual error hard to find.

Just like with a struct, to use a class, a variable of that class type must be declared:

```
DateClass today { 2020, 10, 14 }; // declare a variable of class DateClass
```

In C++, when we define a variable of a class, we call it **instantiating** the class. The variable itself is called an instance of the class. A variable of a class type is also called an **object**. Instantiating a variable allocates memory for the object.

## Member Functions

In addition to holding data, classes can also contain functions! Functions defined inside of a class are called **member functions**. Here is our Date class with a member function to print the date:

```
class DateClass
{
public:
    int m_year;
    int m_month;
    int m_day;

    void print() // defines a member function named print()
    {
        std::cout << m_year << "/" << m_month << "/" << m_day;
    }
};
```

Just like members of a struct, members (variables and functions) of a class are accessed using the member selector operator (.):

```
#include <iostream>

class DateClass
{
public:
    int m_year;
    int m_month;
    int m_day;

    void print()
    {
        std::cout << m_year << "/" << m_month << "/" << m_day;
    }
};

int main()
{
    DateClass today { 2020, 10, 14 };

    today.m_day = 16; // use member selection operator to select a member variable of the class
    today.print(); // use member selection operator to select a member function of the class

    return 0;
}
```

This prints:

```
2020/10/16
```

Note how similar this program is to the struct version we wrote above.

However, there are a few differences. In the struct version of print(), we needed to pass the struct itself to the print() function as the first parameter. Otherwise, print() wouldn’t know what DateStruct we wanted to work on.

However, in our class version of print(), we do not need to pass a DateClass to print()! Because print() is being called on class variable “today”, the member variables in print() will refer to the member variables of class variable today! Thus, inside the call to today.print(), m_day is actually referring to today.m_day. If we called tomorrow.print(), m_day inside of print() would refer to tomorrow.m_day.

Using the “m_” prefix for member variables helps distinguish member variables from function parameters or local variables inside member functions. This is useful for several reasons. First, when we see an assignment to a variable with the “m_” prefix, we know that we are changing the state of the class. Second, unlike function parameters or local variables, which are declared within the function, member variables are declared in the class definition. Consequently, if we want to know how a variable with the “m_” prefix is declared, we know that we should look in the class definition instead of within the function.

By convention, class names should begin with an upper-case letter.

Rule: Name your classes starting with a capital letter.

Here’s another example of a class:

```
#include <iostream>
#include <string>

class Employee
{
public:
    std::string m_name;
    int m_id;
    double m_wage;

    // Print employee information to the screen
    void print()
    {
        std::cout << "Name: " << m_name <<
                "  Id: " << m_id <<
                "  Wage: $" << m_wage << '\n';
    }
};

int main()
{
    // Declare two employees
    Employee alex { "Alex", 1, 25.00 };
    Employee joe { "Joe", 2, 22.25 };

    // Print out the employee information
    alex.print();
    joe.print();

    return 0;
}
```

This produces the output:

```
Name: Alex  Id: 1  Wage: $25
Name: Joe  Id: 2  Wage: $22.25
```

Unlike normal functions, the order in which member functions are defined doesn’t matter!


## A note about struts in C++

In C, structs can only hold data, and do not have associated member functions. In C++, after designing classes (using the class keyword), Bjarne Stroustrup spent some amount of time considering whether structs (which were inherited from C) should be granted the same capabilities. Upon consideration, he determined that they should, in part to have a unified ruleset for both. So although we wrote the above programs using the class keyword, we could have used the struct keyword instead.

Many developers (including myself) feel this was the incorrect decision to be made, as it can lead to dangerous assumptions: For example, it’s fair to assume a class will clean up after itself, but it’s not safe to assume a struct will. Consequently, we recommend using the struct keyword for data-only structures, and the class keyword for defining objects that that require both data and functions to be bundled together.

Rule: Use the struct keyword for data-only structures. Use the class keyword for objects that have both data and functions.

## Conclusion

The class keyword lets us create a custom type in C++ that can contain both member variables and member functions. Classes from the basis for Object-oriented programming, and we'll spend the rest of this chapter and many of the future chapters exploring all they have to offer!
