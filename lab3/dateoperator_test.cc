#include "date.h"
#include <string>
#include <iostream>


int main (){
    Date d(2019, 2, 16);
    std::cout << d; 
    std::cout << " (2019-02-16)" << std::endl;
    std::cout << "Insert to following: 2019-03-12" << std::endl;
    std::cin >> d;
    std::cout << d << " (2019-03-12)" << std::endl;
    std::cout << "Insert something with bad formatting e.g.: 2019-ag-asdfadfka" << std::endl;

    std::cin >> d;
}
