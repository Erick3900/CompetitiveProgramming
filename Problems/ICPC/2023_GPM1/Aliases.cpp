// 2023_GPM1
// Aliases 
// 
// Date: Thursday May 18, 2023
//
// Author: Erick Saúl
// Github: @Erick3900
// Twitter: @Erick_Alcachofa
// Mastodon: @alcachofa@social.linux.pizza

#include <bits/stdc++.h>

int main(int, char *[]) {
    std::ios_base::sync_with_stdio(false), 
        std::cin.tie(nullptr);

    int n;

    std::cin >> n;

    std::unordered_map<std::string, int> uks;

    for (int i = 0; i < n; ++i) {
        int t;
        std::string word;

        std::string alias;

        std::cin >> t;

        alias.reserve(t);

        for (int j = 0; j < t; ++j) {
            std::cin >> word;
            alias.push_back(word.at(0));
        }

        ++uks[alias];
    }

    int ans = 0;

    for (auto &u : uks) {
        if (u.second == 1) {
            ++ans;
        }
    }

    std::cout << ans << '\n';
}
