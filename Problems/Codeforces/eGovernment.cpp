// Codeforces
// eGovernment 
// 
// Date: Saturday April 15, 2023
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

int main(int, char *[]) {
    std::ios_base::sync_with_stdio(false), 
        std::cin.tie(nullptr), 
        std::cout.tie(nullptr);

    char c;
    int q, n, x;
    std::string line;

    std::cin >> q >> n;

    AhoCorasick ac;
    std::vector<bool> isPart(n, true);

    for (int i = 0; i < n; ++i) {
        std::cin >> line;

        ac.addString(line, i);
    }

    ac.prepareAho();

    for (int iq = 0; iq < q; ++iq) {
        std::cin >> c;

        if (c == '?') {
            std::cin >> line;

            int ans = 0;

            ac.preprocessString(line, [&] (int citizen, int) {
                if (isPart[citizen]) {
                    ans += 1;
                }
            });

            std::cout << ans << '\n';
        }
        else if (c == '+') {
            std::cin >> x;

            isPart[--x] = true;
        }
        else if (c == '-') {
            std::cin >> x;

            isPart[--x] = false;
        }
    }
}
