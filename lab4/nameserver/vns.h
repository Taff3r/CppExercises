#ifndef VNS_H
#define VNS_H
#include "nameserverinterface.h"
#include <vector>
#include <string>
#include <tuple>
using std::vector;
using std::string;
using std::tuple;
class VNS : public NameServerInterface {
private:
    vector<tuple<HostName, IPAddress>> pairs;
public:
    void insert(const HostName& hn, const IPAddress& ip);
    bool remove(const HostName& hn);
    IPAddress lookup(const HostName& hn) const;
};
#endif
