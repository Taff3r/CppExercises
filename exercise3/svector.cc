/*
 * Class SVector: implementation.
 */

#include "svector.h"

SVector::SVector(size_t size) : n(size), v(new int[n]){}

SVector::~SVector() {
	delete[] v;
}

SVector::SVector(const SVector &v): n(v.n){
    this->v = new int[n];
    for (size_t i = 0; i != this->n; ++i){
        this->v[i] = v.v[i];
    }
}

SVector& SVector::operator=(SVector &rhs){
    if (this != &rhs){
        int* tmp = new int[rhs.n];
        for (size_t i = 0; i != rhs.n; ++i){
            tmp[i] = this->v[i];
        }
        delete[] v;
        this->v = tmp;
        this->n = rhs.n;
    }
    return *this; 
}

size_t SVector::size() const {
	return n;
}

int SVector::get(size_t i) const {
    return v[i];
}

void SVector::set(size_t i, int value) {
    v[i] = value;
}
