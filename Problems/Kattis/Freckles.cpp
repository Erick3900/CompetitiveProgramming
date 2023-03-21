// Kattis
// Freckles 
// https://open.kattis.com/problems/freckles
// Date: Wednesday March 15, 2023
//
// Author: Erick Saúl
// Github: @Erick3900
// Twitter: @Erick_Alcachofa
// Mastodon: @alcachofa@social.linux.pizza

#include <bits/stdc++.h>
#include <limits>

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

void solve();

int main(int argc, char *argv[]) {
    std::ios_base::sync_with_stdio(false), 
        std::cin.tie(nullptr), 
        std::cout.tie(nullptr);

    int n;

    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        solve();
    }

}

void solve() {
    int n;

    std::cin >> n;

    std::vector<std::pair<double, double>> points(n);

    for (auto &p : points) {
        std::cin >> p.first >> p.second;
    }

    std::vector<std::vector<double>> g(n, std::vector<double>(n, std::numeric_limits<double>::max()));

    for (int u = 0; u < n; ++u) {
        for (int v = u + 1; v < n; ++v) {
            g[u][v] = std::min(
                std::hypot(
                    points[u].first - points[v].first, 
                    points[u].second - points[v].second
                ), 
                g[u][v]
            );

            g[v][u] = g[u][v];
        }
    }

    std::vector<int> parent(n);
    std::vector<int> key(n, std::numeric_limits<int>::max());
    std::vector<bool> mstSet(n, false);

    key[0] = 0;
    parent[0] = -1;

    for (int cnt = 0; cnt < n - 1; ++cnt) {
        int u = [&] {
            int minV = std::numeric_limits<int>::max();
            int minI;

            for (int v = 0; v < n; ++v) {
                if (mstSet[v] == false && key[v] < minV) {
                    minV = key[v];
                    minI = v;
                }    
            }

            return minI;
        }();

        mstSet[u] = true;

        for (int v = 0; v < n; ++v) {
            if (std::abs(g[u][v]) > 1e-6 && mstSet[v] == false && g[u][v] < key[v]) {
                parent[v] = u;
                key[v] = g[u][v];
            }
        }
    }

    double total = 0;

    for (int i = 1; i < n; ++i) {
        total += g[i][parent[i]];
    }

    std::cout << std::fixed << std::setprecision(2) << total << "\n\n";
}
