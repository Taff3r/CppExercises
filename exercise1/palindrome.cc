#include "palindrome.h"
#include <string>
using std::string;

Palindrome::Palindrome(string text){this->text = text;}

Palindrome::Palindrome(){this->text = "";}

bool Palindrome::isPalindrome(){
    int end = this->text.length() - 1;
    int start = 0;
    bool isPalindrome = true; 
    while(isPalindrome) {
        if (this->text.at(start) != this->text.at(end)){
            isPalindrome = false; 
        }

        if (end <= start){
            break;
        } else {
            --end;
            ++start;
        }
    }

    return isPalindrome;
}

void Palindrome::setText(string text){
    this->text = text;
}
