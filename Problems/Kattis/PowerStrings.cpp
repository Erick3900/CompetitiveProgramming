// Kattis
// PowerStrings 
// https://open.kattis.com/problems/powerstrings
// Date: Wednesday April 12, 2023
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

#include "Strings/ZSearch.hpp"

int main(int argc, char *argv[]) {
    std::ios_base::sync_with_stdio(false), 
        std::cin.tie(nullptr), 
        std::cout.tie(nullptr);

    std::string line;
    
    while (std::getline(std::cin, line) && line != ".") {
        auto z = ZFunction(line);

        auto rs = 0;

        for (int i = 0; i < line.size(); ++i) {
            if (z[i] == ((int) line.size() - i)) {
                rs = i;
                break;
            }
        }

        if (rs == 0) {
            std::cout << 1 << '\n';
            continue;
        }

        std::cout << (line.size() / rs) << '\n';
    }
}
