#ifndef TEXT_ITERATOR_H
#define TEXT_ITERATOR_H

#include <vector>
#include <string>
#include <iterator>
class TextIterator : public::std::iterator<std::forward_iterator_tag, bool> {
private:
    std::vector<std::string> *ref;
    unsigned int currentLine;
    unsigned int linePos;

public:
    TextIterator(std::vector<std::string> *lines, unsigned int lineIndex) : ref(lines), currentLine(lineIndex), linePos(0){};
    TextIterator(const TextIterator& it) : ref(it.ref), currentLine(it.currentLine), linePos(it.linePos){};

    TextIterator& operator ++();
    char& operator *();
    TextIterator& operator = (const TextIterator& rhs);
    bool operator != (const TextIterator& ti) const;
    
   };





#endif

