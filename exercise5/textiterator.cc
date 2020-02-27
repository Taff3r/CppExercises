#include "textiterator.h"
#include <string>
#include <iostream>
TextIterator& TextIterator::operator ++(){
    if(linePos != (*ref)[currentLine].length() - 1) {
        linePos++;
    } else {
        currentLine++;
        linePos = 0;
    }
    return *this;
}

char& TextIterator::operator *(){
    return (*ref)[currentLine][linePos];
}

TextIterator& TextIterator::operator =(const TextIterator& rhs){
    this->ref = rhs.ref;
    this->linePos = rhs.linePos;
    this->currentLine = rhs.currentLine;
    return *this;
}

bool TextIterator::operator != (const TextIterator& ti) const {
    return this->ref != ti.ref || this->currentLine != ti.currentLine || this->linePos != ti.linePos;

}
