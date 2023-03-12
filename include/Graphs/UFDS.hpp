#pragma once

#include <bits/stdc++.h>

struct UFDS {
    using Node = int32_t;

    std::vector<Node> parents;

    UFDS(Node n) 
        : parents(n) { 
        std::iota(parents.begin(), parents.end(), 0);
    }

    Node ufind(Node n) {
        if (parents[n] == n) {
            return n;
        }

        return parents[n] = ufind(parents[n]);
    }

    void unite(Node from, Node to) {
        auto toParent = ufind(to);
        auto fromParent = ufind(from);
        
        if (toParent != fromParent) {
            parents[toParent] = fromParent;
        }
    }

    bool connected(Node from, Node to) {
        return ufind(from) == ufind(to);
    }
};

