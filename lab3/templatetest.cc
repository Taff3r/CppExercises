#include "date.h"
#include "template.h"
#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;

int main(){
    double x = 123.333;
    Date d;
    cout << toString(x) << endl;
    cout << toString(d) << " (The date is: <current day>)" << endl;
    double i = string_cast<double>("122.1");
    cout << i << " (122.1)" << endl;
    Date p = string_cast<Date>("2019-02-11");
    cout << p.getMonth() << "(2)" << endl;
    cout << toString(p) << " (The date is: 2019-02-11)" << endl;
}
