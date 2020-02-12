/*
 * countobj.cc: count creation and destruction of objects. One class and
 * several functions, all in this file.
 */

#include <iostream>
#include <string>

class Counted {
public:
	Counted();
	~Counted();
    Counted(const Counted&);
	static int getNbrObj();
    Counted& operator=(const Counted &);
private:
	static int nbrObj;
};

int Counted::nbrObj = 0;

Counted::Counted() {
	nbrObj++;
}

Counted::Counted(const Counted& o){
    nbrObj++;

}

Counted& Counted::operator=(const Counted &o){
    this->nbrObj = o.nbrObj;
    return *this;
}

Counted::~Counted() {
	nbrObj--;
}

int Counted::getNbrObj() {
	return nbrObj;
}

void f() {
	Counted c;
	Counted* pc = new Counted;
	delete pc;
}

void g() {
	Counted c1;
	Counted c2 = c1;
}

void h() {
	Counted c1;
	Counted c2;
	c2 = c1;
}

using std::cout;
using std::endl;
using std::string;

void print_nbr_objects(const string& msg) {
	cout << msg << " -- number of objects: "
	     << Counted::getNbrObj() << endl;
}

int main() {
	print_nbr_objects("Program start, before f()");
	f();
	
	print_nbr_objects("After f(), before g()    ");
	g();
	
	print_nbr_objects("After g(), before h()    ");
	h();
	
	print_nbr_objects("After h(), program end   ");
}

