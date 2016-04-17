
# 5.6 - Do while statements

One interesting thing about the while loop is that if the loop condition is initially false, the while loop will not execute at all. It is sometimes the case that we know we want a loop to execute at least once, such as when displaying a menu. To help facilitate this, C++ offers the do-while loop:

```
do
    statement;
while (condition);    
```

The statement in a do-while loop always executes at least once. After the statement has been executed, the do-while loop checks the condition. If the condition is true, the CPU jumps back to the top of the do-while loop and executes it again.

Here is an example of using a do-while loop to display a menu to the user and wait for the user to make a valid choice:

```
#include <iostream>

int main()
{
    // selection must be declared outside do/while loop
    int selection;

    do
    {
        std::cout << "Please make a selection: \n";
        std::cout << "1) Addition\n";
        std::cout << "2) Subtraction\n";
        std::cout << "3) Multiplication\n";
        std::cout << "4) Division\n";
        std::cin >> selection;
    }
    while (selection != 1 && selection != 2 &&
        selection != 3 && selection != 4);

    // do something with selection here
    // such as a switch statement

    std::cout << "You selected option #" << selection << "\n";

    return 0;
}
```

One interesting thing about the above example is that the selection variable must be declared outside of the do block. Why do you think that is?

If the selection variable were to be declared inside the do block, it would be destroyed when the do block terminates, which happens before the while conditional is executed. But we need the variable to use in the while conditional -- consequently, the selection variable must be declared outside the do block.

Generally it is good form to use a do-while loop instead of a while loop when you intentionally want the loop to execute at least once, as it makes this assumption explicit -- however, it’s not that big of a deal either way.
