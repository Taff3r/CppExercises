#ifndef TEXT_H
#define TEXT_H

#include <string>
#include <vector>
#include "textiterator.h"
class Text {
friend class TextIterator;
public:

    // Functions
	void addLine(const std::string& line) { lines.push_back(line); }
    // Iterator 
    using iterator = TextIterator;
    iterator begin() { return TextIterator(&this->lines, 0); }
    iterator end(){ return TextIterator(&this->lines, this->lines.size()); }
private:
	std::vector<std::string> lines;
};

#endif
