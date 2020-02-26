#include "morsecode.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

using std::string;

MorseCode::MorseCode() {
    // Read .def file
    std::ifstream def("morse.def");
    string read;
    while(def >> read){
        def >> this->map[read];
    }

    def.close();
}

string MorseCode::encode(const string& text) const {
    string ret;
    string key;
    for (char c : text){
        key = c;
        if (map.count(key) > 0){
            ret += map.at(key) + " ";
        }
    }
    return ret; 
}

string MorseCode::decode(const string& enc) const {
    string ret;
    string s;
    std::istringstream ss(enc);
    while ( ss >> s ){
        find_if(map.begin(), map.end(), [&ret, &s](const std::pair<string, string>& p)
                {
                if (p.second == s){
                    ret += p.first; 
                    return true;
                }
                    return false;
                });
    }
    return ret; 
}
