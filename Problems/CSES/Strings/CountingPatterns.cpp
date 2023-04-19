// CSES/Strings
// CountingPatterns
// https://cses.fi/problemset/task/2103/
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

#include "Strings/AhoCorasick.hpp"

int main(int argc, char *argv[]) {
    std::ios_base::sync_with_stdio(false),
        std::cin.tie(nullptr),
        std::cout.tie(nullptr);
 
    std::string text;
    std::string pattern;
 
    std::cin >> text;
 
    int k;
 
    std::cin >> k;
 
    AhoCorasick t;
    
    std::vector<int> parents(k);
    std::vector<int> results(k, 0);

    for (int i = 0; i < k; ++i) {
        std::cin >> pattern;
        auto uid = t.addString(pattern, i);
        parents[i] = uid;
    }
    t.prepareAho();

    t.preprocessString(text, [&](int wid, int) {
        results[wid]++; 
    });
 
    for (int i = 0; i < k; ++i) {
        auto p = parents[i];
 
        std::cout << results[p] << '\n';
    }
}
