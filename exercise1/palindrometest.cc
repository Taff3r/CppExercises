#include "palindrome.h"
#include <string>
#include <iostream>

int main(){
    string input;
    std::cin >> input;
    Palindrome p1(input);
    string isPal = p1.isPalindrome() ? "true" : "false";
    std::cout << "Is palindrome? " <<  isPal << "\n";
    return 0;
}
