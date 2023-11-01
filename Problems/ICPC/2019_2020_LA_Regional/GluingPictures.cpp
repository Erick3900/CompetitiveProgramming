// competitive-programming
// GluingPictures 
// 
// Date: Wednesday October 18, 2023
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

#include "Strings/Trie.hpp"

int main(int argc, char *argv[]) {
    std::ios_base::sync_with_stdio(false), 
        std::cin.tie(nullptr), 
        std::cout.tie(nullptr);

    std::string text, x;

    int n;

    std::cin >> text >> n;

    Trie t;

    for (int i = 0; i < text.size(); ++i) {
        t.insert(std::string_view{text.begin() + i, text.end()});
    }

    for (int i = 0; i < n; ++i) {
        std::cin >> x;

        int ans = 0;
        int idx = 0;

        while (idx < x.size()) {
            auto l_idx = idx;

            auto curr = t.root;
            auto n = UppercaseOffset(x[idx]);

            while(idx < x.size() and curr->childs[n] != nullptr) {
                curr = curr->childs[n];
                n = UppercaseOffset(x[++idx]);
            }

            if (l_idx == idx) {
                ans = -1;
                break;
            }

            ++ans;
        }

        std::cout << ans << '\n';
    }

}
