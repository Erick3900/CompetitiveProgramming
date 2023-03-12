// CSES/Graphs
// DownloadSpeed 
// URL: https://cses.fi/problemset/task/1694
// Date: Thursday March 09, 2023
//
// Author: Erick Saúl
// Github: @Erick3900
// Twitter: @Erick_Alcachofa
// Mastodon: @alcachofa@social.linux.pizza

#include <bits/stdc++.h>

#include "Graphs/FordFulkerson.hpp"

int main(int argc, char *argv[]) {
    std::ios_base::sync_with_stdio(false), 
        std::cin.tie(nullptr), 
        std::cout.tie(nullptr);

    int n, m , u, v, w;

    std::cin >> n >> m;

    Graph g(n);

    for (int i = 0; i < m; ++i) {
        std::cin >> u >> v >> w;

        g.add_edge(u - 1, v - 1, w);
    }

    auto MF = EdmondKarp();

    std::cout << MF.run(g, 0, n - 1) << '\n';
}
