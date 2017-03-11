## Pass by value

By default, arguments in C++ are passed by value. When an argument is **passed by value**, the argument's value is copied into the function's parameter.

Consider the following snippet:

```
void foo(int y)
{
    using namespace std;
    cout << "y = " << y << endl;
}

int main()
{
    foo(5); // first call

    int x = 6;
    foo(x); // second call
    foo(x+1); // third call

    return 0;
}
```

In the first call to foo(), the argument is the literal 5. When foo() is called, variable y is created, and the value of 5 is copied into y. Variable y is then destroyed when foo() ends.

In the second call to foo(), the argument is the variable x. x is evaluated to produce the value 6. When foo() is called for the second time, variable y is created again, and the value of 6 is copied into y. Variable y is then destroyed when foo() ends.

In the third call to foo(), the argument is the expression x+1. x+1 is evaluated to produce the value 7, which is passed to variable y. Variable y is once again destroyed when foo() ends.

Thus, this program prints:

y = 5
y = 6
y = 7

At the start of main, x is 5. When foo() is called. the value of x(5) is passed to foo's parameter y. Inside foo(), y is assigned the value of 6, and then destroyed. The value of x is unchanged, even through y was changed.

**Summary**

Advantages of passing by value:

  - Arguments passed by value can be variables (e.g. X), literals (e.g. 6), expressions (e.g. x+1), struts & classes, and enumerators.
  - Arguments are never changed by the function being called, which prevents side effects.

Disadvantages of passing by value:

  - Copying struts and classes can incur a significant performance penalty, especially if the function is called many times.

When to use pass by value:
  - When passing fundamental data type and enumerators.

When not to use pass by value:
  - When passing arrays, struts, or classes.

In most cases, pass by value is the best way to pass arguments to functions -- it is flexible and safe.

  
