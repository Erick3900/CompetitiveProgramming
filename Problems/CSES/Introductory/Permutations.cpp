// CSES/Introductory
// Permutations 
// URL: https://cses.fi/problemset/task/1070
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

    int n;

    std::cin >> n;

    if (n == 1) {
        std::cout << 1 << '\n';
    }
    else if (n > 3) {
        for (int i = (n & 1 ? n : n - 1); i > 0; i -= 2) {
            std::cout << i << ' ';
        }

        for (int i = (n & 1 ? n - 1 : n); i > 0; i -= 2) {
            std::cout << i << ' ';
        }

        std::cout << '\n';
    }
    else {
        std::cout << "NO SOLUTION\n";
    }
}
