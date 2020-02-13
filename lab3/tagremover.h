#ifndef TAG_REMOVER_H
#define TAG_REMOVER_H
#include <iostream>
#include <string>

class TagRemover {
private:
    std::string loaded;
    void removeTags();
    void replaceSpecialChars();
    void replaceSpecial(int start, int end);
public:
    TagRemover(std::istream&);
    void print(std::ostream&);
};

#endif


