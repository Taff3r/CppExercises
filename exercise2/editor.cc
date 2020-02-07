#include "editor.h"
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;
string::size_type Editor::find_left_par(string::size_type pos) const {
    char parType = this->text[pos];
    char find;
    switch (parType) {
        case ']':
            find = '[';
            break;
        case ')':
            find = '(';
            break;
        case '}':
            find = '{';
            break;
        default:
            return string::npos;
    }
    int ignore = 0;
    int position = static_cast<int> (pos) - 1;
    while ( position >= 0 ){
        char curr = this->text[position];
        if (curr == find){
            if (ignore <= 0){
                return position;
            } else {
                --ignore;
            }
        } else if (curr == parType){
            ++ignore;
        }
        --position;
    }
    return string::npos;
}
