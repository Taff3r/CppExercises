#ifndef PRIME_FINDER_H
#define PRIME_FINDER_H

#include <string>
#include <vector>

class PrimeFinder {
public:
    PrimeFinder(int top);
    PrimeFinder();
    std::vector<int> find();
    int findLargest(unsigned int);
    std::vector<char> getSequence() const;
private:
    const static unsigned int DEFAULT = 10;
    std::string seq;  
    int top;
    void makeSequence();
    void nextPrime(unsigned int *i);
    bool isPrime(unsigned int i);
    void markMultiples(unsigned int i);
};

#endif
