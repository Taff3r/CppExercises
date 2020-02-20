#include "vns.h"
#include "nameserverinterface.h"
#include <iostream>
#include <algorithm>
#include <tuple>
#include <iterator>
using std::tuple;
using std::find_if;
using std::get;
using std::iterator;

void VNS::insert(const HostName& hn, const IPAddress& ip){
    this->pairs.push_back({hn, ip});
}

bool VNS::remove(const HostName& hn){
   auto iterator = find_if(this->pairs.begin(), this->pairs.end(), [hn](const tuple<HostName, IPAddress> tup){
           if (hn == get<0>(tup)){
                return true;
           }
           return false;
           });

   if (iterator != this->pairs.end()){
       this->pairs.erase(iterator);
       return true;
   }

   return false;
}



IPAddress VNS::lookup(const HostName& hn) const {
    auto iterator = find_if(this->pairs.begin(), this->pairs.end(), [hn] (const tuple<HostName, IPAddress> tup) {
           if (hn == get<0>(tup)){
                return true;
           }
           return false;
           });

    if(iterator != this->pairs.end()){
        auto pos = std::distance(this->pairs.begin(), iterator);
        return get<1>(this->pairs.at(pos));
    }
    return NON_EXISTING_ADDRESS;
}
