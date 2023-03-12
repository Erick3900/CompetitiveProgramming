// CSES/Introductory
// Repetitions 
// URL: https://cses.fi/problemset/task/1069
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

    std::string line;

    std::cin >> line;

    std::size_t currCount = 0;
    std::size_t maxCount = 0;
    char lastChar = ' ';

    for (int i = 0; i < line.size(); ++i) {
        if (line.at(i) == lastChar) {
            ++currCount;
        }
        else {
            maxCount = std::max(maxCount, currCount);
            lastChar = line.at(i);
            currCount = 1;
        }
    }

    maxCount = std::max(maxCount, currCount);

    std::cout << maxCount << '\n';
}
