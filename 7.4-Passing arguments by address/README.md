
# 7.4-Passing arguments by address

There is one more way to pass variables to functions, and that is by address. **Passing an argument by address** involves passing the address of the argument variable rather than the argument variable itself. Because the argument is an address, the function parameter must be a pointer. The function can then dereference the pointer to access or change the value being pointed to.

Here is an example of a function that takes a parameter passed by address:

```
#include <iostream>

void foo(int *ptr)
{
    *ptr = 6;
}

int main()
{
    int value = 5;

    std::cout << "value = " << value << '\n';
    foo(&value);
    std::cout << "value = " << value << '\n';
    return 0;
}
```

The above snippet prints:

value = 5
value = 6
