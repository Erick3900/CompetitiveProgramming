// ICPC Gran Premio México 2022 Fecha 1
// JeffreysAmbition
// URL: https://codeforces.com/problemset/gymProblem/103708/J
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

    Graph g(n + m + 2);

    int k, v;

    for (int u = 1; u <= n; ++u) {
        std::cin >> k;

        for (int i = 0; i < k; ++i) {
            std::cin >> v;
            g.add_edge(u, v + n);
        }
    }

    for (int rich = 1; rich <= n; ++rich) {
        g.add_edge(0, rich);
    }

    for (int company = 1; company <= m; ++company) {
        g.add_edge(n + company, n + m + 1);
    }

    auto MF = Dinic();

    std::cout << (m - MF.run(g, 0, n + m + 1)) << '\n';
}
