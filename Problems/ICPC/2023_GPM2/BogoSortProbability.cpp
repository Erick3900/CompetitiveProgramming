// 2023_GPM2
// BogoSortProbability 
// 
// Date: Sunday June 04, 2023
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

std::array<int64_t, static_cast<size_t>(1e6 + 10)> fact_memo{ 0 };
int64_t last_fact = 1;

int64_t fact(int64_t n) {
    if (fact_memo[n] != 0) {
        return fact_memo[n];
    }

    auto val = fact_memo[last_fact];

    for (int i = last_fact + 1; i <= n; ++i) {
        val = (val * i) % MOD;
        fact_memo[i] = val;
    }

    last_fact = n;


    return val;
}

int main(int argc, char *argv[]) {
    std::ios_base::sync_with_stdio(false), 
        std::cin.tie(nullptr), 
        std::cout.tie(nullptr);

    fact_memo[0] = 1;
    fact_memo[1] = 1;

    int n, k, i, v;

    std::cin >> n >> k;

    std::vector<int64_t> nums(n);
    std::unordered_map<int64_t, int64_t> count;

    for (auto &e : nums) {
        std::cin >> e;
        count[e]++;
    }

    int64_t curr_prob = 1;

    for (const auto &[_, c] : count) {
        if (c > 1) {
            curr_prob = (curr_prob * fact(c)) % MOD;
        }
    }

    const auto total_prob = mod_inv(fact(n));

    std::cout << (curr_prob * total_prob) % MOD << '\n';

    for (auto itm = 0; itm < k; ++itm) {
        std::cin >> i >> v;

        --count[nums[--i]];

        if (count[nums[i]] >= 1) {
            // Divide to 'reduce' the possible sorted permutations
            curr_prob = (curr_prob * mod_inv(count[nums[i]] + 1)) % MOD;
        }

        if (++count[v] >= 2) {
            // Multiply to 'add' the possible new sorted permutations
            curr_prob = (curr_prob * count[v]) % MOD;
        }

        nums[i] = v;

        std::cout << (curr_prob * total_prob) % MOD << '\n';
    }
}
