// OmegaUp
// FraseOculta 
// 
// Date: Friday October 20, 2023
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

    int n, q;

    std::cin >> n >> q;

    std::string str;

    std::cin >> str;

    std::vector<std::vector<int>> poss(26);

    for (int i = 0; i < n; ++i) {
        poss[str[i] - 'a'].push_back(i);
    }

    int k;
    std::string qstr;

    while (q--) {
        std::cin >> k >> qstr;

        bool ans = true;

        int last_pos = -1;

        for (const auto &c : qstr) {
            const auto &container = poss[c - 'a'];

            auto it = std::upper_bound(container.begin(), container.end(), last_pos);

            if (it == container.end()) {
                ans = false;
                break;
            }
            else {
                last_pos = *it;
            }
        }

        std::cout << ans << '\n';
    }

}
