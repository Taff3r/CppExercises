/*
 * A BitsetIterator is an iterator for Bitsets.
 * Postfix ++, ==, and -> are not implemented.
 */

#ifndef BITSET_ITERATOR_H
#define BITSET_ITERATOR_H

#include "bitreference.h"
#include <iterator>

class BitsetIterator : public std::iterator<std::forward_iterator_tag, bool> {
public:
    BitsetIterator(const BitsetIterator& bi) : ref(bi.ref.p_bits, bi.ref.pos){}
	BitsetIterator(Bitset::BitStorage* pb, std::size_t p) : ref(pb, p) {}
	bool operator!=(const BitsetIterator& bsi) const;
	
	BitsetIterator& operator++();

	BitReference operator*(); 
	
	BitsetIterator& operator=(const BitsetIterator& rhs); 

private:
	BitReference ref;
};

#endif

