#pragma once
#include <bits/stdc++.h>

struct Graph {
    using Node = int32_t;
    using Weight = int64_t;

    const Weight INF = std::numeric_limits<Weight>::max();

    struct Edge {
        Node from;
        Node to; 

        Weight capacity;
        Weight flow;
    };

    std::size_t n;

    std::vector<Edge> edges;
    std::vector<std::vector<std::size_t>> adj;

    Graph(std::size_t N)
        : n(N)
        , edges()
        , adj(N) {
    }

    void add_edge(Node from, Node to, Weight weight = 1, bool undirected = false) {
        edges.push_back({ from, to, weight, 0 });
        adj[from].push_back(edges.size() - 1);

        edges.push_back({ to, from, undirected ? weight : 0, 0 });
        adj[to].push_back(edges.size() - 1);
    }
};
