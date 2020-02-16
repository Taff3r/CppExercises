#ifndef TEMPLATE_H
#define TEMPLATE_H

#include <string>
#include <sstream>
#include "date.h"

template <typename T>
std::string toString(T &t){
    std::stringstream s;
    s << t;
    return s.str();
}

std::string toString(Date &t){
    std::stringstream s;
    s << t;
    return "The date is: " + s.str();
}

template <typename R>
R string_cast(const std::string &s){
    std::stringstream ss;
    R r;
    ss << s;
    ss >> r; 
    return r;
}

#endif
