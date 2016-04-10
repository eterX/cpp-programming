# 2.4a - Fixed width integers and the unsigned controversy

In the previous lesson 2.4 -- Integers you learned that C++ only guarantees that integer variables will have a minimum size - but they could be larger, depending on the target system.

## Why isn't the size of the integer variables fixed?

The short, non-technical anwser is that this goes back to C, when performance was of utmost concern. C opted to intentionally leave the size of an integer open so that the compiler implementers could pick a size for int that performs best on the target computer architecture.

## Doesn't this suck ?

Yes! As a programmer, it's a little ridiculous to have to deal with variables whose size could vary depending on the target architecture.

## Fixed-width integers

To help with cross-platform portability, C99 defined a set of fixed-width integers (int the **stdint.h** header) that are guaranteed to have the same size on any architecture. These are defined as follows?

| **Name** |	**Type** | **Range** |
|:-:|:-:|:-:|
| int8_t	| 1 byte signed	| -128 to 127 |
| uint8_t	| 1 byte unsigned	| 0 to 255 |
| int16_t	| 2 byte signed	| -32,768 to 32,767 |
| uint16_t	| 2 byte unsigned	| 0 to 65,535 |
| int32_t	| 4 byte signed	| -2,147,483,648 to 2,147,483,647 |
| uint32_t	| 4 byte unsigned	| 0 to 4,294,967,295 |
| int64_t	| 8 byte signed	| -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807 |
| uint64_t	| 8 byte unsigned	| 0 to 18,446,744,073,709,551,615 |

C++ officaially adopted these fixed-width integers as part of C++11. They can be accessed by including the **cstdint** header. Here's an example:

```
#include <iostream>
#include <cstdint>

int main()
{
    int16_t i(5); // implicit assignment
    std::cout << i;
    return 0;
}
```

Even though these weren't adopted in C++ util C++11, because they were part of the C99 standard, some older C++ compilers offer access to these types, typicallly by including **stdint.h**. Visual Studio 2005 and 2008 do not incldue **stdint.h**, but 2010 does.

If you are using the boost library, boost provides these as part of <boost/cstdint.hpp>

If your compiler does not include **cstdint** or **stdint.h**, the good news is that you can download Paul Hsieh's **pstdint.h** cross-platform compatible version of the **stdint.h** header. Simply include the pstdint.h file in your project and it will define the fixed width integer types with the proper sizes for your platform.

**Warning: int8_t and uint8_t may or may not behave like chars**

Due to an oversight in the C++ specification, most compilers define and treat int8_t and uint8_t identically to types signed char and unsigned char respectively, but this is not required. Consequently, std::cin and std::cout may work differently than you’re expecting. We cover char types in more detail in section **2.7 -- Chars**.

Until this is clarified by a future draft of C++, you should assume that int8_t and uint8_t may or may not behave like char types.

## Integer best practices

Now that fixed-width integers have been added to C++, the best practice for integers in C++ is as follow:

  - int can be used when the integer size doesn't matter and isn't going to be large.
  - Fixed-width integers should be used in all other cases.
  - Only use unsigned types if you have a compelling reason.

Some compilers define their own version of fixed width integers -- for example, Visual Studio defines __int8, __int16, etc… You should avoid these like the plague.

## The controversy over unsigned numbers

Many developers (and some large development houses, such as Google) believe that developers should generally avoid unsigned integers. This is largely because unexpected behavior can result when you mix signed and unsigned integers.

Consider the following snippet:

```
void doSomething(unsigned int x)
{
    // Run some code x times
}

int main()
{
    doSomething(-1);
}
```

What happens in this case? -1 gets converted to some large number (probably 4294967295), and your program goes ballistic. But even worse, there's no good way to guard against this condition from happening. C++ will freely convert between signed and unsigned numbers, but it won't do any range checking to make sure you don't overflow your type.

Many modern programming language (such as Java and C#) either don't include unsigned types, or limit their use. Bjarne Stroustrup, the designer of C++, said, "Using an unsigned instead of an int to gain one more bit to represent positive integers is almost never a good idea".

This doesn’t mean you have to avoid unsigned types altogether -- but if you do use them, use them only where they really make sense, and take care not to mix signed and unsigned numbers.

Alex’s note: Most of this tutorial was written prior to these fixed-width integers being adopted into C++11, so we may use int in some examples where a fixed-width integer would be more appropriate.
