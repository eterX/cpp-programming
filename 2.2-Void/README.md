
# 2.2 - Void

Void is the easiest of the data types to explain. Basically, it means "no types"!

Void is typically used in serval different contexts:

1) As a way to indicate that a function does not return a value:

```
void writeValue(int x) // void here means no return value
{
    std::cout << "The value of x is: " << x << std::endl;
    // no return statement, because the return type is void
}
```

2) As a way to indicate that a function does not take any parameters:

```
int getValue(void) // void here means no parameters
{
    int x;
    std::cin >> x;
    return x;
}
```

The explicit use of keyword void to mean "no parameters" is a holdover from C, and is not required in C++. The following code is equivalent, and preferred in C++:

```
int getValue() // empty function parameters is an implicit void
{
    int x;
    std::cin >> x;
    return x;
}
```

Because void means no type, note that you can not declare variables of type void:

```
void myVariable; // compiler error!
```

For future reference, the void keyword has a third (more advanced) use in C++ that we cover in section 6.13 -- Void pointers. Since we haven’t covered what a pointer is yet, you don’t need to worry about this case for now.
