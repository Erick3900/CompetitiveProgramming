// CSES/Graphs
// DistinctRoutes *
// URL: https://cses.fi/problemset/task/1710
// Date: Friday March 10, 2023
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

    int n, m, u, v;

    std::cin >> n >> m;

    Graph g(n);

    for (int i = 0; i < m; ++i) {
        std::cin >> u >> v;
        g.add_edge(u - 1, v - 1, 1, true);
    }

    auto maxFlow = EdmondKarp().run(g, 0, n - 1);

    std::cout << maxFlow << std::endl;
}
