
# 6.11 - References variables

So far, we've discussed two basic variable types:

- Normal variables, which hold values directly.
- Pointers, which hold the address of another value (or null) and can be dereferenced to retrieve the value at the address they point to.

References are the third basic type of variable that C++ supports.

## References

A **reference** is a type of C++ variable that acts as an alias to another variable. References are declared by using an ampersand(&) between the reference type and the variable name:

```
int value = 5;     // normal integer
int &ref = value;  // reference to variable value
```

In this context, the ampersand does not mean "address of", it means "reference to".

In most cases, references act identically to the variables they're referencing. Let's take a look at references in use:

```
int value = 5; // normal integer
int &ref = value; // reference to variable value
value = 6; // value is now 6
ref = 7; // value is now 7

cout << value; // prints 7
++ref;
cout << value; // prints 8
```

This code prints:
7
8

In the above example, ref and value are synonymous.

Using the address-of operator on a reference returns the address of the value being referenced:

```
cout << &value;   // prints 0012FF7C
cout << &ref;     // prints 0012FF7C
```

Note that you can’t initialize a non-const reference with a const object:

```
const int x = 5;
int &ref = x; // invalid, non-const reference to const object
```

Otherwise, you’d be able to change the value of x through ref, which would violate x’s const-ness.


## References are implicitly const

References are implicitly const. Like normal constant objects, references must be initialized:

```
int value = 5;
int &ref = value; // valid reference

int &invalidRef; // invalid, needs to reference something
```

References must always be initialized with a valid object. Unlike pointers, which can hold a null value, there is no such thing as a null reference.

Because references are implicitly const, a reference can not be “redirected” (assigned) to another variable. Consider the following snippet:

```
int value1 = 5;
int value2 = 6;

int &ref = value1; // okay, ref is now an alias for value1
ref = value2; // assigns 6 (the value of value2) to value1 -- does NOT change the reference!
```

Note that the second statement may not do what you might expect! Instead of reassigning ref to alias value2, it instead assigns the value from value2 to value1 (which ref is a reference of).


## Const references

Although references are implicitly const, it is possible to declare a const reference:

```
const int value = 5;
const int &ref = value; // ref is a const reference to value
```

A const reference treats the value it is referencing as const. This means it’s okay to initialize a const reference with a const value.

Much like a pointer to a const value, a const reference can reference a non-const variable. When accessed through a const reference, the value is considered const even if the original variable is not:

```
int value = 5;
const int &ref = value;

ref = 6; // illegal -- ref is const
value = 7; // okay, value is non-const
```


## Const references to literal values

You can assign const references to literal values, though there is typically not much need to do so:

```
const int &rnRef = 6;
```

## References as function parameters

Most often, references are used as function parameters because they allow us to pass a parameter to a function without making a copy of the value itself (we just copy the reference).|

In lesson 6.8 -- Pointers and arrays we talked about how passing a pointer argument to a function allows the function to dereference the pointer to modify the argument’s value directly.

References work similarly in this regard. A function that uses a reference parameter is able to modify the argument passed in:

```
#include <iostream>

// ref is a reference to the argument passed in, not a copy
void changeN(int &ref)
{
	ref = 6;
}

int main()
{
	int n = 5;

	std::cout << n << '\n';

	changeN(n); // note that this is a non-reference argument

	std::cout << n << '\n';
	return 0;
}
```

This program prints:

5
6


When argument n is passed to the function, the function parameter ref is set as a reference to argument n. This allows the function to change the value of n through ref! Note that n does not need to be a reference itself.

This is useful both when the function needs to change the value of an argument passed in, or when making a copy of the argument would be expensive (e.g. for a large struct).

References as function parameters can also be const. This allows us to access the argument without making a copy of it, while guaranteeing that the function will not change the value being referenced.

```
// ref is a const reference to the argument passed in, not a copy
void changeN(const int &ref)
{
	ref = 6; // not allowed, ref is const
}
```

To avoid making unnecessary, potentially expensive copies, variables that are not pointers and not fundamental data types (int, double, etc…) should be generally passed by (const) reference.

Rule: Pass non-pointer, non-fundamental data type variables by (const) reference.

We’ll talk about reference parameters in more detail in the next chapter (on functions).


## References as shortcuts

A secondary use of references is to provide easier access to nested data. Consider the following struct:

```
struct Something
{
    int value1;
    float value2;
};

struct Other
{
    Something something;
    int otherValue;
};

Other other;
```

Let’s say we needed to work with the value1 field of the Something struct of other. Normally, we’d access that member as other.something.value1. If there are many separate accesses to this member, the code can become messy. References allow you to more easily access the member:

```
int &ref = other.something.value1;
// ref can now be used in place of other.something.value1
```

The following two statements are thus identical:

```
other.something.value1 = 5;
ref = 5;
```

This can help keep your code cleaner and more readable.


## References vs pointers

References and pointers have an interesting relationship -- a reference acts like a const pointer that is implicitly dereferenced when accessed. Thus given the following:

```
int value = 5;
int *const ptr = &value;
int &ref = value;
```

*ptr and ref evaluate identically. As a result, the following two statements produce the same effect:

```
*ptr = 5;
ref = 5;
```

Similarly, a const reference acts just like a const pointer to a const value that is implicitly dereferenced.

Because references must be initialized to valid objects and can not be changed once set, references are generally much safer to use than pointers. However, they are also a bit more limited in functionality.

If a given task can be solved with either a reference or a pointer, the reference should generally be preferred. Pointers should only be used in situations where references are not sufficient (such as dynamically allocating memory).
