// 2023_GPM2
// FibonacciFever 
// 
// Date: Sunday June 04, 2023
//
// Author: Erick Saúl
// Github: @Erick3900
// Twitter: @Erick_Alcachofa
// Mastodon: @alcachofa@social.linux.pizza

#include <bits/stdc++.h>

constexpr int64_t MOD = (1e9 + 7);

constexpr int64_t bin_pow(int64_t a, int64_t b) {
    a %= MOD;

    int64_t res = 1;

    while (b > 0) {
        if (b & 1)
            res = res * a % MOD;

        a = a * a % MOD;
        b >>= 1;
    }

    return res;
}

int64_t pisano(int64_t m) {
    int64_t temp;
    int64_t prev = 0;
    int64_t curr = 1;

    int64_t res = 0;

    for (int64_t i = 0; i < (m * m); ++i) {
        temp = curr;
        curr = (prev + curr) % m;
        prev = temp;

        if (prev == 0 and curr == 1) {
            res = i + 1;
        }
    }

    return res;
}

const auto P = 150016;

int main(int argc, char *argv[]) {
    std::ios_base::sync_with_stdio(false), 
        std::cin.tie(nullptr), 
        std::cout.tie(nullptr);

    int64_t n, k;

    std::cin >> n >> k;

    auto nn = n % P - 1;

    int64_t rest_sum = 1;
    int64_t total_sum = 1;

    int64_t temp;
    int64_t prev = 0;
    int64_t curr = 1;

    for (int64_t i = 0; i < P; ++i) {
        temp = curr;
        curr = (prev + curr) % MOD;
        prev = temp;

        auto exp = bin_pow(curr, k);
        total_sum += exp;

        if (i < nn) {
            rest_sum += exp;
        }
    }

    total_sum = (total_sum * (n / P)) % MOD;
    total_sum += rest_sum;

    total_sum %= MOD;

    std::cout << total_sum << '\n';
}
