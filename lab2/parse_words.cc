#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;
using std::vector;
using std::sort;

string toLower(string& s){
    string lower;

    for (unsigned int i = 0; i < s.length(); ++i){
        lower += tolower(s.at(i));
    }

    return lower;
}

vector<string> findTrigrams(const string &word){
    vector<string> trigrams;
    if (word.length() < 3){
        return trigrams;
    }
    for (unsigned int lower = 0; lower + 3 <= word.length(); ++lower){
        string s; 
        s.append(word, lower, 3);
        s = toLower(s);
        trigrams.push_back(s);
    }
    sort(trigrams.begin(), trigrams.end());
    return trigrams;

}

void write(ifstream &input, ofstream &output){
    string word;
    while (input >> word) {
        auto trigrams = findTrigrams(word);
        output << word << " " << trigrams.size() << " ";
        for (auto i = 0; i < trigrams.size(); ++i){
            output << trigrams.at(i) + " ";
        }
        output << endl;
    }
}

int main(){
    string PATH = "/usr/share/dict/words";
    ifstream input(PATH);
    ofstream output("words.txt");
    write(input, output);

    return 0;
}

