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
    this->words.resize(Dictionary::MAX_LETTERS);
    while (words >> s){
        string f = s;
        vector<string> tris;
        int num;
        words >> num; // get number
        for(int i = 0; i < num; ++i){
            words >> s; // get tri
            tris.push_back(s);
        }
        Word w (f, tris);
        if (f.length() < Dictionary::MAX_LETTERS){
            this->wordSet.insert(s);
            this->words.at(f.length()).push_back(w);
        }
    }
}

bool Dictionary::contains(const string& word) const {
    return this->wordSet.find(word) != this->wordSet.end();
}

vector<string> Dictionary::get_suggestions(const string& word) const {
	vector<string> suggestions;
    add_trigram_suggestions(suggestions, word);
    rank_suggestions(suggestions, word);
    trim_suggestions(suggestions);
	return suggestions;
}
void Dictionary::add_trigram_suggestions(vector<string> &suggestions, const string word) const{}
void Dictionary::rank_suggestions(vector<string> &suggestions, const string word) const{}
void Dictionary::trim_suggestions(vector<string> &suggestions) const{}





