#ifndef RATIONAL_H
#define RATIONAL_H
#include <ostream>
class Rational{
private:
    unsigned int t;
    unsigned int n;
    int gcd(unsigned int, unsigned int);
public:
    Rational();
    Rational(unsigned int, unsigned int);
    Rational(unsigned int);
    friend std::ostream& operator << (std::ostream&, const Rational& r);
    Rational& operator += (const Rational& r);
};
Rational operator + (const Rational& lhs, const Rational& rhs);
#endif

