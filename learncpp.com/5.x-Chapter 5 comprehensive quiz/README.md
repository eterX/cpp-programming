
# 5.x - Chapter 5 comprehensive quiz

## Quick review

**If statements** allow us to execute a statement based on whether some condition is true. **Else statements** execute if the associated if statement is false. You can chain together multiple if and else statements.

**Switch statement** provide a cleaner and faster method for selecting between a number of discrete items. Switch statements pair great with enumerations.

**Goto statement** allow the program to jump to somewhere else in the code. Don't use these.

**While loop** allow the program to loop as long as a given condition is true. The condition is evaluated before the loop executes.

**Do while loops** are the same as while loops, but the condition is evaluated after the loop execution. They're great for menus or things that need to execute at least once.

**For loops** are the most used loop, and are perfect when you need to a loop a specific number of times.

**Break statements** allow us to break out of a switch, while, do while, or for loop. Or a for each loop, which we haven’t covered yet.

**Continue statements** to move immediately to the next loop iteration. Be careful when using these with while and do while loops, as your loop counter may not get incremented properly.

And finally, random numbers give us a way to make our programs behave different each time they are run. We’ll see an example of this in the quiz below!

## Quiz time!

Warning: The quizzes start getting harder from this point forward, but you can do it. Let’s rock these quizzes!

1) In the chapter 2 comprehensive quiz, we wrote a program to simulate a ball falling off of a tower. Because we didn’t have loops yet, the ball could only fall for 5 seconds.

Take the program below and modify it so that the ball falls for as many seconds as needed until it reaches the ground.

In constants.h:

```
#ifndef CONSTANTS_H
#define CONSTANTS_H

namespace myConstants
{
    const double gravity(9.8); // in meters/second squared
}
#endif
```

In your main code file:

```
#include <iostream>
#include "constants.h"

// gets initial height from user and returns it
double getInitialHeight()
{
	std::cout << "Enter the height of the tower in meters: ";
	double initialHeight;
	std::cin >> initialHeight;
	return initialHeight;
}

// Returns height from ground after "seconds" seconds
double calculateHeight(double initialHeight, int seconds)
{
	// Using formula: [ s = u * t + (a * t^2) / 2 ], here u(initial velocity) = 0
	double distanceFallen = (myConstants::gravity * seconds * seconds) / 2;
	double currentHeight = initialHeight - distanceFallen;

	return currentHeight;
}

// Prints height every second till ball has reached the ground
void printHeight(double height, int seconds)
{
	if (height > 0.0)
	{
		std::cout << "At " << seconds << " seconds, the ball is at height:\t" << height <<
			" meters\n";
	}
	else
		std::cout << "At " << seconds << " seconds, the ball is on the ground.\n";
}

void calculateAndPrintHeight(double initialHeight, int seconds)
{
	double height = calculateHeight(initialHeight, seconds);
	printHeight(height, seconds);
}

int main()
{
	const double initialHeight = getInitialHeight();

	calculateAndPrintHeight(initialHeight, 0);
	calculateAndPrintHeight(initialHeight, 1);
	calculateAndPrintHeight(initialHeight, 2);
	calculateAndPrintHeight(initialHeight, 3);
	calculateAndPrintHeight(initialHeight, 4);
	calculateAndPrintHeight(initialHeight, 5);

	return 0;
}
```

2) Implement a game of hi-lo. First, your program should pick a random integer between 1 and 100. The user is given 7 tries to guess the number. If the user does not guess the correct number, the program should tell them whether they guessed too high or too low. If the user guesses the right number, the program should tell them they won. If they run out of guesses, the program should tell them they lost, and what the correct number is. At the end of the game, the user should be asked if they want to play again. If the user doesn’t enter ‘y’ or ‘n’, ask them again.

Here’s what your output should look like:

```
Let's play a game.  I'm thinking of a number.  You have 7 tries to guess what it is.
Guess #1: 64
Your guess is too high.
Guess #2: 32
Your guess is too low.
Guess #3: 54
Your guess is too high.
Guess #4: 51
Correct! You win!
Would you like to play again (y/n)? y
Let's play a game.  I'm thinking of a number.  You have 7 tries to guess what it is.
Guess #1: 64
Your guess is too high.
Guess #2: 32
Your guess is too low.
Guess #3: 54
Your guess is too high.
Guess #4: 51
Your guess is too high.
Guess #5: 36
Your guess is too low.
Guess #6: 45
Your guess is too low.
Guess #7: 48
Your guess is too low.
Sorry, you lose.  The correct number was 49.
Would you like to play again (y/n)? q
Would you like to play again (y/n)? f
Would you like to play again (y/n)? n
Thank you for playing.
```

Hints:
* Seed your random number generator with time(0).
* Visual Studio users: Due to a flaw in the Visual Studio implementation of rand(), call rand() once after seeding to discard the first result.
* Use the getRandomNumber() function from lesson 5.9 -- Random number generation to pick a random number.
* Write a function that allows the user to play a single game of hi-lo.
* Write a function that asks the user if they want to play again and handles the looping logic for an incorrect input.
