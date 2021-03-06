#ifndef UMNS_H 
#define UMNS_H 
#include "nameserverinterface.h"
#include <unordered_map>

class UMNS : public NameServerInterface {
private:
    std::unordered_map<HostName, IPAddress> map;
public:
    void insert(const HostName&, const IPAddress&);
    bool remove(const HostName&);
    IPAddress lookup(const HostName&) const;
};

#endif
