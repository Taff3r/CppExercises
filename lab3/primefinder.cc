#include "primefinder.h"
#include <string>
#include <iostream>
#include <vector>
#include <cmath>

using std::string;
using std::vector;

PrimeFinder::PrimeFinder(int top){
    this->seq = string(top + 1, 'P');
    this->top = top;
}

PrimeFinder::PrimeFinder(){
    this->seq = string(this->DEFAULT, 'P');
}
vector<int> PrimeFinder::find(){ 
    this->makeSequence();
    vector<int> primes;
    for (unsigned int i = 0; i < this->seq.length(); ++i){
        if (this->seq.at(i) == 'P'){
            primes.push_back(i);
        }
    }
    std::cout << this->seq << std::endl;
    return primes; 
}

vector<char> PrimeFinder::getSequence() const{ 
    vector<char> sequence; 
    for (unsigned int i = 0; i < this->seq.length(); ++i){
        sequence.push_back(this->seq.at(i));
    }
    return sequence; 
}

void PrimeFinder::makeSequence(){
    // Make first two in sequence composites.
    this->seq[0] = 'C';
    this->seq[1] = 'C';
    unsigned int i = 0;
    nextPrime(&i);

    while(this->seq.at(i) == 'P'){
        markMultiples(i);
        nextPrime(&i); // Make the value of i to the next prime
    } 
}

void PrimeFinder::nextPrime(unsigned int *i){
    for (unsigned int k = *i + 1; k < this->seq.length(); ++k){
        if (this->seq.at(k) == 'P'){
            *i = k;
            return;
        }
    }
    
    *i = 0;
}

void PrimeFinder::markMultiples(unsigned int i){
    for (unsigned int k = i + i; k < this->seq.length(); k = k + i){
        this->seq[k] = 'C';
    }
}

int PrimeFinder::findLargest(unsigned int i) {
    string oldSeq = this->seq;
    this->seq = string(i, 'P');
    this->find();
    for (int i = this->seq.length() - 1; i >= 0; --i){
        if (this->seq.at(i) == 'P'){
            this->seq = oldSeq;
            return i;
        }
    }
    return -1; 
}

