
# 5.9 - Random number generation

The ability to generate random numbers can be useful in certain kinds of programs, particularly in games, statistics modeling programs, and scientific simulations that need to model random events. Take games for example -- without random events, monsters would always attack you the same way, you’d always find the same treasure, the dungeon layout would never change, etc… and that would not make for a very good game.

So how do we generate random numbers? In real life, we often generate random results by doing things like flipping a coin, rolling a dice, or shuffling a deck of cards. These events involve so many physical variables (e.g. gravity, friction, air resistance, momentum, etc…) that they become almost impossible to predict or control, and produce results that are for all intents and purposes random.

However, computers aren’t designed to take advantage of physical variables -- your computer can’t toss a coin, throw a dice, or shuffle real cards. Computers live in a controlled electrical world where everything is binary (false or true) and there is no in-between. By their very nature, computers are designed to produce results that are as predictable as possible. When you tell the computer to calculate 2 + 2, you always want the answer to be 4. Not 3 or 5 on occasion.

Consequently, computers are generally incapable of generating random numbers. Instead, they must simulate randomness, which is most often done using pseudo-random number generators.

A **pseudo-random number generator (PRNG)** is a program that takes a starting number (called a **seed**), and performs mathematical operations on it to transform it into some other number that appears to be unrelated to the seed. It then takes that generated number and performs the same mathematical operation on it to transform it into a new number that appears unrelated to the number it was generated from. By continually applying the algorithm to the last generated number, it can generate a series of new numbers that will appear to be random if the algorithm is complex enough.

It’s actually fairly easy to write a PRNG. Here’s a short program that generates 100 pseudo-random numbers:

```
#include <iostream>

unsigned int PRNG()
{
    // our initial starting seed is 5323
    static unsigned int seed = 5323;

    // Take the current seed and generate a new value from it
    // Due to our use of large constants and overflow, it would be
    // very hard for someone to predict what the next number is
    // going to be from the previous one.
    seed = (8253729 * seed + 2396403);

    // Take the seed and return a value between 0 and 32767
    return seed  % 32768;
}

int main()
{
    // Print 100 random numbers
    for (int count=0; count < 100; ++count)
    {
        std::cout << PRNG() << "\t";

        // If we've printed 5 numbers, start a new row
        if ((count+1) % 5 == 0)
            std::cout << "\n";
	}
}
```

The result of this program is:

```
23070	27857	22756	10839	27946
11613	30448	21987	22070	1001
27388	5999	5442	28789	13576
28411	10830	29441	21780	23687
5466	2957	19232	24595	22118
14873	5932	31135	28018	32421
14648	10539	23166	22833	12612
28343	7562	18877	32592	19011
13974	20553	9052	15311	9634
27861	7528	17243	27310	8033
28020	24807	1466	26605	4992
5235	30406	18041	3980	24063
15826	15109	24984	15755	23262
17809	2468	13079	19946	26141
1968	16035	5878	7337	23484
24623	13826	26933	1480	6075
11022	19393	1492	25927	30234
17485	23520	18643	5926	21209
2028	16991	3634	30565	2552
20971	23358	12785	25092	30583
```

Each number appears to be pretty random with respect to the previous one. As it turns out, our algorithm actually isn’t very good, for reasons we will discuss later. But it does effectively illustrate the principle of PRNG number generation.

## Generating random numbers in C++

C (and by extension C++) comes with a built-in pseudo-random number generator. It is implemented as two separate functions that live in the cstdlib header:

- **srand()**, sets the initial seed value to a value that is passed in by the caller. **srand()** should only be called once.
- **rand()**, generates the next random in the sequence. That number will be a pseudo-random integer between 0 and RAND_MAX, a constant in cstdlib that is typically set to 32767.

Here's a sample program using these functions:

```
#include <iostream>
#include <cstdlib> // for rand() and srand()

int main()
{
    srand(5323); // set initial seed value to 5323

    // Print 100 random numbers
    for (int count=0; count < 100; ++count)
    {
        std::cout << rand() << "\t";

        // If we've printed 5 numbers, start a new row
        if ((count+1) % 5 == 0)
            std::cout << "\n";
	}
}
```

Here's the output of this program:

```
89463661	377197527	187110345	847509207	1975695145
1116152101	898704962	1281806983	1921500224	795181182
819390593	1832551987	490780235	58721518	1237559053
1275882576	1134239537	2099047587	1978925440	1720628991
596661235	1484228802	263431662	1532146767	314301792
1807930171	1136262594	1740828234	782922110	939597601
1369623616	386901919	80069517	1403609197	351911684
409709150	1149111768	801047305	627072092	1498394415
2121688183	247333246	1549008577	242901058	71668859
1947670893	411467430	635752670	1363980865	38466330
111030563	2074866745	1445923229	706760351	789167700
682530028	1572021969	481923942	1534860357	824452335
1005903901	1235594923	477004371	456009146	1924064326
940370556	1475776419	2085634930	2038182176	1216178735
566646999	1693621395	1946528427	537394191	1815432502
526404538	1795928173	1282145026	1160537984	1715415034
1012515463	686967813	995946819	1390642215	1459177204
128018888	1982319969	790419425	245435633	1868081591
636380797	1183493119	975312519	334829282	1068587434
343263377	1086501397	775528938	1236607323	312541995
```

## PRNG sequences and seeding

If you run the rand() sample program above multiple times, you will note that it prints the same result every time! This means that while each number in the sequence is seemingly random with regards to the previous ones, the entire sequence is not random at all! And that means our program ends up totally predictable (the same inputs lead to the same outputs every time). There are cases where this can be useful or even desired (e.g. you want a scientific simulation to be repeatable, or you’re trying to debug why your random dungeon generator crashes).

But often, this is not what is desired. If you’re writing a game of hi-lo (where the user has 10 tries to guess a number, and the computer tells them whether their guess is too high or too low), you don’t want the program picking the same numbers each time. So let’s take a deeper look at why this is happening, and how we can fix it.

Remember that each number in a PRNG sequence is generated from the previous number, in a deterministic way. Thus, given any starting seed number, PRNGs will always generate the same sequence of numbers from that seed as a result! We are getting the same sequence because our starting seed number is always 5323.

In order to make our entire sequence randomized, we need some way to pick a seed that’s not a fixed number. The first answer that probably comes to mind is that we need a random number! That’s a good thought, but if we need a random number to generate random numbers, then we’re in a catch-22. It turns out, we really don’t need our seed to be a random number -- we just need to pick something that changes each time the program is run. Then we can use our PRNG to generate a unique sequence of pseudo-random numbers from that seed.

The commonly accepted method for doing this is to enlist the system clock. Each time the user runs the program, the time will be different. If we use this time value as our seed, then our program will generate a different sequence of numbers each time it is run!

C comes with a function called **time()** that returns the number of seconds since midnight on Jan 1, 1970. To use it, we merely need to include the ctime header, and then initialize srand() with a call to time(0).

Here’s the same program as above, using a call to time() as the seed:

```
#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime> // for time()

int main()
{
    srand(static_cast<unsigned int>(time(0))); // set initial seed value to system clock

    for (int count=0; count < 100; ++count)
    {
        std::cout << rand() << "\t";

        // If we've printed 5 numbers, start a new row
        if ((count+1) % 5 == 0)
            std::cout << "\n";
	}
}
```

Now our program will generate a different sequence of random numbers every time! Run it a couple of times and see for yourself.

## Generating random numbers between a given range

Generally, we do not want random numbers between 0 and RAND_MAX -- we want numbers between two other values, which we’ll call min and max. For example, if we’re trying to simulate the user rolling a die, we want random numbers between 1 and 6.

Here’s a short function that converts the result of rand() into the range we want:

```
// Generate a random number between min and max (inclusive)
// Assumes srand() has already been called

int getRandomNumber(int min, int max)
{
    static_cast double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    // static used for efficiency, so we only calculate this value once
    // evenly distribute the random number across our range

    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}
```

To simulate the roll of a die, we’d call getRandomNumber(1, 6).

## What is a good PRNG?

As I mentioned above, the PRNG we wrote isn’t a very good one. This section will discuss the reasons why. It is optional reading because it’s not strictly related to C or C++, but if you like programming you will probably find it interesting anyway.

In order to be a good PRNG, the PRNG needs to exhibit a number of properties:

**First**, the PRNG should generate each number with approximately the same probability. This is called distribution uniformity. If some numbers are generated more often than others, the result of the program that uses the PRNG will be biased!

For example, let’s say you’re trying to write a random item generator for a game. You’ll pick a random number between 1 and 10, and if the result is a 10, the monster will drop a powerful item instead of a common one. You would expect a 1 in 10 chance of this happening. But if the underlying PRNG is not uniform, and generates a lot more 10s than it should, your players will end up getting more rare items than you’d intended, possibly trivializing the difficulty of your game.

Generating PRNGs that produce uniform results is difficult, and it’s one of the main reasons the PRNG we wrote at the top of this lesson isn’t a very good PRNG.

**Second**, the method by which the next number in the sequence is generated shouldn’t be obvious or predictable. For example, consider the following PRNG algorithm: num = num + 1. This PRNG is perfectly uniform, but it’s not very useful as a sequence of random numbers!

Third, the PRNG should have a good dimensional distribution of numbers. This means it should return low numbers, middle numbers, and high numbers seemingly at random. A PRNG that returned all low numbers, then all high numbers may be uniform and non-predictable, but it’s still going to lead to biased results, particularly if the number of random numbers you actually use is small.

Fourth, all PRNGs are periodic, which means that at some point the sequence of numbers generated will eventually begin to repeat itself. As mentioned before, PRNGs are deterministic, and given an input number, a PRNG will produce the same output number every time. Consider what happens when a PRNG generates a number it has previously generated. From that point forward, it will begin to duplicate the sequence between the first occurrence of that number and the next occurrence of that number over and over. The length of this sequence is known as the period.

For example, here are the first 100 numbers generated from a PRNG with poor periodicity:

```
112	9	130	97	64
31	152	119	86	53
20	141	108	75	42
9	130	97	64	31
152	119	86	53	20
141	108	75	42	9
130	97	64	31	152
119	86	53	20	141
108	75	42	9	130
97	64	31	152	119
86	53	20	141	108
75	42	9	130	97
64	31	152	119	86
53	20	141	108	75
42	9	130	97	64
31	152	119	86	53
20	141	108	75	42
9	130	97	64	31
152	119	86	53	20
141	108	75	42	9
```

You will note that it generated 9 as the second number, and 9 again as the 16th number. The PRNG gets stuck generating the sequence in-between these two 9’s repeatedly: 9-130-97-64-31-152-119-86-53-20-141-108-75-42-(repeat).

A good PRNG should have a long period for all seed numbers. Designing an algorithm that meets this property can be extremely difficult -- most PRNGs will have long periods for some seeds and short periods for others. If the user happens to pick a seed that has a short period, then the PRNG won’t be doing a good job.

Despite the difficulty in designing algorithms that meet all of these criteria, a lot of research has been done in this area because of its importance to scientific computing.


## rand() is a mediocre PRNG

The algorithm used to implement rand() can vary from compiler to compiler, leading to results that may not be consistent across compilers. Most implementations of rand() use a method called a **Linear Congruential Generator (LCG)**. If you have a look at the first example in this lesson, you’ll note that it’s actually a LCG, though one with intentionally picked poor constants. LCGs tend to have shortcomings that make them not good choices for most kinds of problems.

One of the main shortcomings of rand() is that RAND_MAX is usually set to 32767 (essentially 15-bits). This means if you want to generate numbers over a larger range (e.g. 32-bit integers), rand() is not suitable. Also, rand() isn’t good if you want to generate random floating point numbers (e.g. between 0.0 and 1.0), which is often useful when doing statistical modelling. Finally, rand() tends to have a relatively short period compared to other algorithms.

That said, rand() is perfectly suitable for learning how to program, and for programs in which a high-quality PRNG is not a necessity.

For applications where a high-quality PRNG is useful, I would recommend Mersenne Twister, which produces great results and is relatively easy to use.

  - **A note for Visual Studio users**

  The implementation of rand() in Visual Studio has a flaw -- the first random number generated doesn’t change much for similar seed values. This means that when using time() to seed your random number generator, the first result from rand() won’t change much in successive runs. This problem is compounded by calling getRandomNumber(), which compresses similar inputs into the same output number.

However, there’s an easy fix: call rand() once and discard the result. Then you can use rand() as normal in your program.


## Random numbers in C++

C++11 added a ton of random number generation functionality to the C++ standard library, including the Mersenne Twister algorithm, as well as generators for different kinds of random distributions (uniform, normal, Poisson, etc…). This is accessed via the <random> header.

Here’s a short example showing how to generate random numbers in C++11 using Mersenne Twister:

```
#include <iostream>
// #include <ctime> // uncomment if using Code::Blocks
#include <random> // for std::random_device and std::mt19937

int main()
{
    std::random_device rd; // Use a hardware entropy source if available, otherwise use PRNG
    std::mt19937 mersenne(rd()); // initialize our mersenne twister with a random seed

    // Note: Due to a bug in the Code::Blocks compiler, if using Code::Blocks on Windows, delete the two lines above and uncomment this line:
    // std::mt19937 mersenne(static_cast<unsigned int>(time(0))); // initialize our mersenne twister with a random seed

    // Print a bunch of random numbers
    for (int count = 0; count < 48; ++count)
    {
        std::cout << mersenne() << "\t";

        // If we've printed 4 numbers, start a new row
        if ((count + 1) % 4 == 0)
            std::cout << "\n";
    }
}
```

You’ll note that Mersenne Twister generates random 32-bit unsigned integers (not 15-bit integers like rand()), giving a lot more range. There’s also a version (std::mt19937_64) for generating 64-bit unsigned integers!

There’s so much functionality in <random> that it really warrants its own section. We’ll look to cover that in a future lesson in more detail.
