// Kattis
// NatureReserve
// URL: https://open.kattis.com/problems/naturereserve
// Date: Wednesday March 15, 2023
//
// Author: Erick Saúl
// Github: @Erick3900
// Twitter: @Erick_Alcachofa
// Mastodon: @alcachofa@social.linux.pizza

#include <bits/stdc++.h>
#include <limits>
#include <queue>

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

#include "Graphs/SizeRankedUFDS.hpp"

void solve();

int main(int argc, char *argv[]) {
    std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);

    int t;

    std::cin >> t;

    while (t--) {
        solve();
    }
}

void solve() {
    constexpr auto INF = std::numeric_limits<int64_t>::max();

    int n, m, l, s, u, v, w;

    std::cin >> n >> m >> l >> s;

    SizeRankedUFDS uf(n + 1);
    std::vector<bool> connected(n + 1, false);
    std::vector<std::tuple<int64_t, int64_t, int64_t>> edges;

    for (int i = 0; i < s; ++i) {
        std::cin >> u;
        connected[u] = true;
        uf.unite(0, u);
    }

    for (int i = 0; i < m; ++i) {
        std::cin >> u >> v >> w;
        edges.push_back({ u, v, w });
    }

    std::sort(edges.begin(), edges.end(), [](const auto &a, const auto &b) {
        return std::get<2>(a) < std::get<2>(b);
    });

    int64_t ans = 0;

    for (const auto &e : edges) {
        auto from = std::get<0>(e);
        auto to = std::get<1>(e);
        auto cost = std::get<2>(e);

        if (connected[uf.ufind(from)] && connected[uf.ufind(to)] || uf.connected(from, to)) {
            continue;
        }
        else {
            uf.unite(from, to);
            ans += (cost + l);
        }
    }

    std::cout << ans << '\n';
}
