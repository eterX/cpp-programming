# 1.4B - Why functions are useful, and how to use them effectively

Now that we’ve covered what functions are and some of their basic capabilities, let’s take a closer look at why they’re useful.

## Why use functions ?

New programmers often ask, “can’t the code we’re putting inside the function just be put directly inside main?” In many cases (particularly for simple examples), it can. However, functions provide a number of benefits that make them extremely useful in non-trivial programs.

- Organization -- As programs grow in complexity, having all the code live inside the main() function becomes increasingly complicated. A function is almost like a mini-program that we can write separately from the main program, without having to think about the rest of the program while we write it. This allows us to divide complicated tasks into smaller, simpler ones, and drastically reduces the overall complexity of our program.
- Reusability -- Once a function is written, it can be called multiple times from within the program. This avoids duplicated code and minimizes the probability of copy/paste errors. Functions can also be shared with other programs, reducing the amount of code that has to be written from scratch (and retested) each time.
- Testing -- Because functions reduce code redundancy, there’s less code to test in the first place. Also because functions are self-contained, once we’ve tested a function to ensure it works, we don’t need to test it again unless we change it. This reduces the amount of code we have to test at one time, making it much easier to find bugs (or avoid them in the first place).
Extensibility -- When we need to extend our program to handle a case it didn’t handle before, functions allow us to make the change in one place and have that change take effect every time the function is called.
- Abstraction -- In order to use a function, you only need to know its name, inputs, outputs, and where it lives. You don’t need to know how it works, or what other code it’s dependent upon to use it. This is super-useful for making other people’s code accessible (such as everything in the standard library).

Although it doesn’t look like it, every time you use std::cin or std::cout to do input or output, you’re using a function provided by the standard library that meets all of the above criteria.


## Effectively using functions

One of the biggest challenges new programmers encounter (besides learning the language) is learning when and how to use functions effectively. Here are a few basic guidelines for writing functions:

- Code that appears more than once in a program should generally be made into a function. For example, if we’re reading input from the user multiple times in the same way, that’s a great candidate for a function. If we output something in the same way multiple times, that’s also a great candidate for a function.
- Code that has a discrete set of inputs and outputs is a good candidate for a function, particularly if it is complicated. For example, if we have a list of items that we want to sort, the code to do the sorting would make a great function, even if it’s only done once. The input is the unsorted list, and the output is the sorted list.
- A function should generally perform one (and only one) task.
- When a function becomes too long, too complicated, or hard to understand, it should be split into multiple sub-functions. This is called refactoring.


Typically, when learning C++, you will write a lot of programs that involve 3 subtasks:


1. Reading inputs from the user
2. Calculating a value from the inputs
3. Printing the calculated value

For trivial programs (e.g. less than 20 lines of code), some or all of these can be done in main(). However, for longer programs (or just for practice) each of these is a good candidate for an individual function.

New programmers often combine calculating a value and printing the calculated value into a single function. However, this violates the “one task” rule of thumb for functions. A function that calculates a value should return the value to the caller and let the caller decide what to do with the calculated value (such as call another function to print the value).
