#include "rational.h"
#include <iostream>

using std::ostream;
Rational::Rational(){
    this->t = 0;
    this->n = 1;
}

Rational::Rational(unsigned int t, unsigned int n){
    this->t = t;
    this->n = n;
}
Rational::Rational(unsigned int t){
    this->t = t;
    this->n = 1;
}

int Rational::gcd(unsigned int u, unsigned int v){
    if (u == v){
        return u;
    }

    if (u == 0){
        return v;
    }

    if (t == 0){
        return u;
    }

    if (u % 2 == 0 && v % 2 == 0) {
        return 2 * gcd(u / 2, v / 2) ;
    }

    if (u % 2 == 0 && v % 2 == 1) {
        return gcd(u/2, v) ;
    }

    if (u % 2 == 1 && v % 2 == 0) {
        return gcd(u , v / 2) ;
    }

    if (u % 2 == 1 && v % 2 == 1 ) {
        if (u >= v){
            return gcd((u - v)/2 , v ) ;
        } else {
            return gcd((v - u) / 2, u );
        }
    }

    return 0;
}

ostream& operator << (ostream& os, Rational& r){
    os << r.t << '/' << r.n;
    return os;
}

