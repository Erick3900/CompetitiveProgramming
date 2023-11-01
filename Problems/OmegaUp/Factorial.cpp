// OmegaUp
// Factorial 
// URL: https://omegaup.com/arena/problem/Factorial-de-un-numero-/#problems
// Date: Tuesday March 21, 2023
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

    std::cin >> n;

    std::array<int64_t, 15> fact;

    fact[0] = 1;

    for (int64_t i = 1; i <= n; ++i) {
        fact[i] = i * fact[i - 1];
    }
    
    std::cout << fact[n] << std::endl;
}
