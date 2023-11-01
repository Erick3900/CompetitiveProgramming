// Kattis
// BuildDependencies 
// URL: https://open.kattis.com/problems/builddeps
// Date: Friday March 10, 2023
//
// Author: Erick Saúl
// Github: @Erick3900
// Twitter: @Erick_Alcachofa
// Mastodon: @alcachofa@social.linux.pizza

#include <bits/stdc++.h>

int main(int argc, char *argv[]) {
    std::ios_base::sync_with_stdio(false), 
        std::cin.tie(nullptr), 
        std::cout.tie(nullptr);

    int n;

    std::cin >> n;

    std::string line;

    std::cin.ignore();

    std::unordered_map<std::string, std::unordered_set<std::string>> graph;

    for (int i = 0; i < n; ++i) {
        std::getline(std::cin, line);

        auto divPos = line.find_first_of(':');
        auto rule = line.substr(0, divPos);

        if (! graph.count(rule)) {
            graph.insert({ rule, {} });
        }

        std::stringstream in{ line.substr(divPos + 1) };

        while (in >> line) {
            graph[line].insert(rule);
        }
    }

    std::cin >> line;

    const auto topologicalSort = [&]() -> std::list<std::string> {
        std::unordered_map<std::string, bool> visited;
        std::list<std::string> order;

        std::function<void(const std::string &)> dfs;

        dfs = [&] (const std::string &node) -> void {
            visited[node] = true;

            for (const auto &neigh : graph[node]) {
                if (! visited[neigh]) {
                    dfs(neigh);
                }
            }

            order.push_back(node);
        };

        for (const auto &it : graph) {
            auto &k = it.first;
            if (! visited[k])
                dfs(k);
        }

        return order;
    };

    auto order = topologicalSort();

    std::unordered_set<std::string> rebuild;
    std::queue<std::string> q;

    q.push(line);
    rebuild.insert(line);

    while (! q.empty()) {
        auto curr = q.front();
        q.pop();

        for (const auto &dep : graph.at(curr)) {
            if (! rebuild.count(dep)) {
                q.push(dep);
                rebuild.insert(dep);
            }
        }
    }
    
    for (auto it = order.crbegin(); it != order.crend(); ++it) {
        if (rebuild.count(*it)) {
            std::cout << *it << '\n';
        }
    }
}
