// CSES/Graphs
// SchoolDance 
// URL: https://cses.fi/problemset/task/1696
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

    int b, g, m, u, v;

    std::cin >> b >> g >> m;

    Graph graph(b + g + 2);

    for (int i = 0; i < m; ++i) {
        std::cin >> u >> v;

        graph.add_edge(u, v + b);
    }

    auto maxIt = graph.edges.size();

    for (int boy = 1; boy <= b; ++boy) {
        graph.add_edge(0, boy);
    }


    for (int girl = 1; girl <= g; ++girl) {
        graph.add_edge(b + girl, b + g + 1);
    }

    auto MF = EdmondKarp();

    std::cout << MF.run(graph, 0, b + g + 1) << '\n';

    for (int i = 0; i < maxIt; ++i) {
        const auto &edge = graph.edges.at(i);

        if (edge.capacity != 0 && edge.flow == 1) {
            std::cout << edge.from << ' ' << (edge.to - b) << '\n';
        }
    }
}
