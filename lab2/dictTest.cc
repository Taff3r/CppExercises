#include <iostream>
#include <algorithm>
#include "dictionary.h"
#include <string>
#include <vector>
#include "word.h"

using std::string;
using std::vector;
using std::cout;
using std::endl;

int main(){
    string s = "summer";
    vector<string> tris;
    vector<string> t;
    tris.push_back("sum");
    tris.push_back("umm");
    tris.push_back("mme");
    tris.push_back("mer");
    t.push_back("sum");
    t.push_back("aaa");
    t.push_back("umm");
    t.push_back("rand");
    t.push_back("mme");
    t.push_back("mer");;
    std::sort(t.begin(), t.end());
    std::sort(tris.begin(), tris.end());
    Word w(s, tris);
    cout << w.get_matches(t) << "(4)" << endl;
}
