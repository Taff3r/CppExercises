#include "crypto.h"
#include <iostream>
#include <string>
#include <random>
#include <cstdlib>

using std::string;
using std::srand;
using std::rand;
string Crypto::encrypt(const string& text, unsigned int key) {
    srand(key); // seed with key
    string toBeEnc = text; 
    for (auto i = 0; i != text.length(); ++i){
        int randomNbr = rand() % (256 + 1);
        toBeEnc[i] = toBeEnc.at(i) + randomNbr;
    }

	return toBeEnc;
}

string Crypto::decrypt(const string& crypt, unsigned int key) {
    srand(key); // seed with key
    string toBeEnc = crypt; 
    for (auto i = 0; i != crypt.length(); ++i){
        int randomNbr = rand() % (256 + 1);
        toBeEnc[i] = toBeEnc.at(i) - randomNbr;
    }

	return toBeEnc;
}
