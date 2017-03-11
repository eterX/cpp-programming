
# 4.x - Chapter 4 comprehensive quiz

## Quick review

We covered a lot of material in this chapter. Good job, you’re doing great!

**A block of statements** (aka. a compound statement) is treated by the compiler as if it were a single statement. These are placed between curly brackets ({ and }) and used pretty much everywhere.

**Local variables** are created when the block they are part of is entered, and destroyed when it is exited. They can only be accessed inside the block in which they are declared.

**Global variables** are created when the program starts, and are destroyed when it ends. They can be used anywhere in the program. Non-const global variables should generally be avoided because they are evil.

The **static** keyword can be used to give a global variable internal linkage, so it can only be used in the file in which it is declared. It can also be used to give a local variable static duration, which means the local variable retains its value, even after it goes out of scope.

**Namespaces** are an area in which all names are guaranteed to be unique. Use of namespace is a great way to avoid naming collisions. Avoid use of “using statements” outside of functions.

**Implicit type** conversion happens when one type is converted into another type without using a cast. Explicit type conversion happens when one type is converted to another using a cast. In some cases, this is totally safe, and in others, data may be lost. Avoid C-style casts and use static_cast instead.

**std::string** offers an easy way to deal with text strings. Strings are always placed between double quotes.

**Enumerated types** let us define our own type where all of the possible values are enumerated. These are great for categorizing things. Enum classes work like enums but offer more type safety, and should be used instead of standard enums if your compiler is C++11 capable.

**Typedefs** allow us to create an alias for a type’s name. Fixed width integers are implemented using typedefs. Typedefs are useful for giving simple names to complicated types.

And finally, structs offer us a way to group related variables into a single structure and access them using the member selection operator (.). Object-oriented programming builds heavily on top of these, so if you learn one thing from this chapter, make sure it’s this one.

Quiz time!

Yay.

1) In designing a game, we decide we want to have monsters, because everyone likes fighting monsters. Declare a struct that represents your monster. The monster should have a type that can be one of the following: an ogre, a dragon, an orc, a giant spider, or a slime. If you’re using C++11, use an enum class for this. If you’re using an older compiler, use an enumeration for this.

Each individual monster should also have a name, as well as an amount of health that represents how much damage they can take before they die. Write a function named printMonster() that prints out all of the struct’s members. Instantiate an ogre and a slime, initialize them using an initializer list, and pass them to printMonster().

Your program should produce the following output:

This Ogre is named Torg and has 145 health.
This Slime is named Blurp and has 23 health.
