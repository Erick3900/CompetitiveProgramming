// Kattis
// StringsMatching 
// https://open.kattis.com/problems/stringmatching
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

// #include "Strings/ZSearch.hpp"

#include "Strings/KMPSearch.hpp"

int main(int, char *[]) {
    std::ios_base::sync_with_stdio(false), 
        std::cin.tie(nullptr), 
        std::cout.tie(nullptr);

    std::string pattern, text;

    std::vector<int> data;

    while (std::getline(std::cin, pattern) && std::getline(std::cin, text)) {
        // auto z = ZFunction(pattern, text);
        // int sz = pattern.size();

        // for (int i = sz + 1; i < z.size(); ++i) {
        //     if (z[i] == sz) {
        //         std::cout << (i - sz - 1) << ' ';
        //     }
        // }

        int m = pattern.size();
        int n = text.size();

        if (data.capacity() < pattern.length()) {
            data.reserve(pattern.length());
            data.resize(pattern.length(), 0);
        }

        KMPFunction(data.data(), pattern);
        auto &kmp = data;

        int i = 0, j = 0;

        while (i < n) {
            while (j >= 0 && pattern[j] != text[i]) {
                j = kmp[j];
            }

            ++i;
            ++j;

            if (j == m) {
                std::cout << (i - j) << ' ';
                j = kmp[j];
            }
        }

        std::cout << "\n";
    }
}
