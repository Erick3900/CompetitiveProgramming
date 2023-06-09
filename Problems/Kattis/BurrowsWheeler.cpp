// Kattis
// BurrowsWheeler 
// https://open.kattis.com/problems/burrowswheeler
// Date: Monday April 10, 2023
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

#include "Strings/SuffixArray.hpp"

int main(int argc, char *argv[]) {
    std::ios_base::sync_with_stdio(false), 
        std::cin.tie(nullptr), 
        std::cout.tie(nullptr);

    std::string input;

    while (std::getline(std::cin, input)) {
        auto suffixArray = SuffixArray(input + input);

        for (std::size_t i = 0; i < suffixArray.size(); ++i) {
            if (suffixArray[i] < input.length()) {
                auto c = ((suffixArray[i] == 0) ? input.length() : suffixArray[i]) - 1;
                std::cout << input[c];
            }
        }
        std::cout << '\n';
    }
}

