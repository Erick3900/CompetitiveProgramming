// Kattis
// Where's my internet??
// URL: https://open.kattis.com/problems/wheresmyinternet 
//
// Author: Erick Saúl
// Github: @Erick3900
// Twitter: @Erick_Alcachofa
// Mastodon: @alcachofa@social.linux.pizza

#include <bits/stdc++.h>

std::vector<bool> visited;

void bfs(const std::vector<std::vector<int>> &graph, int node) {
    visited[node] = true;

    std::queue<int> q;
    q.push(node);

    while (! q.empty()) {
        node = q.front();
        q.pop();

        for (auto &neigh : graph.at(node)) {
            if (! visited[neigh]) {
                visited[neigh] = true;
                q.push(neigh);
            }
        }
    }
}

int main(int argc, char *argv[]) {
    std::ios_base::sync_with_stdio(false), 
        std::cin.tie(nullptr), 
        std::cout.tie(nullptr);

    int n, m, u, v;

    std::cin >> n >> m;

    std::vector<std::vector<int>> graph(n);
    visited.resize(n, false);

    for (int i = 0; i < m; ++i) {
        std::cin >> u >> v;

        graph[u - 1].push_back(v - 1);
        graph[v - 1].push_back(u - 1);
    }

    bool missing = false;

    bfs(graph, 0);

    for (int i = 0; i < n; ++i) {
        if (! visited[i]) {
            std::cout << (i + 1) << '\n';
            missing = true;
        }
    }

    if (! missing) {
        std::cout << "Connected\n";
    }
}
