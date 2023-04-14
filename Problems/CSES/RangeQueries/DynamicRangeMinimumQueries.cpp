// RangeQueries
// DynamicRangeMinimumQueries 
// https://cses.fi/problemset/task/1649
// Date: Thursday April 13, 2023
//
// Author: Erick Saúl
// Github: @Erick3900
// Twitter: @Erick_Alcachofa
// Mastodon: @alcachofa@social.linux.pizza

#include <bits/stdc++.h>

#define _DEBUG
#ifdef _DEBUG
#    define deb(x) std::clog << #x << " = " << x << std::endl;
#    define deb2(x, y) std::clog << #x << " = " << x << "\t|\t" << #y << " = " << y << std::endl;
#    define debug(x) { x };
#else
#    define deb(x)
#    define deb2(x, y)
#    define debug(x)
#endif

#include "DataStructures/SegmentTree.hpp"

int main(int argc, char *argv[]) {
    std::ios_base::sync_with_stdio(false), 
        std::cin.tie(nullptr), 
        std::cout.tie(nullptr);

    int n, m, q, l, r;

    std::cin >> n >> m;

    std::vector<int> values(n);

    for (auto &e : values) {
        std::cin >> e;
    }

    SegmentTree t{ values };

    while (m--) {
        std::cin >> q >> l >> r;
        --l;

        if (q == 1) {
            t.update(l, r);
        }
        else {
            --r;

            std::cout << t.query(l, r) << '\n';
        }
    }
}

