#include "hns.h"
#include <vector>
#include <algorithm>
#include <tuple>

using std::tuple;
using std::vector;
using std::get;

HNS::HNS(long size){
    this->map.resize(size);
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
}

bool HNS::remove(const HostName& hn){
    int index = hash(hn);
    auto iterator = remove_if(this->map[index].begin(), this->map[index].end(), [hn] (const Node n) {
            if (hn == n.hn) {
               return true; 
            }
            return false;
    });
    if (iterator != this->map[index].end()){
        return true;
    }
    return false;
}

IPAddress HNS::lookup(const HostName& hn) const {
    try {
        int index = hash(hn);
        auto iterator = find_if(this->map[index].begin(), this->map[index].end(), [hn] (const Node n) {
                if (hn == n.hn) {
                    return true; 
                }
                return false;
        });

        if (iterator != this->map[index].end()){
            auto dist = std::distance(this->map[index].begin(), iterator);
            return this->map[index][dist].ip;
        }
    } catch (std::exception& e){
        return NON_EXISTING_ADDRESS;
    }

    return NON_EXISTING_ADDRESS;
}
    



