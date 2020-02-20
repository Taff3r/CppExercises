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
    unsigned int value = 7;
    for (unsigned int i = 0 ; i < hn.size(); ++i){
        value = value * 31 * hn[i];
    }
    return value % this->map.size();
}

void HNS::insert(const HostName& hn, const IPAddress& ip){
    int index = hash(hn);
    this->map[index].push_back({hn, ip});
}

bool HNS::remove(const HostName& hn){
    int index = hash(hn);
    auto iterator = find_if(this->map[index].begin(), this->map[index].end(), [hn] (const tuple<HostName, IPAddress> tuple) {
            if (hn == get<0>(tuple)) {
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
        auto iterator = find_if(this->map[index].begin(), this->map[index].end(), [hn] (const tuple<HostName, IPAddress> tuple) {
                if (hn == get<0>(tuple)) {
                    return true; 
                }
                return false;
        });

        if (iterator != this->map[index].end()){
            auto dist = std::distance(this->map[index].begin(), iterator);
            return get<1>(this->map[index].at(dist));
        }
    } catch (std::exception& e){
        return NON_EXISTING_ADDRESS;
    }

    return NON_EXISTING_ADDRESS;
}
    



