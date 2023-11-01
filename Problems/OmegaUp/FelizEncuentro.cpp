// OmegaUp
// FelizEncuentro 
// 
// Date: Thursday October 19, 2023
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

    int n, q, l, r;

    std::cin >> n >> q;

    std::string str;
    std::vector<int> pre(n, 0);

    std::cin >> str;

    for (int i = 1; i < n; ++i) {
        if (str[i] == str[i - 1]) {
            pre[i] = pre[i - 1] + 1;
        }
        else {
            pre[i] = pre[i - 1];
        }
    }

    while (q--) {
        std::cin >> l >> r;

        --r, --l;

        std::cout << pre[r] - pre[l] << '\n';
    }
}
