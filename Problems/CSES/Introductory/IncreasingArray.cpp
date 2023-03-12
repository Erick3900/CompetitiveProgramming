// CSES/Introductory
// IncreasingArray 
// URL: https://cses.fi/problemset/task/1094
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

    int n, lt, t;

    std::cin >> n;

    int64_t ans = 0;

    std::cin >> t;

    for (int i = 1; i < n; ++i) {
        lt = t;
        std::cin >> t;

        if (lt > t) {
            ans += (lt - t);
            t = lt;
        }
    }

    std::cout << ans << '\n';
}
