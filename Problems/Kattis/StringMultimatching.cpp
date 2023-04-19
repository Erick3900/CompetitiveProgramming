// Kattis
// StringMultimatching 
// 
// Date: Sunday April 16, 2023
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

    int n;
    std::string pattern;
    std::vector<int> lengths;
    std::vector<std::list<int>> matches;

    while (std::cin >> n) {
        std::cin.ignore();

        AhoCorasick ac;
        std::vector<int> parents(n);

        matches.clear();
        matches.resize(n);

        lengths.resize(n);
        
        for (int i = 0; i < n; ++i) {
            std::getline(std::cin, pattern);

            int uid = ac.addString(pattern, i);
            lengths[i] = pattern.length();
            parents[i] = uid;
        }
        ac.prepareAho();

        std::getline(std::cin, pattern);

        ac.preprocessString(pattern, [&] (int wid, int pos) {
            matches[wid].push_back(pos - lengths[wid]);
        });

        for (int i = 0; i < n; ++i) {
            for (auto match : matches[parents[i]]) {
                std::cout << match << ' ';
            }
            std::cout << '\n';
        }
    }

}
