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
    struct Node {
        Node(HostName hn, IPAddress ip) : hn(hn), ip(ip) {};
        Node() : hn(""), ip(NON_EXISTING_ADDRESS) {};
        HostName hn;
        IPAddress ip;
        bool operator < (const Node&n) const {
            return this->hn < n.hn;
        }
    };
    vector<vector<Node>> map;
    int hash(const HostName&) const;
public:
    HNS(long size);
    void insert(const HostName&, const IPAddress&);
    bool remove(const HostName&);
    IPAddress lookup(const HostName&) const;
};

#endif
