#include <string>
#include <utility>
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
using std::pair;
using std::make_pair;
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
    if (word.length() > 2 && word.length() + 1 < Dictionary::MAX_LETTERS){
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
int min(int x, int y){
     int min = ((x) < (y)) ? (x) : (y);
     return min;
}

int distance(const string &s, const string &w){
    int d[Dictionary::MAX_LETTERS + 1][Dictionary::MAX_LETTERS + 1];
    for (unsigned int i = 0; i <= s.length(); ++i){
        d[i][0] = i;
    }

    for (unsigned int j = 0; j <= w.length(); ++j){
        d[0][j] = j;
    }

    unsigned int i = 1;
    unsigned int j = 1;
    for (i = 1; i <= s.length(); ++i){
        for (j = 1; j <= w.length(); ++j){
            int qDist = 0;
            if(s.at(i - 1) == w.at(j - 1)){
                qDist = d[i-1][j-1];
            } else {
                qDist = (d[i-1][j-1] + 1);
            }
            int oDist = min((d[i-1][j] + 1), (d[i][j-1] + 1));
            d[i][j] = min(oDist, qDist);
        }
    }
    return d[s.length()][w.length()];
}

bool comparePair(pair<int, string> &p1, pair<int, string> &p2){
    return p1.first < p2.first;
}
void Dictionary::rank_suggestions(vector<string> &suggestions, const string word) const{
    vector<pair<int, string>> pairs;
    for (string sugg : suggestions){
        int d = distance(word, sugg);
        pairs.push_back(make_pair(d, sugg));
    }
    // sort suggestions on distance
    sort(pairs.begin(), pairs.end(), comparePair);
    suggestions.clear(); // empty current suggestions

    // replace with sorted ones
    for (unsigned int i = 0; i < pairs.size(); ++i){
        auto second = pairs.at(i).second;
        suggestions.push_back(second);
    }

}


void Dictionary::trim_suggestions(vector<string> &suggestions) const{
    while (suggestions.size() > 5){
        suggestions.pop_back();
    }
}





