// OmegaUp
// RecursividadBeta 
// URL: https://omegaup.com/arena/problem/Recursividad-Beta/#problems
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

std::unordered_map<int64_t, int64_t> memo;

int64_t solve(int64_t n) {
    if (auto it = memo.find(n); it != memo.end()) {
        return it->second;
    }

    if (n <= 15) {
        memo[n] = n + n * 3;    
    }
    else {
        memo[n] = solve(n - 10) * 5;
    }

    std::cout << memo[n] << '\n';

    return memo[n];
}

int main(int argc, char *argv[]) {
    std::ios_base::sync_with_stdio(false), 
        std::cin.tie(nullptr), 
        std::cout.tie(nullptr);

    int n;

    std::cin >> n;

    solve(n);
}
