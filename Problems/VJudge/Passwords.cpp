// CompetitiveProgramming
// Passwords 
// 
// Date: Tuesday April 11, 2023
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

#include "Strings/KMPSearch.hpp"

int kmp[1000100];

int main(int argc, char *argv[]) {
    std::ios_base::sync_with_stdio(false), 
        std::cin.tie(nullptr), 
        std::cout.tie(nullptr);

    freopen("/home/alcachofa/dev/competitive-programming/CompetitiveProgramming/in", "r+", stdin);

    std::string input;

    std::cin >> input;

    KMPFunction(kmp, input);

    int max = -1;
    std::unordered_set<int> s;

    auto sz = input.size();
    bool firstCase = true;
    bool otherCase = false;
    bool lastRepeated = false;

    for (int i = 1; i < (sz - 1); ++i) {
        if (kmp[i] != 0 && firstCase) {
            if (((kmp[i - 1]) + 1) != kmp[i]) {
                firstCase = false;
            }
        }

        if (kmp[i] == kmp[sz - 1]) {
            if (lastRepeated) {
                otherCase = true;
            }
            lastRepeated = true;
        }

        max = std::max(max, kmp[i]);
    }

    if (firstCase) {
        std::cout << input << '\n';
    }
    else {
        if (max == kmp[sz - 1]) {
            if (lastRepeated && ! otherCase) {
                std::cout << input.substr(0, max) << '\n';
                return 0;
            }
        }

        std::cout << "Just a legend\n";
    }
}
