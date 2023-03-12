#pragma once

#include <bits/stdc++.h>

#include "Graphs/FlowGraph.hpp"

struct Dinic {
    Graph::Node source;
    Graph::Node sink;

    std::vector<std::size_t> ptr;
    std::vector<int64_t> level;

    Graph::Weight run(Graph &g, Graph::Node source, Graph::Node sink) {
        this->sink = sink;
        this->source = source;
        ptr.resize(g.n);
        level.resize(g.n);

        Graph::Weight flow = 0;

        while (true) {
            if (! bfs(g)) {
                break;
            }

            std::fill(ptr.begin(), ptr.end(), 0);

            Graph::Weight pushed;

            while ((pushed = dfs(g, source, g.INF)) != 0) {
                flow += pushed;
            }
        }

        return flow;
    }

    bool bfs(Graph &g) {
        std::fill(level.begin(), level.end(), -1);

        level[source] = 0;

        std::queue<Graph::Node> q;

        q.push(source);

        while (! q.empty()) {
            auto v = q.front();
            q.pop();

            for (auto id : g.adj[v]) {
                if ((g.edges[id].capacity - g.edges[id].flow) < 1) {
                    continue;
                }

                if (level[g.edges[id].to] != -1) {
                    continue;
                }

                level[g.edges[id].to] = level[v] + 1;
                q.push(g.edges[id].to);
            }
        }

        return level[sink] != -1;
    }

    Graph::Weight dfs(Graph &g, Graph::Node from, Graph::Weight pushed) {
        if (pushed == 0 || from == sink) {
            return pushed;
        }

        for (auto &cid = ptr[from]; cid < g.adj[from].size(); ++cid) {
            auto id = g.adj[from][cid];
            auto to = g.edges[id].to;

            if ((level[from] + 1) != level[to] || (g.edges[id].capacity - g.edges[id].flow) < 1) {
                continue;
            }

            auto tr = dfs(g, to, std::min(pushed, g.edges[id].capacity - g.edges[id].flow));

            if (tr == 0) {
                continue;
            }

            g.edges[id].flow += tr;
            g.edges[id ^ 1].flow -= tr;
            
            return tr;
        }
        
        return 0;
    }

};

struct EdmondKarp {
    Graph::Node source;
    Graph::Node sink;

    std::vector<std::size_t> ptr;
    std::vector<int64_t> parents;

    Graph::Weight run(Graph &g, Graph::Node source, Graph::Node sink) {
        this->sink = sink;
        this->source = source;
        ptr.resize(g.n);
        parents.resize(g.n);

        Graph::Weight flow = 0;
        Graph::Weight pushed;

        while ((pushed = bfs(g)) != 0) {
            flow += pushed;

            Graph::Node curr = sink;

            while (curr != source) {
                g.edges[ptr[curr]].flow += pushed;
                g.edges[ptr[curr] ^ 1].flow -= pushed;

                curr = parents[curr];
            }
        }

        return flow;
    }

    Graph::Weight bfs(Graph &g) {
        std::fill(parents.begin(), parents.end(), -1);

        ptr[source] = 0;
        parents[source] = -2;

        std::queue<std::pair<Graph::Node, Graph::Weight>> q;

        q.push({ source, g.INF });

        while (! q.empty()) {
            auto curr = q.front().first;
            auto flow = q.front().second;
            q.pop();

            for (const auto &id : g.adj[curr]) {
                auto &edge = g.edges[id];
                
                if (parents[edge.to] == -1 && (edge.capacity - edge.flow) != 0) {
                    ptr[edge.to] = id;
                    parents[edge.to] = curr;

                    auto new_flow = std::min(flow, edge.capacity - edge.flow);

                    if (edge.to == sink) {
                        return new_flow;
                    }

                    q.push({ edge.to, new_flow });
                }
            }
        }

        return 0;
    }
};
