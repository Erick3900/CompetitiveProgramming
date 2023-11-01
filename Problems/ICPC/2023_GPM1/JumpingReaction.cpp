// 2023_GPM1
// JumpingReaction
//
// Date: Thursday May 18, 2023
//
// Author: Erick Saúl
// Github: @Erick3900
// Twitter: @Erick_Alcachofa
// Mastodon: @alcachofa@social.linux.pizza

#include <bits/stdc++.h>

constexpr int64_t MOD = (1e9 + 7LL);

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

// Modular Inverse, valid only if MOD is prime
constexpr int64_t mod_inv(int64_t a) {
    return bin_pow(a, MOD - 2);
}

int main(int, char *[]) {
    std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr);

    int n, q;

    std::cin >> n >> q;

    struct data {
        int64_t value;
        int64_t prefSum;
        int64_t sqPrefSum;
    };

    std::vector<data> values(n + 1, { 0, 0, 0 });

    for (int i = 1; i <= n; ++i) {
        std::cin >> values[i].value;

        values[i].prefSum = (values[i].value + values[i - 1].prefSum) % MOD;
        values[i].sqPrefSum = ((values[i].value * values[i].value) % MOD + values[i - 1].sqPrefSum) % MOD;
    }

    int l, r;

    constexpr auto TWO_MOD_INV = mod_inv(2); // (1e9 + 4) / 2

    while (q--) {
        std::cin >> l >> r;

        auto sqPrefSum = ((values[r].sqPrefSum - values[l - 1].sqPrefSum) + MOD) % MOD;
        auto prefSum = ((values[r].prefSum - values[l - 1].prefSum) + MOD) % MOD;
        prefSum = (prefSum * prefSum) % MOD;

        auto ans = ((prefSum - sqPrefSum) + MOD) % MOD;
        ans = (ans * TWO_MOD_INV) % MOD;

        std::cout << ans << '\n';
    }
}
