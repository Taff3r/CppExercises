#include "hns.h"
#include <vector>
#include <algorithm>
#include <iostream>

using std::tuple;
using std::vector;
using std::get;

HNS::HNS(long size){
    this->map.resize(size);
    for( vector<Node> v : this->map ){
        v.reserve(size / 10);
    }
}

int HNS::hash(const HostName& hn) const {
    int value = std::hash<std::string>{} (hn);
    if ( value < 0 ){
        value *= -1;
    } 
    return value % this->map.size();
}

void HNS::insert(const HostName& hn, const IPAddress& ip){
    int index = hash(hn);
    this->map[index].push_back({hn, ip});
    // Make the list sorted for faster lookup
    sort(this->map[index].begin(), this->map[index].end(), [](const Node r, const Node l) {
            return r.hn < l.hn;
            });
    
}

bool HNS::remove(const HostName& hn){
    int index = hash(hn);
    auto iterator = find_if(this->map[index].begin(), this->map[index].end(), [hn] (const Node n) {
            if (hn == n.hn) {
               return true; 
            }
            return false;
    });
    if (iterator != this->map[index].end()){
        this->map[index].erase(iterator);
        return true;
    }
    return false;
}

IPAddress HNS::lookup(const HostName& hn) const {
    try {
        int index = hash(hn);
        Node n(hn, NON_EXISTING_ADDRESS);
        auto iterator = std::lower_bound(this->map[index].begin(), this->map[index].end(), n);
        if(iterator != this->map[index].end()) {
            return this->map[index][iterator - this->map[index].begin()].ip;
        }
        return NON_EXISTING_ADDRESS;
    // if nothing is at index
    } catch (std::exception& e){
        return NON_EXISTING_ADDRESS;
    }
}
    



