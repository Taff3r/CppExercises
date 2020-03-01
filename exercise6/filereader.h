#ifndef FILE_READER_H
#define FILE_READER_H

#include <unordered_map>
#include <string>
#include <iostream>

class FileReader {
    private:
        std::unordered_map<std::string, unsigned int> count;
        std::unordered_map<std::string, std::unordered_map<std::string, int>> fileCommons;
    public:
        friend std::istream& operator >> (std::istream& is, FileReader & fr);
        friend std::ostream& operator << (std::ostream& os, FileReader & fr);
};

#endif 
