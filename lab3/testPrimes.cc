#include "primefinder.h"
#include <string>
#include <vector>
#include <iostream>
#include <iterator>

int main(){
    PrimeFinder pf(35);
    std::vector<int> primes35= pf.find();
    PrimeFinder pf2(200);
    std::vector<int> primes200 = pf2.find();
    PrimeFinder pf3;
    int largest100K = pf3.findLargest(1000*100);
    
    // Tests    
    std::cout << primes35.size() << " (11)" << std::endl;

    std::copy(primes35.begin(), primes35.end(), std::ostream_iterator<int> (std::cout, " "));
    std::cout << std::endl;
    std::copy(primes200.begin(), primes200.end(), std::ostream_iterator<int> (std::cout, " "));
    std::cout << std::endl;
    std::cout << primes200.size() << " (46)" << std::endl;
    std::cout << largest100K << " (99991)" << std::endl;

}
