
# 6.14 - Pointers to pointers

This lesson is optional, for advanced readers who want to learn more about C++. Future lessons do not build on it.

A pointer to a pointer is exactly what you'd expect: a pointer that holds the address of another pointer.


## Pointers to pointers

A normal pointer to an int is declared using a single asterisk:

```
int *ptr;    // pointer to an int, one asterisk
```

A pointer to a pointer to an int is declared using two asterisks

```
int **ptrptr;   // pointer to a pointer to an int, two asterisks
```

A pointer to a pointer works just like a normal pointer — you can dereference it to retrieve the value pointed to. And because that value is itself a pointer, you can dereference it again to get to the underlying value. These dereferences can be done consecutively:

```
int value = 5;

int *ptr = &value;
std::cout << *ptr; // dereference pointer to int to get int value

int **ptrptr = &ptr;
std::cout << **ptrptr; // first dereference to get pointer to int, second dereference to get int value
```

The above program prints:
5
0x7fff5486954c
5

Note that you can not set a pointer to a pointer directly to a value:

```
int value = 5;
int **ptrptr = &&value;   // not valid
```

This is because the address of operator (operator&) requires an lvalue, but &value is an rvalue.

However, a pointer to a pointer can be set to null:

```
int **ptrptr = nullptr;  // use 0 instead prior to C++11
```

## Arrays of pointers

Pointers to pointers have a few uses. The most common use is to dynamically allocate an array of pointers:

```
int **array = new int *[10];    // allocate an array of 10 int pointers
```

This works just like a standard dynamically allocated array, except the array elements are of type "pointer to integer" instead of integer.

## Two-dimensional dynamically allocated arrays

Another common use for pointers to pointers is to facilitate dynamically allocated multidimensional arrays.

Unlike a two dimensional fixed array, which can easily be declared like this:

```
int array[0][5];
```

Dynamically allocating a two-dimensional array is a little more challenging. You may be tempted to try something like this:

```
int **array = new int[10][15];   // won't work !
```

But it won't work.

There are two possible solutions here. If the right-most array dimension is a compile-time constant, you can do this:

```
int (*array)[5] = new int[10][5];
```

The parenthesis are required here to ensure proper precedence. In C++ 11 or newer, this is a good place to use automatic type deduction:

```
auto array = new int[10][5];  // so much simpler !
```

Unfortunately, this relatively simple solution doesn't work if the right-most array dimension isn't a compile-time constant. In the case, we have to get a little more complicated. First, we allocate an array of pointers (as per above). Then we iterate through the array of pointers and allocate a dynamic array for each array element. Our dynamic two-dimensional array is a dynamic one-dimensional array of dynamic one-dimensional arrays!

```
int **array = new int*[10];  // allocate an array of 10 int pointers
for (int count=0; count < 10; ++count)
    array[count] = new int[5];  // these are our columns
```

We can then access our array like usual:

```
array[9][4] = 3;     // This is the same as (array[9])[4] = 3;
```

With this method, because each array column is be dynamically allocated independently, it's possible to make dynamically allocated two dimensional arrays that are not rectangular. For example, we can make a triangle-shaped array:

```
int **array = new int*[10];  // allocate an array of 10 int pointers - these are our rows
for (int count = 0; count < 10; ++count)
    array[count] = new int[count+1];     // these are our columns
```

In the above example, node that array[0] is an array of length 1, array[1] is an array of length 2, etc...

Deallocating a dynamically allocated two-dimensional array using method requires a loop as well:

```
for (int count=0; count < 10; ++count)
    delete[] array[count];
delete[] array;   // this needs to be done last
```

Note that we delete the array in the opposite order that we created it. If we delete array before the array elements, then we'd have to access deallocated memory to delete the array elements. And that would result in underined behavior.

Because allocating and deallocating two-dimensional arrays is complex and easy to mess up, it's often easier to "flattern" a two-dimensional array (of size x by y) into a one-dimensional array of size x * y:

```
// Instead of this:
int **array = new int*[10];   // allocate an array of 10 int pointers - these are our rows
for (int count = 0; count < 10; ++count)
    array[count] = new int[5];   // these are our columns

// Do this
int *array = new int[50];        // a 10x5 array flattened into a single array
```

Simple math can then be used to convert a row and column index for a rectangular two-dimensional array into a single index for a one-dimensional array:

```
int getSingleIndex(int row, int col, int numberOfColumnsInArray)
{
     return (row * numberOfColumnsInArray) + col;
}

// set array[9,4] to 3 using our flattened array
array[getSingleIndex(9, 4, 5)] = 3;
```

## Passing a pointer by address

Much like we can use a pointer parameter to change the actual value of the underlying argument passed in, we can pass a pointer to a pointer to a function and use that pointer to change the value of the pointer it points to (confused yet?)

However, if we want a function to be able to modify what a pointer argument points to, this is generally better done using a reference to a pointer instead. So we won't talk about it further here.

We'll talk more about pass by address and pass by reference in the next chapter.

## Pointer to a pointers to a pointer to...

It's also possible to declare a pointer to a pointer to a pointer:

```
int ***ptrx3;
```

These can be used to dynamically allocated a three-dimensional array. However, doing so would require a loop inside a loop, and are extremely complicated to get correct.

You can even declare a pointer to a pointer to a pointer:

```
int ****ptrx4;
```

Or higher, if you wish.

## Conclusion

We recommend avoiding using pointers to pointers unless no other options are available, because they're complicated to use and potentially dnagerous. It's easy enough to dereference a null or dangling pointer with normal pointers -- it's doubly easy with a pointer to a pointer since you have to do a double-dreference to get to the underlying value !
