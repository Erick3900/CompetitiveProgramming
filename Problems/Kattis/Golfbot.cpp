// Kattis
// Golfbot 
// URL: https://open.kattis.com/problems/golfbot
// Date: Thursday March 09, 2023
//
// Author: Erick Saúl
// Github: @Erick3900
// Twitter: @Erick_Alcachofa
// Mastodon: @alcachofa@social.linux.pizza

#include <bits/stdc++.h>

#include "Math/PolynomialMultiplication.hpp"

int main(int argc, char *argv[]) {
    std::ios_base::sync_with_stdio(false), 
        std::cin.tie(nullptr), 
        std::cout.tie(nullptr);

    int n;
    int x;

    std::cin >> n;
    int maxVal = 0;

    std::unordered_set<int> possible;

    for (int i = 0; i < n; ++i) {
        std::cin >> x;
        possible.insert(x);
        maxVal = std::max(maxVal, x);
    }

    std::vector<int> values(maxVal + 1, 0);

    for (const auto &v : possible) {
        values[v] = 1;
    }

    auto res = PolynomialMultiplication(values, values);

    for (int i = 0; i < (maxVal * 2 + 1); ++i) {
        if (res[i]) {
            possible.insert(i);
        }
    }

    std::cin >> n;

    int ans = 0;

    for (int i = 0; i < n; ++i) {
        std::cin >> x;
        if (possible.count(x)) {
            ans++;
        }
    }

    std::cout << ans << '\n';
}
