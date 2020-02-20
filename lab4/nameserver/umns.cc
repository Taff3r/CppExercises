#include "umns.h"
#include <algorithm>
#include <unordered_map>
using std::pair;
void UMNS::insert(const HostName& hn, const IPAddress& ip){
    this->map[hn] = ip;
}

bool UMNS::remove(const HostName& hn){
    auto iterator = find_if(this->map.begin(), this->map.end(), [hn] (const pair<HostName, IPAddress> pair){
            if(pair.first == hn){
                return true;
            }
            return false;
            });
    if(iterator != this->map.end()){
        this->map.erase(iterator);
        return true;
    }

    return false;
}

IPAddress UMNS::lookup(const HostName& hn) const {
    try{
        return this->map.at(hn);
    }catch(std::exception& e){
        return NON_EXISTING_ADDRESS;
    }
}


