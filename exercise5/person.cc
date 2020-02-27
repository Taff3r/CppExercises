#include "person.h"

#include <iostream>

std::ostream& operator<<(std::ostream& os, const Person& p) {
	return os << p.get_name() << " " << p.get_phone();
}

bool Person::operator < (const Person& rhs) const {
    if(this->name == rhs.name) {
        return this->phone < rhs.phone;
    }

    return this->name < rhs.name;
}
