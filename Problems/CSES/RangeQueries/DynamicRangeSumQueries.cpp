// CSES/RangeQueries
// DynamicRangeSumQueries 
// https://cses.fi/problemset/task/1648/
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

#include "DataStructures/FenwickTree.hpp"

int main(int argc, char *argv[]) {
    std::ios_base::sync_with_stdio(false), 
        std::cin.tie(nullptr), 
        std::cout.tie(nullptr);

    int n, m, q, i, d;

    std::cin >> n >> m;

    std::vector<int> nums(n);

    for (auto &e : nums) {
        std::cin >> e;
    }

    FenwickTree t(nums);

    while (m--) {
        std::cin >> q >> i >> d;
        --i;

        if (q == 1) {
            t.updateAdd(i, d - nums[i]);
            nums[i] = d;
        }
        else if (q == 2) {
            --d;
            std::cout << t.querySum(i, d) << '\n';
        }
        else assert(false);
    }

}
