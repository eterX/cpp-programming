#include <iostream>


class DateClass
{
    int m_month;
	int m_day;
	int m_year;
};


int main(int argc, const char *argv[])
{
	DateClass date;
	date.m_month = 10;  // 'm_month' is a private member of 'DateClass'
	date.m_day = 14;
    date.m_year = 2020;

    return 0;
}
