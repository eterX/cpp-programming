
## 6.x - Chapter 6 comprehensive quiz

## Words of enouragement

Congratulations on reaching the end of the longest chapter in the tutorials! Unless you have previous programming experience, this chapter was probably the most challenging one so far. If you made it this far, you’re doing great!

The good news is that the next chapter is easy in comparison. And in the chapter beyond that, we reach the heart of the tutorials: **Object-oriented programming**!


## Chapter summary

Arrays allow us to store and access many variables of the same type through a single identifier. Array elements can be accessed using the subscript operator ([]). Be careful not to index an array out of the array’s range. Arrays can be initialized using an initializer list or uniform initialization (in C++11).

Fix arrays must have a length that is set at compile time. Fix arrays will usually decay into a pointer when evaluated or passed to a function.

Loops can be used to iterate through an array. Beware of off-by-one errors, so you don’t iterate off the end of your array. For-each loops are useful when the array hasn’t decayed into a pointer.

Arrays can be made multidimensional by using two indexes.

Arrays can be used to do C-style strings. You should generally avoid these and use std::string instead.

Pointers are variables that store the memory address of (point at) another variable. The address-of operator (&) can be used to get the address of a variable. The dereference operator (*) can be used to get the value that a pointer points at.

A null pointer is a pointer that is not pointing at anything. Pointers can be made null by initializing or assigning the value 0 (or in C++11, nullptr) to them. Avoid the NULL macro. Dereferencing a null pointer can cause bad things to happen. Deleting a null pointer is okay (it doesn’t do anything).

A pointer to an array doesn’t know how large the array they are pointing to is. This means sizeof() and for-each loops won’t work.

The new and delete operators can be used to dynamically allocate memory for a pointer variable or array. Although it’s unlikely to happen, operator new can fail if the operating system runs out of memory, so make sure to check whether new returned a null pointer.

Make sure to use the array delete (delete[]) when deleting an array. Pointers pointing to deallocated memory are called dangling pointers. Dereferencing a dangling pointer can cause bad things to happen.

Failing to delete dynamically allocated memory can result in memory leaks when the last pointer to that memory goes out of scope.

Normal variables are allocated from limited memory called the **stack**. Dynamically allocated variables are allocated from a general pool of memory called the **heap**.

A pointer to a const value treats the value it is pointing to as const.

```
int value = 5;
const int *ptr = &value;  // this is okay, ptr is pointing to a "const int"
```

A const pointer is a pointer whose value can not be changed after initialization.

```
int value = 5;
int *const ptr = &value;
```

A reference is an alias to another variable. References are declared using an ampersand, but this does not mean address-of in this context. References are implicitly const -- they must be initialized with a value, and a new value can not be assigned to them. References can be used to prevent copies from being made when passing data to or from a function.

The member selection operator (->) can be used to select a member from a pointer to a struct. It combines both a dereference and normal member access (.).

Void pointers are pointers that can point to any type of data. They can not be dereferenced directly. You can use static_cast to convert them back to their original pointer type. It’s up to you to remember what type they originally were.

Pointers to pointers allow us to create a pointer that points to another pointer.

**std::array** provides all of the functionality of C++ built-in arrays (and more) in a form that won’t decay into a pointer. These should generally be preferred over built-in fixed arrays.

**std::vector** provides dynamic array functionality that handles its own memory management and remember their size. These should generally be favored over built-in dynamic arrays.

## Quiz time

1) Pretend you’re writing a game where the player can hold 3 types of items: health potions, torches, and arrows. Create an enum to identify the different types of items, and a fixed array to store the number of each item the player is carrying (use built-in fixed arrays, not std::array). The player should start with 2 health potions, 5 torches, and 10 arrows. Write a function called countTotalItems() that returns how many items the player has in total. Have your main() function print the output of countTotalItems().
