// VJudge
// RADutyScheduler *
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

    int m, n, k, d;

    std::cin >> m >> n;

    Graph g(m + n + 2);

    std::unordered_map<Graph::Node, std::string> names;
    
    std::string ra;

    for (int i = 1; i <= m; ++i) {
        std::cin >> ra >> k;

        names[i] = ra;
        
        for (int j = 0; j < k; ++j) {
            std::cin >> d;

            g.add_edge(i, m + d);
        }
    }

    auto maxIdx = g.edges.size();

    for (int i = 1; i <= m; ++i) {
        g.add_edge(0, i, 3);
    }

    for (int i = 1; i <= n; ++i) {
        g.add_edge(m + i, m + n + 1, 2);
    }

    auto maxFlow = EdmondKarp().run(g, 0, m + n + 1);

    std::map<int, std::vector<int>> days;
    std::map<int, int> count;

    auto maxCount = 0;

    for (int i = 1; i <= n; ++i) {
        for (auto id : g.adj[m + i]) {
            auto &edge = g.edges[id ^ 1];

            if (edge.capacity != 0 && edge.flow > 0) {
                days[edge.to - m].push_back(edge.from);
                count[edge.from]++;
                
                maxCount = std::max(maxCount, count[edge.from]);
            }
        }
    }

    std::cout << maxCount << '\n';

    for (const auto p : days) {
        auto &d = p.first;
        auto &k = p.second;

        std::cout << "Day " << d << ": ";

        for (const auto &i : k) {
            std::cout << names[i] << ' ';
        }

        std::cout << std::endl;
    }
}
