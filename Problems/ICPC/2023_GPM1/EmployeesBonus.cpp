// 2023_GPM1
// EmployeesBonus 
// 
// Date: Thursday May 18, 2023
//
// Author: Erick Saúl
// Github: @Erick3900
// Twitter: @Erick_Alcachofa
// Mastodon: @alcachofa@social.linux.pizza

#include <bits/stdc++.h>

int n;

std::vector<int> subtree_sizes;
std::vector<std::vector<int>> tree;

int subtree_size(int node) {
    if (subtree_sizes[node] != 0) {
        return subtree_sizes[node];
    }

    if (tree[node].empty()) {
        return subtree_sizes[node] = 1;
    }

    int size = 1;

    for (auto child : tree[node]) {
        size += subtree_size(child);
    }

    return subtree_sizes[node] = size;
}

int main(int argc, char *argv[]) {
    std::ios_base::sync_with_stdio(false), 
        std::cin.tie(nullptr), 
        std::cout.tie(nullptr);

    int q, u, v;

    std::cin >> n >> q;

    std::vector<std::tuple<int, int, int>> money(n, { 0, 0, -1 });

    for (auto &m : money) {
        std::cin >> std::get<0>(m);
    }

    subtree_sizes.resize(n, 0);
    tree.resize(n);

    for (int i = 0; i < (n - 1); ++i) {
        std::cin >> u >> v;

        --u, --v;

        tree[u].push_back(v);
    }

    for (int i = 0; i < n; ++i) {
        [[maybe_unused]] auto _ = subtree_size(i);
    }

    for (int i = 0; i < q; ++i) {
        std::cin >> u >> v;

        --u;

        auto bonus = (v / subtree_sizes[u]);

        if ((v % subtree_sizes[u]) != 0) {
            std::get<1>(money[u]) += (v % subtree_sizes[u]);
        }

        std::queue<int> bfs_queue;

        bfs_queue.push(u);

        while (! bfs_queue.empty()) {
            auto curr_node = bfs_queue.front();
            bfs_queue.pop();

            std::get<1>(money[curr_node]) += bonus;

            if (std::get<2>(money[curr_node]) == -1) {
                if (std::get<1>(money[curr_node]) >= std::get<0>(money[curr_node])) {
                    std::get<2>(money[curr_node]) = (i + 1);
                }
            }

            for (auto child : tree[curr_node]) {
                bfs_queue.push(child);
            }
        }
    }

    for (const auto &m : money) {
        std::cout << std::get<2>(m) << '\n';
    }
}
