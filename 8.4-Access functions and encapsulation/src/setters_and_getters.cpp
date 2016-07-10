
#include <iostream>

class DateClass
{
private:
    int month;
    int day;
    int year;

public:
  void setMonth(int m) {month = m;}  // setters
  int getMonth() {return month;}     // getters

  void setDay(int d) {day = d;}
  int getDay() {return day;}

  void setYear(int y) {year = y;}
  int getYear() {return year;};
};


int main(int argc, const char *argv[])
{
    DateClass date;
    date.setMonth(7);
    date.setDay(10);
    date.setYear(2020);

    std::cout << date.getMonth() << std::endl;
    std::cout << date.getDay() << std::endl;
    std::cout << date.getYear() << std::endl;

    return 0;
}
