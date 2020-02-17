#include <ctime>  // time and localtime
#include "date.h"
#include <iostream>
#include <string>

using std::istream;
using std::ostream;
using std::string;

int Date::daysPerMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

Date::Date() {
	time_t timer = time(0); // time in seconds since 1970-01-01
	tm* locTime = localtime(&timer); // broken-down time
	year = 1900 + locTime->tm_year;
	month = 1 + locTime->tm_mon;
	day = locTime->tm_mday;
}

Date::Date(int y, int m, int d) {
    // add checking?
    this->year = y;
    this->month= m;
    this->day = d;
}

int Date::getYear() const {
	return this->year;
}

int Date::getMonth() const {
	return this->month;
}

int Date::getDay() const {
	return this->day;
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

istream& operator>>(istream& in, Date& d){
    in.clear();
    string input;
    getline(in, input);
    int parts[3];
    // year
    try {
        int end = input.find_first_of('-');
        parts[0] = std::stoi(input.substr(0, end));
        // cut string and repeat
        input.erase(0, end + 1);
        end = input.find_first_of('-');
        parts[1] = std::stoi(input.substr(0, end));
        input.erase(0, end + 1);
        // day should be rest of input
        parts[2] = std::stoi(input);
    } catch (std::exception& e){
        in.setstate(std::ios::failbit);
        return in;
    }
    
    // check formatting
    if (parts[0] > 0 && parts[1] > 0 && parts[1] > 0){ // Positive dates
        if (parts[1] > 0 && parts[1] < 12){ // Valid month
            if (Date::daysPerMonth[parts[1] - 1] >= parts[2]){ // Check valid date
                d.year = parts[0];
                d.month= parts[1];
                d.day = parts[2];
                in.setstate(std::ios::goodbit);
                return in;
            }
        }
    }
    // if we get here the format was bad.
    in.setstate(std::ios::failbit);
    return in;
}

ostream& operator<<(ostream& out, Date& date){
    string formatted; 
    formatted += std::to_string(date.getYear());
    formatted += "-";
    if (date.getMonth() < 10) {
        formatted += "0";
        formatted += std::to_string(date.getMonth());
    } else {
        formatted += std::to_string(date.getMonth());
    }
    formatted += "-";
    if (date.getDay() < 10) {
        formatted += "0";
        formatted += std::to_string(date.getDay());
    } else {
        formatted += std::to_string(date.getDay());
    }
    out << formatted;
    return out;
}

