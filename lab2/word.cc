#include <string>
#include <vector>
#include "word.h"

using std::vector;
using std::string;

Word::Word(const string& w, const vector<string>& t) {
    this->word = w;
    this->trigrams = t;
}

string Word::get_word() const {
    return this->word;
}

unsigned int Word::get_matches(const vector<string>& t) const {
    auto matches = 0;
    unsigned int p1 = 0;
    unsigned int p2 = 0;
    while(p1 < this->trigrams.size() && p2 < t.size()){
        if (this->trigrams.at(p1) == t.at(p2)){
            ++matches;
            ++p2;
            ++p1;
        } else if (this->trigrams.at(p1) > t.at(p2)){
            ++p2;
        } else {
            ++p1;
        }
    }
	return matches;
}
