#pragma once
#include <bits/stdc++.h>

struct SizeRankedUFDS {
    using Node = int32_t;
    using Rank = std::size_t;

    std::vector<Node> parents;
    std::vector<Rank> rank;

    SizeRankedUFDS(Node n) 
        : parents(n)
        , rank(n, 1) { 
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
            if (rank[fromParent] < rank[toParent]) {
                std::swap(fromParent, toParent);
            }

            parents[toParent] = fromParent;
            rank[fromParent] += rank[toParent];
        }
    }

    bool connected(Node from, Node to) {
        return ufind(from) == ufind(to);
    }
};
