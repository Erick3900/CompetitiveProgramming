// VJudge
// MinimumCut *
// 
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

    auto maxFlow = Dinic().run(g, s, t);

    std::unordered_set<Graph::Node> visited;
    std::queue<Graph::Node> st;

    st.push(s);
    visited.insert(s);

    while (! st.empty()) {
        auto curr = st.front();
        st.pop();

        for (auto id : g.adj[curr]) {
            auto &edge = g.edges[id];
            
            if (edge.capacity == 0 || edge.to == t) {
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

    std::cout << visited.size() << '\n';

    for (auto node : visited) {
        std::cout << node << '\n';
    }
}
