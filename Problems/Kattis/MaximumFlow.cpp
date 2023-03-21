// Kattis
// MaximumFlow 
// URL: https://open.kattis.com/problems/maxflow
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

    int n, m, s, t, u, v, w;

    std::cin >> n >> m >> s >> t;

    Graph g(n);

    for (int i = 0; i < m; ++i) {
        std::cin >> u >> v >> w;
        g.add_edge(u, v, w);
    }

    auto MF = EdmondKarp();

    auto maxFlow = MF.run(g, s, t);

    std::cout << n << ' ' << maxFlow << ' ';

    int count = 0;
    std::stringstream ss;

    for (const auto &edge : g.edges) {
        if (edge.capacity != 0 && edge.flow > 0) {
            count++;
            ss << edge.from << ' ' << edge.to << ' ' << edge.flow << '\n';
        }
    }

    std::cout << count << '\n';
    std::cout << ss.str();
}
