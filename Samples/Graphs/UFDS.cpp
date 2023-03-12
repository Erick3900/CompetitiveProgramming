// Graphs
// Where's my internet?? - Kattis
// URL; https://open.kattis.com/problems/wheresmyinternet 
//
// Author: Erick Saúl
// Github: @Erick3900
// Twitter: @Erick_Alcachofa
// Mastodon: @alcachofa@social.linux.pizza

#include <bits/stdc++.h>

#include "Graphs/UFDS.hpp"

int main(int argc, char *argv[]) {
    std::ios_base::sync_with_stdio(false), 
        std::cin.tie(nullptr), 
        std::cout.tie(nullptr);

    int n, m, u, v;

    std::cin >> n >> m;

    UFDS uf(n);

    for (int i = 0; i < m; ++i) {
        std::cin >> u >> v;

        uf.unite(u - 1, v - 1);
    }

    bool missing = false;

    for (int i = 0; i < n; ++i) {
        if (! uf.connected(0, i)) {
            std::cout << (i + 1) << '\n';
            missing = true;
        }
    }

    if (! missing) {
        std::cout << "Connected\n";
    }
}
