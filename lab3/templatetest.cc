#include "template.h"
#include "date.h"
#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;

int main(){
    double x = 123.333;
    Date d;
    cout << toString(x) << endl;
    cout << d.toString(d) << endl;
}
