// 2023_2024_LA_MexicoFinals
// Inversions
//
// Date: Tuesday October 24, 2023
//
// Author: Erick Saúl
// Github: @Erick3900
// Twitter: @Erick_Alcachofa
// Mastodon: @alcachofa@social.linux.pizza

#include <bits/stdc++.h>

#ifdef _DEBUG
#    define deb(x) std::clog << #x << " = " << x << std::endl;
#    define deb2(x, y) std::clog << #x << " = " << x << "\t|\t" << #y << " = " << y << std::endl;
#    define debug(x) { x };
#else
#    define deb(x)
#    define deb2(x, y)
#    define debug(x)
#endif

constexpr int64_t mod = (1e9) + 7;

constexpr int64_t bin_pow(int64_t a, int64_t b) {
    a %= mod;

    int64_t res = 1;

    while (b > 0) {
        if (b & 1)
            res = res * a % mod;

        a = a * a % mod;
        b >>= 1;
    }

    return res;
}

// Modular Inverse, valid only if mod is prime
constexpr int64_t mod_inv(int64_t a) {
    return bin_pow(a, mod - 2);
}

int main(int argc, char *argv[]) {
    std::ios_base::sync_with_stdio(false), 
        std::cin.tie(nullptr), 
        std::cout.tie(nullptr);

    std::string input;

    int64_t n;

    int64_t ans = 0;

    std::cin >> input >> n;

    n %= mod;

    const auto mult = ((n * (((n - 1) % mod + mod)) % mod) * mod_inv(2)) % mod;

    deb(mult);

    std::array<std::vector<int>, 26> letters;

    for (int i = 0; i < input.size(); ++i) {
        letters[input[i] - 'a'].push_back(i);
    }

    for (int i = 1; i < letters.size(); ++i) {
        for (const auto &idx : letters[i]) {
            for (int j = 0; j < i; ++j) {
                auto it = std::upper_bound(letters[j].begin(), letters[j].end(), idx);

                int64_t upper = 0;
                int64_t lower = 0;

                if (it != letters[j].end()) {
                    lower = it - letters[j].begin();
                    upper = letters[j].end() - it;
                }
                else {
                    lower = letters[j].size();
                }

                deb(char(i + 'a'));
                deb2(upper, lower);

                ans += ((upper * ((mult + n) % mod)) % mod);
                ans %= mod;

                ans += ((lower * mult) % mod);
                ans %= mod;
            }
        }
    }

    std::cout << ans << '\n';
}
