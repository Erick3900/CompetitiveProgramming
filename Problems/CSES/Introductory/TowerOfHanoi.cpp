// CSES/Introductory
// TowerOfHanoi 
// URL: https://cses.fi/problemset/task/2165
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

void hanoi(int64_t n, int start, int end, int helper) {
    if (n == 0) {
        return;
    }

    hanoi(n - 1, start, helper, end);
    std::cout << start << ' ' << end << '\n';
    hanoi(n - 1, helper, end, start);
}

int main(int argc, char *argv[]) {
    std::ios_base::sync_with_stdio(false), 
        std::cin.tie(nullptr), 
        std::cout.tie(nullptr);

    int64_t n;

    std::cin >> n;

    std::cout << ((1LL << n) - 1) << '\n';

    hanoi(n, 1, 3, 2);
}
