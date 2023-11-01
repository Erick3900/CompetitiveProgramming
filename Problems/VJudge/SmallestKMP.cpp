// VJudge
// SmallestKMP 
// 
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

int main(int, char *[]) {
    std::ios_base::sync_with_stdio(false), 
        std::cin.tie(nullptr), 
        std::cout.tie(nullptr);

    int n;

    std::cin >> n;

    std::string txt;
    std::string pat;

    while (n--) {
        std::cin >> txt;
        std::cin >> pat;

        std::array<int, 26> occs = { 0 };

        for (auto &c : pat) {
            occs[c - 'a']++;
        }

        std::string x;
        x.reserve(txt.size() - pat.size());

        for (auto &e : txt) {
            if (occs[e - 'a'] > 0) {
                occs[e - 'a']--;
            }
            else x.push_back(e);
        }

        std::sort(x.begin(), x.end());
        
        auto pos = std::upper_bound(
            x.begin(),
            x.end(),
            pat.front()
        );

        for (auto it = x.begin(); it != pos; ++it) {
            std::cout << *it;
        }

        std::cout << pat;

        for (auto it = pos; it != x.end(); ++it) {
            std::cout << *it;
        }

        std::cout << '\n';
    }
}
