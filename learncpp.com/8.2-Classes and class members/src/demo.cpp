#include <iostream>

/*
 * warning: extended initializer lists only available
 * with -std=c++11 or -std=gnu++11 [enabled by default]
 *
 * $ g++ -std=c++11 demo.cpp
 * $ g++ -std=gnu++11 demo.cpp
 */

struct DateStruct
{
    int year;
    int month;
    int day;
};


class DateClass
{
public:
    int year;
    int month;
    int day;

    void print()
    {
        std::cout << year << "/" << month << "/" << day << "\n";
    }
};


void print(DateStruct &date)
{
    std::cout << date.year << "/" << date.month << "/" << date.day << "\n";
}

int main()
{
    DateStruct today { 2020, 10, 14 };
    // DateStruct today = { 2020, 10, 14 };
    today.day = 16;
    print(today);

    DateClass today_ { 2020, 10, 14 };
    // DateClass today_ = {2016, 10, 14};
    today_.day = 16;
    today_.print();

    return 0;
}
