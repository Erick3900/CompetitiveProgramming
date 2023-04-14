// Kattis
// FenwickTree 
// https://open.kattis.com/problems/fenwick
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

    int n, m, i, d;
    char q;

    std::cin >> n >> m;

    FenwickTree t(n);

    while (m--) {
        std::cin >> q >> i;

        if (q == '+') {
            std::cin >> d;

            t.updateAdd(i, d);
        }
        else if (q == '?') {
            std::cout << t.querySum(i - 1) << '\n';
        }
        else assert(false);
    }

}
