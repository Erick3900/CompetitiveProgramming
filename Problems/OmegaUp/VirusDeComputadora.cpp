// OmegaUp
// VirusDeComputadora 
// 
// Date: Friday October 20, 2023
//
// Author: Erick Saúl
// Github: @Erick3900
// Twitter: @Erick_Alcachofa
// Mastodon: @alcachofa@social.linux.pizza

#include <bits/stdc++.h>

#define _DEBUG
#ifdef _DEBUG
#    define deb(x) std::clog << #x << " = " << x << std::endl;
#    define deb2(x, y) std::clog << #x << " = " << x << "\t|\t" << #y << " = " << y << std::endl;
#    define debug(x) { x };
#else
#    define deb(x)
#    define deb2(x, y)
#    define debug(x)
#endif

int main(int argc, char *argv[]) {
    std::ios_base::sync_with_stdio(false), 
        std::cin.tie(nullptr), 
        std::cout.tie(nullptr);


    int n, m, k;

    std::cin >> n >> m >> k;

    std::vector<int> infected;
    std::vector<std::vector<int>> graph(n);

    infected.reserve(k);

    int u, v;

    for (int i = 0; i < k; ++i) {
        std::cin >> u;
        infected.push_back(--u);
    }

    for (int i = 0; i < m; ++i) {
        std::cin >> u >> v;

        --u, --v;

        graph[u].push_back(v);
    }

    std::vector<bool> visited(n, false);
    std::queue<int> q;

    int min_ans = k;

    for (auto &c : infected) {
        visited[c] = true;
        q.push(c);
    }

    for (auto &c : infected) {
        for (auto &x : graph[c]) {
            if (not visited[x]) {
                visited[x] = true;
                ++min_ans;
            }
        }
    }

    visited.assign(n, false);

    while (not q.empty()) {
        auto c = q.front();
        q.pop();

        visited[c] = true;

        for (auto &x : graph[c]) {
            if (not visited[x]) {
                q.push(x);
            }
        }
    }

    auto max_ans = std::count(visited.begin(), visited.end(), true);

    std::cout << min_ans << ' ' << max_ans << '\n';

}
