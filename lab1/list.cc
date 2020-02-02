#include <iostream>
#include "list.h"
using std::cout;
using std::endl;
List::List() {
    this->first = nullptr;
}
    
List::~List() {
   delete this->first; 
}

bool List::exists(int d) const {
    Node* n = this->first;
    while (n != NULL){
        if(n->value == d){
            return true;
        }else{
            n = n->next;
        }
    }
	return false;
}

int List::size() const {
    int size{0};
    Node* n = this->first;
    while (n != NULL){
        ++size;
        n = n->next;
    }
	return size;
}

bool List::empty() const {
    return this->first == nullptr;
}

void List::insertFirst(int d) {
    Node* n = new Node(d, this->first);
    this->first = n;
}

void List::remove(int d, DeleteFlag df) {
    Node* prev = nullptr; 
    Node* curr = this->first;

    while(curr != NULL){ // returns if list is empty
        switch (df) {
            case DeleteFlag::LESS:
                if (curr->value < d){
                    if (prev == NULL){
                        this->first = curr->next;
                    }else{
                        prev->next = curr->next; 
                    }
                    delete curr;
                    return;
                }
                break;
            case DeleteFlag::EQUAL:
                if (curr->value == d){
                    if (prev == NULL){
                        this->first = curr->next;
                    }else{
                        prev->next = curr->next; 
                    }
                    delete curr;
                    return;
                }
                break;
            case DeleteFlag::GREATER:
                if(curr->value > d){
                    if (prev == NULL){
                        this->first = curr->next;
                    }else{
                        prev->next = curr->next; 

                    }
                    delete curr;
                    return;
                }
                break;
        }
        prev = curr;
        curr = curr->next;
    }
}

void List::print() const {
    Node* curr = this->first;
    cout << '(';
    while(curr != NULL){
        if (curr ->next != NULL){
            cout << curr->value << " ";
        }else{
            cout << curr->value;
        }
        curr = curr->next;
    }
    cout << ')' << endl;
}

