#include "bitsetiterator.h"

bool BitsetIterator::operator !=(const BitsetIterator& bsi) const {
    
    return this->ref.pos != bsi.ref.pos;
}

BitsetIterator& BitsetIterator::operator++(){
    this->ref.pos++;
    return *this;
}

BitReference BitsetIterator::operator*(){
    return BitReference(this->ref.p_bits, this->ref.pos);
}

BitsetIterator& BitsetIterator::operator=(const BitsetIterator& rhs){
    this->ref.p_bits = rhs.ref.p_bits;
    this->ref.pos = rhs.ref.pos;
    return *this;
}
