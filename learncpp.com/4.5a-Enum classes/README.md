
# 4.5a - Enum classes

Although enumerated types are distinct types in C++, they are not type safe, and in some cases will allow you to do things that don't make sense. Consider the following case:

```
#include <iostream>

int main(int argc, const char *argv[])
{
    enum Color
	{
	    RED,  // RED is placed in the same scope as Color
		BLUE
	};

	enum Fruit
	{
	    BANANA, // BANANA is placed in the same scope as Fruit
		APPLE
	};

	Color color = RED;  // Color and RED can be accessed in the same scope (no prefix needed)
	Fruit fruit = BANANA;  // Fruit and BANANA can be accessed in the same scope (no prefix needed)

	if (color == fruit) // The compiler will compare a and b as integers
	    std::cout << "color and fruit are equal\n";
    else
		std::cout << "color and fruit are not equal\n";

    return 0;
}
```

When C++ compares color and fruit, it implicitly converts color and fruit to integers, and compares the integers. Since color and fruit have both been set to enumerators that evaluate to value 0, this means that in the above example, color will equal fruit. This is definitely not as desired since color and fruit are from different enumerations and are not intended to be comparable! With standard enumerators, there's no way to prevent comparing enumerators from different enumerations.

```


#include <iostream>

int main(int argc, const char * argv[]) {
    enum class Color
    {
        RED,  // RED is placed in the same scope as Color
        BLUE
    };

    enum class Fruit
    {
        BANANA,  // BANANA is placed in the same scope as Fruit
        APPLE
    };

    Color color = Color::RED;  // note: RED is not directly accessable any more, we have to use Color::RED
    Fruit fruit = Fruit::BANANA;  // note: BANANA is not directly accessible any more, we have to use Fruit::BANANA

    if (color == fruit)    // compile error here, as the compiler doesn't known how to compare different types Color and Fruit
        std::cout << "color and fruit are equal\n";
    else
        std::cout << "color and fruit are not equal\n";

    return 0;
}

```

With normal enumerations, enumerators are placed in the same scope as the enumeration itself, so you can typically access enumerators directly (e.g. RED). However, with enum classes, the strong scoping rules mean that all enumerators are considered part of the enumeration, so you have to use a scope qualifier to access the enumerator (e.g. Color::RED). This helps keep name pollution and the potential for name conflicts down.

Because the enumerators are part of the enum class, there’s no need to prefix the enumerator names (e.g. it’s okay to use RED instead of COLOR_RED, since Color::COLOR_RED is redundant).

The strong typing rules means that each enum class is considered a unique type. This means that the compiler will not implicitly compare enumerators from different enumerations. If you try to do so, the compiler will throw an error, as shown in the example above.

However, note that you can still compare enumerators from within the same enum class (since they are of the same type):

```


#include <iostream>

int main(int argc, const char * argv[]) {
    enum class Color
    {
        RED,
        BLUE
    };

    Color color = Color::RED;

    if (color == Color::RED)  // it's okay
        std::cout << "The color is red!\n";
    else if (color == Color::BLUE)
        std::cout << "The color is blue!\n";

    return 0;
}
```

With enum classes, the compiler will no longer implicitly convert enumerator values to integers. This is mostly a good thing. However, there are occasionally cases where it is useful to be able to do so. In these  cases, you can explicitly convert an enum class enumerator to an integer by using a **static_cast** to int:

```
#include <iostream>

int main(int argc, const char * argv[]) {
    enum class Color
    {
        RED,
        BLUE
    };

    Color color = Color::RED;

    std::cout << color;  // won't work, because there's no implicit conversion to int
    std::cout << static_cast<int>(color);
    return 0;
}
```

If you're using a C++11 compiler, there's really to use normal enumerated types instead of enum classes.

Note that the class keyword, along with the static keyword, is one of the most overloaded keywords in the C++ language, and can have different meanings depending on context. Although enum classes use the class keyword, they aren't considered "classes" in the traditional C++ sense. We'll cover actual classes later.
