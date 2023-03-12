// CSES/Introductory
// BitStrings 
// URL: https://cses.fi/problemset/task/1617
// Date: Saturday March 11, 2023
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

int main(int argc, char *argv[]) {
    std::ios_base::sync_with_stdio(false), 
        std::cin.tie(nullptr), 
        std::cout.tie(nullptr);

    int64_t n;
    constexpr int64_t MOD = static_cast<int64_t>(1e9 + 7);

    std::cin >> n;

    if (n < 63) {
        std::cout << (1LL << n) % MOD << '\n';
        
        return 0;
    }

    int64_t ans = (1LL << 61) % MOD;

    for (int i = 62; i <= n; ++i) {
        ans = (ans * 2LL) % MOD;
    }

    std::cout << ans << '\n';
}
