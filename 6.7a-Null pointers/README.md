# 6.7a - Null pointers

## Null values and null pointers

Just like normal variables, pointers are not initialized when they are instantiated. Unless a value is assigned, a pointer will point to some garbage address by default.

Besides memory addresses, there is one additional value that a pointer can hold: a null value. A **null value** is a special value that means the pointer is not pointing at anything. A pointer holding a null value is called a **null pointer**.

```
int *ptr(0);    // ptr is now a null pointer

int *ptr2;      // ptr2 is uninitialized
ptr2 = 0;       // ptr2 is now a null pointer
```

Because a null pointer evaluates to 0, it can be used inside a conditional to test whether the pointer is a null pointer or not:

```
#include <iostream>

int main(int argc, const char *argv[])
{
	int *ptr(0);

	if (ptr)
	{ std::cout << "ptr is pointing to a int value."; }
	else
	{ std::cout << "ptr is a null pointer."; }
}
```

Best practice: **Initialize your pointers to a null value if you’re not giving them another value.**

## Dereferencing null pointers

In the previous lesson, we noted that dereferencing a garbage pointer would lead to undefined results. Dereferencing a null pointer also results in undefined behavior. In most cases, it will crash your application.

## The NULL macro

C (but not C++) defines a special preprocessor macro called NULL that is #defined as the value 0. Even though this is not technically part of C++, its usage is common enough that it should work in every C++ compiler:

```
int *ptr(NULL);   // assign address 0 to ptr
```

However, because NULL is a preprocessor macro and because it’s technically not a part of C++, best practice in C++ is to avoid using it.

## nullptr in C++11

Note that the value of 0 isn't a pointer type, so assigning 0 to a pointer to denote that the pointer is a null pointer is a little inconsistent. In rare cases, when used as a literal argument, it can even cause problems because the compiler can’t tell whether we mean a null pointer or the integer 0:

```
doSomething(0);   // is 0 an integer argument or a null pointer argument? (It will assume integer)
```

To address these issues, C++11 introduces a new keyword called **nullptr**. nullptr is both a keyword and an rvalue constant, much like the boolean keywords true and false are.

Starting with C++11, this should be favored instead of 0 when we want a null pointer:

```
int *ptr = nullptr;  // note: ptr is still an integer pointer, just set a null value(0)
```

C++ will implicitly convert nullptr to any pointer type. So in the above example, nullptr is implicitly converted to an integer pointer, and then the value of nullptr (0) assigned to ptr.

This can also be used to call a function with a nullptr literal:

```
doSomething(nullptr); // the argument is definitely a null pointer (not an integer)
```

Best practice: **With C++11, use nullptr to initialize your pointers to a null value.**


## std::nullptr_t

C++11 also introduces a new type called std::nullptr_t (in header <cstddef>). std::nullptr_t can only hold one value: nullptr! While this may seem kind of silly, it's useful in one situation. If we want to write a function that accepts a nullptr argument, what type do we make the parameter? The answer is std::nullptr_t.

```
#include <iostream>
#include <cstddef> // for std::nullptr_t

void doSomething(std::nullptr_t ptr)
{
    std::cout << "in doSomething()\n";
}

int main()
{
    doSomething(nullptr); // call doSomething with an argument of type std::nullptr_t

    return 0;
}
```

You probably won’t ever need to use this, but it’s good to know, just in case.
