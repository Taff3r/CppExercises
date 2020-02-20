#ifndef HNS_H
#define HNS_H
#include <map>
#include "nameserverinterface.h"

class MNS : public NameServerInterface {
private:
    std::map<HostName, IPAddress> map;
public:
    void insert(const HostName&, const IPAddress&);
    bool remove(const HostName&);
    IPAddress lookup(const HostName&) const;
};
#endif
