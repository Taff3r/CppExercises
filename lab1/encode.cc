#include <iostream>
#include <fstream>
#include <string>
#include "coding.h"

using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::ofstream;
using std::ifstream;

int main(int argc, const char** argv){
    string file; 
    if( argc < 2 ){
        cout << "Please enter a filename" << endl;
        cin >> file;
    } else {
        file = argv[1];
    }

    ifstream input(file);
    ofstream output(file + ".enc");

    char c;  
    while(input.get(c)){
       output << encode(c);
    }

    output.close();
    input.close();
    return 0;
}
