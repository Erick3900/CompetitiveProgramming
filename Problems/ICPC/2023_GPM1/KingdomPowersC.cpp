// 2023_GPM1
// KingdomPowersC 
// 
// Date: Monday May 15, 2023
//
// Author: Erick Saúl
// Github: @Erick3900
// Twitter: @Erick_Alcachofa
// Mastodon: @alcachofa@social.linux.pizza

#include <bits/stdc++.h>

#include "Graphs/FordFulkerson.hpp"

int main(int, char *[]) {
    std::ios_base::sync_with_stdio(false), 
        std::cin.tie(nullptr), 
        std::cout.tie(nullptr);

    int n, s, e, t, u, v;

    std::cin >> n >> s >> e;

    std::vector<int> startingLevels(s, 0);
    std::vector<int> endingLevels(e, 0);

    Graph g((n + 2) * 2);

    for (auto &i : startingLevels) {
        std::cin >> i;
    }

    for (auto &i : endingLevels) {
        std::cin >> i;
    }
    
    for (int i = 0; i <= n; ++i) {
        g.add_edge(i * 2, i * 2 + 1);
    }

    for (auto &i : startingLevels) {
        g.add_edge(1, i * 2);
    }
 
    for (auto &i : endingLevels) {
        g.add_edge(i * 2 + 1, (n + 1) * 2);
    }

    std::cin >> t;

    for (int i = 0; i < t; ++i) {
        std::cin >> u >> v;
        g.add_edge(u * 2 + 1, v * 2);
    }

    std::cout << Dinic{}.run(g, 1, (n + 1) * 2) << '\n';
}

