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
// "private" functions
string toLower(string &s);

Dictionary::Dictionary() {
    const string PATH = "words.txt";
    ifstream words(PATH);
    // read first word in each line of words.txt
    string s;
    int num;
    while (words >> s){
        string f = s;
        vector<string> tris;
        words >> num; // get number
        for(int i = 0; i < num; ++i){
            words >> s; // get tri
            tris.push_back(s);
        }
        if (f.length() < Dictionary::MAX_LETTERS){
            Word w (f, tris);
            this->wordSet.insert(f);
            this->words[f.length()].push_back(w);
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
void Dictionary::add_trigram_suggestions(vector<string> &suggestions, const string word) const{
    // if word is to long for Dict
    if(word.length() > Dictionary::MAX_LETTERS){
        return;
    }

    vector<Word> words = this->words[word.length()];
    // append words with length  - 1 if word is appropriate length
    if (word.length() < 2){
        words.insert(words.end(), this->words[word.length() - 1].begin(), this->words[word.length() - 1].end());
    }

    // append words with length  + 1 if word is appropriate length
    if (word.length() > 3){
       words.insert(words.end(), this->words[word.length() + 1].begin(), this->words[word.length() + 1].end());
    }
    // add words with atleast half of the trigrams matching to suggestions
    vector<string> wTrigrams;
    if (word.length() > 3){
        for (unsigned int lower = 0; lower + 3 <= word.length(); ++lower){
            string s;
            s.append(word, lower, 3);
            s = toLower(s);
            wTrigrams.push_back(s);
        }
        sort(wTrigrams.begin(), wTrigrams.end());
    }
    for (Word w : words){
        if (w.get_matches(wTrigrams) > wTrigrams.size() / 2){
            suggestions.push_back(w.get_word());
        }
    }
}

string toLower(string &s){
    string lower;
    for (unsigned int i = 0; i < s.length(); ++i){
        lower += tolower(s.at(i));
    }
    return lower;
}
void Dictionary::rank_suggestions(vector<string> &suggestions, const string word) const{}
void Dictionary::trim_suggestions(vector<string> &suggestions) const{}





