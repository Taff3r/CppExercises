#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "word.h"
#include "dictionary.h"
#include <limits>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::ifstream;
using std::numeric_limits;
using std::streamsize;

Dictionary::Dictionary() {
    const string PATH = "words.txt";
    ifstream words(PATH);
    // read first word in each line of words.txt
    string s;
    while (words >> s){
        string f = s;
        vector<string> tris;
        this->wordSet.insert(s);
        int num;
        words >> num; // get number
        for(int i = 0; i < num; ++i){
            words >> s; // get tri
            tris.push_back(s);
        }
        Word w(f, tris);
    }
        cout << "dict loaded" << endl;
}

bool Dictionary::contains(const string& word) const {
    return this->wordSet.find(word) != this->wordSet.end();
}

vector<string> Dictionary::get_suggestions(const string& word) const {
	vector<string> suggestions;
	return suggestions;
}
