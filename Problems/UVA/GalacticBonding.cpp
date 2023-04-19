// UVA
// GalacticBonding 
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=16&page=show_problem&problem=3117
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

#include "Graphs/UFDS.hpp"

int main(int argc, char *argv[]) {
    std::ios_base::sync_with_stdio(false), 
        std::cin.tie(nullptr), 
        std::cout.tie(nullptr);

    int t, cs = 0;

    std::cin >> t;

    while (t--) {
        int n;
        double d, x, y;

        std::cin >> n >> d;
    
        UFDS uf(n);
        std::vector<std::pair<double, double>> stars;
        stars.reserve(n);

        for (int i = 0; i < n; ++i) {
            std::cin >> x >> y;

            stars.push_back(std::make_pair(x, y));
        }

        for (int i = 0; i < n; ++i) {
            const auto &stI = stars[i];
            for (int j = i + 1; j < n; ++j) {
                const auto &stJ = stars[j];
                double dist = std::hypot(stI.first - stJ.first, stI.second - stJ.second);
            
                if (dist < d) {
                    uf.unite(i, j);
                }
            }
        }

        std::cout << "Case " << ++cs << ": " << uf.size << '\n';
    }


}
