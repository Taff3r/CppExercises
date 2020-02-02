#include "list.h"
#include <iostream>
int main(){
    List test;
    std::cout<< "Constructed" << std::endl;
    std::cout<< "Empty: " << test.empty() << " (1)"<< std::endl;
    std::cout<< "size: " << test.size() << " (0)" << std::endl;
    test.insertFirst(3);
    std::cout<< "size: " << test.size() << " (1)" << std::endl;
    std::cout<< "Empty: " << test.empty() << " (0)"<< std::endl;
    test.insertFirst(1);
    std::cout<< "size: " << test.size() << " (2)" << std::endl;
    std::cout<< "Empty: " << test.empty() << " (0)"<< std::endl;
    std::cout<< "3 Exists: " << test.exists(3) << " (1)" << std::endl;
    std::cout<< "2 Exists: " << test.exists(2)<< " (0)" << std::endl;
    std::cout<< "1 Exists: " << test.exists(1)<< " (1)" << std::endl;
    std::cout<< "Contents:  " << "(1 3)" << std::endl;
    test.print();
    test.remove(3);
    std::cout<< "Remove 3: " << test.exists(3) << " (0)" << std::endl;
    std::cout<< "Contents:  " << "(1)" << std::endl;
    test.print();
    std::cout<< "size: " << test.size() << " (1)" << std::endl;
    test.remove(1);
    std::cout<< "Remove 1: " << test.exists(1) << " (0)" << std::endl;
    std::cout<< "Contents:  " << "()" << std::endl;
    test.print();
    std::cout<< "size: " << test.size() << " (0)" << std::endl;
    test.insertFirst(3);
    test.insertFirst(3);
    test.insertFirst(3);
    std::cout<< "Contents:  " << "(3 3 3)" << std::endl;
    test.print();
    std::cout<< "size: " << test.size() << " (3)" << std::endl;
}
