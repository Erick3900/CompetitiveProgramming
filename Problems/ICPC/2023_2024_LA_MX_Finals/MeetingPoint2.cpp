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

struct edge {
    int to;
    int weight;
};

template <typename NodeId, typename GetNeighsT, typename IgnoreNodeT>
std::pair<std::vector<int>, std::vector<int>> dijkstra(NodeId inf, NodeId src, size_t graph_size, GetNeighsT &&get_neighs, IgnoreNodeT &&ignore) {
    std::vector<NodeId> dist(graph_size, inf);
    std::vector<NodeId> parent(graph_size, NodeId{});

    auto compare = [&] (const auto &a, const auto &b) {
        if (dist[a] != dist[b]) {
            return dist[a] < dist[b];
        }

        return a < b;
    };

    std::set<int, decltype(compare)> q(compare);

    dist[src] = 0;
    q.insert(src);

    while (not q.empty()) {
        auto u = *q.begin();
        q.erase(q.begin());

        for (const auto &[v, w] : get_neighs(u)) {
            if (ignore(v))
                continue;

            if (dist[v] > dist[u] + w) {
                q.erase(v);
                dist[v] = dist[u] + w;
                parent[v] = u;
                q.insert(v);
            }
        }
    }

    return { std::move(dist), std::move(parent) };
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

    const int inf = std::numeric_limits<int>::max() - (1e9 + 7);

    auto with_e = dijkstra(
        inf,
        s,
        graph.size(),
        [&] (auto id) { return graph[id]; },
        [&] (auto) { return false; }
    ).first;

    auto without_e = dijkstra(
        inf,
        s,
        graph.size(),
        [&] (auto id) { return graph[id]; },
        [&] (auto id) { return id == e; }
    ).first;

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
