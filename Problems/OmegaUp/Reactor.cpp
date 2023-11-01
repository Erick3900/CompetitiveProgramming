// OmegaUp
// Reactor 
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

int n;

bool has_cycles;

std::vector<bool> visited;
std::vector<bool> vis_st;
std::vector<bool> on_cycles;

std::stack<int> amb_rad;
std::vector<int> fail_sources;
std::vector<std::vector<int>> graph;

void dfs(int c) {
    vis_st[c] = true;
    visited[c] = true;

    if (graph[c].empty()) {
        amb_rad.push(c);
    }
    else {
        for (const auto &x : graph[c]) {
            ++fail_sources[x];

            if (not visited[x]) {
                dfs(x);
            }
            else {
                if (vis_st[x]) {
                    has_cycles = true;
                    on_cycles[x] = true;
                }
            }

        }
    }

    vis_st[c] = false;
}


int main(int argc, char *argv[]) {
    std::ios_base::sync_with_stdio(false), 
        std::cin.tie(nullptr), 
        std::cout.tie(nullptr);

    int m, r, u, v;

    std::cin >> n >> m >> r;

    --r;

    visited.resize(n, false);
    vis_st.resize(n, false);
    graph.resize(n);

    on_cycles.resize(n, false);

    has_cycles = false;

    fail_sources.resize(n, 0);

    ++fail_sources[r];

    for (int i = 0; i < m; ++i) {
        std::cin >> u >> v;

        --u, --v;

        graph[u].push_back(v);
    }

    dfs(r);

    if (not has_cycles) {
        std::cout << "B\n";
    }
    else {
        char ans = 'G';

        for (auto &x : fail_sources) {
            if (x > 1) {
                ans = 'S';
                break;
            }
        }

        std::cout << ans << '\n';
    }

    std::cout << amb_rad.size() << ' ';
}
