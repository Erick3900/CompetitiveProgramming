// Kattis
// PolynomialMultiplication 
// URL: https://open.kattis.com/problems/polymul2
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

    int n, a, b;

    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        std::cin >> a;
        std::vector<int32_t> fa(a + 1);
        
        for (auto &e : fa) {
            std::cin >> e;
        }

        std::cin >> b;
        std::vector<int32_t> fb(b + 1);

        for (auto &e : fb) {
            std::cin >> e;
        }

        auto res = PolynomialMultiplication(fa, fb);

        std::cout << (a + b) << '\n';

        for (int i = 0; i < (a + b + 1); ++i) {
            std::cout << res[i] << ' ';
        }

        std::cout << '\n';
    }
}
