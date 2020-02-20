#ifndef HNS_H 
#define HNS_H 
#include "nameserverinterface.h"
#include <unordered_map>
#include <vector>
#include <tuple>
using std::vector;
using std::tuple;

class HNS : public NameServerInterface {
private:
    vector<vector<tuple<HostName,IPAddress>>> map;
    int hash(const HostName&) const;
public:
    HNS(long size);
    void insert(const HostName&, const IPAddress&);
    bool remove(const HostName&);
    IPAddress lookup(const HostName&) const;
};

#endif
