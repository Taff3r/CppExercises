/*
 * Class Date, implementation.
 * The next() function in this implementation cannot handle leap years.
 */

#include "date.h"

#include <ctime>   /* for C routines time and localtime */
#include <iostream>
#include <utility> /* for swap */

using std::cout;

int Date::daysPerMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

Date::Date() {
	time_t timer = time(0); // time in seconds since 1970-01-01
	tm* locTime = localtime(&timer); // broken-down time
	year = 1900 + locTime->tm_year;
	month = 1 + locTime->tm_mon;
	day = locTime->tm_mday;
}

Date::Date(int y, int m, int d) {
    year = y;
    month = m;
    day = d;
}

int Date::get_year() const {
	return year;
}

int Date::get_month() const {
	return month;
}

int Date::get_day() const {
	return day;
}

void Date::next() {
    ++day;
    if(daysPerMonth[month - 1] < day) {
        day = 1;
        ++month;
        if (month > 12){
            month = 1;
            ++year;
        }
    }
}

void print(const Date& d) {
	cout << d.get_year() << "-";
	if (d.get_month() < 10) {
		cout << "0";
	}
	cout << d.get_month() << "-";
	if (d.get_day() < 10) {
		cout << "0";
	}
	cout << d.get_day();
}

bool operator<(const Date& d1, const Date& d2) {
	return (d1.get_year() < d2.get_year()) ||
	(d1.get_year() == d2.get_year() && d1.get_month() < d2.get_month()) ||
	(d1.get_year() == d2.get_year() && d1.get_month() == d2.get_month()
	 && d1.get_day() < d2.get_day());
}

int distance(const Date& d1, const Date& d2) {
    int year1 = d1.get_year();
    int month1 = d1.get_month();
    int day1 = d1.get_day();
    Date date1 = Date(year1, month1, day1);

    int year2 = d2.get_year();
    int month2 = d2.get_month();
    int day2 = d2.get_day();
    Date date2 = Date(year2, month2, day2);

    int distance = 0;
    if (date1 < date2){
        while (date1 < date2) {
            ++distance;
            date1.next();
        }
        return distance;

    } else {
        while (date2 < date1) {
            ++distance;
            date2.next();
        }
        return distance;
    }
}
