#pragma once

#include <bits/stdc++.h>

struct UFDS {
    using Node = int32_t;

    int32_t size;
    std::vector<Node> parents;

    UFDS(Node n) 
        : size(n)
        , parents(n) { 
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
            --size;
        }
    }

    bool connected(Node from, Node to) {
        return ufind(from) == ufind(to);
    }
};

