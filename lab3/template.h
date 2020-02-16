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

#endif
