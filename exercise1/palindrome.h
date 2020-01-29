#include <string>
using std::string;

class Palindrome {

    private:
        string text;

    public:
        Palindrome(string);
        Palindrome();
        void setText(string);
        bool isPalindrome();
};
