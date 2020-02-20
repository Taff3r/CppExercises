#include "rational.h"
#include <iostream>

using std::ostream;
Rational::Rational(){
    this->t = 0;
    this->n = 1;
}

Rational::Rational(unsigned int t, unsigned int n){
    unsigned int gcd = this->gcd (t, n);
    this->t = t / gcd;
    this->n = n / gcd;
}
Rational::Rational(unsigned int t){
    this->t = t;
    this->n = 1;
}

int Rational::gcd(unsigned int u, unsigned int v){

    if (u == v){
        return v;
    }

    if (u == 0){
        return v;
    }

    if (v == 0){
        return u;
    }

    if (u % 2 == 0) { // if u is even
        if (v % 2 == 0){ // if both are even
            return 2 * gcd(u / 2, v / 2) ;
        } else { // if v is odd
            return gcd(u/2, v);
        }
    }
    // u is odd, v is even
    if (v % 2 == 0) { 
        return 2 * gcd(u / 2, v / 2) ;
    }
    // both are odd
    if (u >= v){
        return gcd((u - v) / 2, v) ;
    }

    return gcd((v - u) / 2, u);
}

ostream& operator << (ostream& os, const Rational& r){
    if (r.n != 1){
        os << r.t << '/' << r.n;
    } else {
        os << r.t;
    }
    return os;
}

Rational operator + (const Rational& lhs, const Rational& rhs){
    Rational loc = rhs;
    return loc += lhs;
}

Rational& Rational::operator += (const Rational& lhs){
    unsigned int t = this->t * lhs.n + this->n * lhs.t; 
    unsigned int n = this->n * lhs.n;
    unsigned int gcd = this->gcd(t, n);
    this->t = t / gcd;
    this->n = n / gcd;
    return *this;
}

