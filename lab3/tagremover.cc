#include "tagremover.h"
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;
TagRemover::TagRemover(std::istream& in ){
    // load file through using buffer string 
    string buffer;
    while(std::getline(in, buffer)){
        this->loaded += buffer + std::string(1, '\n');
    }
    removeTags();
    replaceSpecialChars();
}

void TagRemover::removeTags(){
    while(this->loaded.find_first_of('<') != string::npos && this->loaded.find_first_of('>') != string::npos){
       auto first = this->loaded.find_first_of('<');
       auto last = this->loaded.find_first_of('>');
       this->loaded.replace(first, last + 1 - first, "");
    }
}

void TagRemover::replaceSpecialChars(){
    while(this->loaded.find_first_of('&') != string::npos && this->loaded.find_first_of(';') != string::npos){
        auto start = this->loaded.find_first_of('&');
        auto end = this->loaded.find_first_of(';');
        this->replaceSpecial(start, end);
    }
}

void TagRemover::replaceSpecial(int start, int end){
    string sub = this->loaded.substr(start, end + 1 - start);
    if(sub == "&nbsp;"){
       this->loaded.replace(start, end + 1 - start, " ");
    } else if (sub == "&lt;"){
       this->loaded.replace(start, end + 1 - start, "<");
    } else if (sub == "&gt;"){
        this->loaded.replace(start, end + 1 - start, ">");
    } else if (sub == "&amp;"){
        this->loaded.replace(start, end + 1 - start, "&");
    }
}

void TagRemover::print(std::ostream& out){
    out << this->loaded;
}
