// CSES/Graphs
// PoliceChase.cpp 
// URL: https://cses.fi/problemset/task/1695
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

    int n, m;

    std::cin >> n >> m;

    Graph g(n);

    int u, v;
    
    for (int i = 0; i < m; ++i) {
        std::cin >> u >> v;
        g.add_edge(u - 1, v - 1, 1, true);
    }

    auto maxFlow = EdmondKarp().run(g, 0, n - 1);

    std::cout << maxFlow << std::endl;

    std::unordered_set<Graph::Node> visited;
    std::queue<Graph::Node> st;

    st.push(0);
    visited.insert(0);

    while (! st.empty()) {
        auto curr = st.front();
        st.pop();

        for (auto id : g.adj[curr]) {
            auto &edge = g.edges[id];
            
            if (edge.capacity == 0) {
                continue;
            }

            if (visited.count(edge.to) == 0) {
                if ((edge.capacity - edge.flow) > 0) {
                    visited.insert(edge.to);
                    st.push(edge.to);
                }
            }
        }
    }

    for (auto node : visited) {
        for (auto id : g.adj[node]) {
            auto &edge = g.edges[id];

            if (edge.capacity != 0 && visited.count(edge.to) == 0) {
                std::cout << (edge.from + 1) << ' ' << (edge.to + 1) << '\n';
            }
        }
    }
}
