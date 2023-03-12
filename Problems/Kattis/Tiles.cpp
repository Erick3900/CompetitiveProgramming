// Kattis
// Tiles 
// URL: https://open.kattis.com/problems/tiles
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

    std::vector<int32_t> divisors(500002, 2);

    for (int i = 2; (i * 2) < divisors.size(); ++i) {
        for (int j = 2; (i * j) < divisors.size(); ++j) {
            divisors[j * i]++;
        }
    }

    divisors[0] = 0;
    divisors[1] = 1;

    auto res = PolynomialMultiplication(divisors, divisors);

    int n;

    std::cin >> n;

    int a, b;

    for (int i = 0; i < n; ++i) {
        std::cin >> a >> b;

        int sz = 0;
        int szIdx = 0;

        for (int j = a; j <= b; ++j) {
            if (res[j] > sz) {
                sz = res[j];
                szIdx = j;
            }
        }

        std::cout << szIdx << ' ' << sz << '\n';
    }
}
