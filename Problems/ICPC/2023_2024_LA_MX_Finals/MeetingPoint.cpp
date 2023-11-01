// 2023_2024_LA_MX_Finals
// MeetingPoint
//
// Date: Wednesday October 25, 2023
//
// Author: Erick Saúl
// Github: @Erick3900
// Twitter: @Erick_Alcachofa
// Mastodon: @alcachofa@social.linux.pizza

#include <bits/stdc++.h>

#ifdef _DEBUG
#    define deb(x) std::clog << #x << " = " << x << std::endl;
#    define deb2(x, y) std::clog << #x << " = " << x << "\t|\t" << #y << " = " << y << std::endl;
#    define debug(x) { x };
#else
#    define deb(x)
#    define deb2(x, y)
#    define debug(x)
#endif

constexpr int inf = std::numeric_limits<int>::max() - (1e9 + 7);

struct edge {
    int to;
    int weight;

    bool operator<(const edge &other) const {
        if (weight != other.weight) {
            return weight < other.weight;
        }

        return to < other.to;
    }
};

std::vector<int> dijkstra(int src, const std::vector<std::vector<edge>> &graph, int node_to_ignore = -1) {
    std::set<edge> q;

    std::vector<int> dist(graph.size(), inf);

    q.insert({ src, 0 });
    dist[src] = 0;

    while (not q.empty()) {
        auto u = q.begin()->to;
        q.erase(q.begin());

        for (const auto &[v, w] : graph[u]) {
            if (v == node_to_ignore)
                continue;

            if (dist[v] > dist[u] + w) {
                q.erase({ v, dist[v] });
                dist[v] = dist[u] + w;
                q.insert({ v, dist[v] });
            }
        }
    }

    return dist;
}

int main(int argc, char *argv[]) {
    std::ios_base::sync_with_stdio(false),
        std::cin.tie(nullptr),
        std::cout.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    int s, e;
    std::cin >> s >> e;

    --s, --e;

    int u, v, w;

    std::vector<std::vector<edge>> graph(n);

    for (int i = 0; i < m; ++i) {
        std::cin >> u >> v >> w;

        --u, --v;

        graph[u].push_back({ v, w });
        graph[v].push_back({ u, w });
    }

    auto with_e = dijkstra(s, graph);
    auto without_e = dijkstra(s, graph, e);

    auto expected_dist = with_e[e] * 2;
    bool at_least_one = false;

    for (int i = 0; i < n; ++i) {
        if (with_e[i] == expected_dist and with_e[i] < without_e[i]) {
            at_least_one = true;
            std::cout << (i + 1) << ' ';
        }
    }

    if (not at_least_one) {
        std::cout << "*\n";
    }
    else {
        std::cout << '\n';
    }
}
