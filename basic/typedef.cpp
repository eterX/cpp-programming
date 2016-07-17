// Copyright[2016] <Vex Woo>

#include <iostream>


/*
In C++, there are two syntaxes for creating such type aliases:

 - The first, inherited from the C language, uses the [typedef] keyword.
*/

typedef int set_score;


int main(int argc, const char* argv[]) {
    const set_score jim_score = 99;
    std::cout << "Jim's score is " << jim_score << "\n";
    return 0;
}
