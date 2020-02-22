#include "bitreference.h"
#include "bitset.h"

/*
 * p_bits = pointer to word
 * pos = position of the bit
 */
BitReference& BitReference::operator=(bool b) {
	//
	// *** IMPLEMENT ***
	// This corresponds to the set() function in SimpleBitset.
    //
    if (b){ // if b == 1
        *this->p_bits |= 1L << this->pos;;
    } else { 
        *this->p_bits &= ~ (1L << this->pos);
    }
	return *this;
}

BitReference& BitReference::operator=(const BitReference& rhs) {
	//
	// *** IMPLEMENT ***
	// Same as operator=(bool), but the bit is picked from rhs
    //
    if(rhs){
        *this->p_bits |= 1L << this->pos;
    } else {
        *this->p_bits &= ~ (1L << this->pos);
    }
	return *this;
}

BitReference::operator bool() const {
	//
	// *** IMPLEMENT ***
	// This corresponds to the get() function in SimpleBitset.
	//
    return (*this->p_bits & (1L << this->pos)) != 0;
}
