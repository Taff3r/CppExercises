#include "bitbuffer.h"
#include <string>
#include <iostream>
using std::ostream;
using std:: string;
BitBuffer::BitBuffer(ostream &out): os(out), inBuffer(0){}

void BitBuffer::put(bool b) {
    buffer = (buffer << 1) | b;
    ++this->inBuffer;
    if (this->inBuffer == 8){
        os.put(buffer);
        inBuffer = 0;
    }
}
