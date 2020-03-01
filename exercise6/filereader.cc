#include "filereader.h"
#include <string>
using std::string;
#include <unordered_map>
using std::unordered_map;
#include <iostream>
using std::ostream;
using std::istream;
#include <fstream>
using std::ifstream;
#include <vector>
using std::vector;
#include <algorithm>

ostream& operator << (ostream& os, FileReader& fr){
    os << "Top 20 (All Files):" << std::endl;
    vector<std::pair<int, string>> top;
    for(std::pair<string, int> p : fr.count){
        top.push_back({p.second, p.first});
    }
    sort(top.begin(), top.end(), [] (const std::pair<int, string>& p,const std::pair<int, string>& l ) {
            return p.first > l.first;
            });
    for (size_t i = 0; i < 20 && i < top.size(); i++){
        os << top[i].second << " : " << top[i].first << std::endl;
    }
    return os;
}
istream& operator >> (istream& is, FileReader& fr){
    string fileName;
    is >> fileName;
    ifstream fs(fileName);

    while(!fs.eof()){
        string s;
        fs >> s;
        fr.count[s]++;
        fr.fileCommons[fileName][s]++;
    }
    fs.close();
    return is;
}



