#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <string>
#include <vector>
#include <unordered_set>
#include "word.h"

using std::unordered_set;
using std::string;
using std::vector;

class Dictionary {
public:
    static const unsigned int MAX_LETTERS = 25;
	Dictionary();
	bool contains(const std::string& word) const;
	std::vector<std::string> get_suggestions(const std::string& word) const;
private:
    unordered_set<string> wordSet;
    vector<vector<Word>> words;
    void add_trigram_suggestions(vector<string>&, const string) const;
    void rank_suggestions(vector<string> &, const string ) const;
    void trim_suggestions(vector<string> &) const;
};

#endif
