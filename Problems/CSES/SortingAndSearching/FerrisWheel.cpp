// CSES/SortingAndSearching
// FerrisWheel 
// URL: https://cses.fi/problemset/task/1090
// Date: Saturday March 11, 2023
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

    int64_t n, x, t;

    std::cin >> n >> x;

    std::vector<int64_t> childs(n);

    for (auto &c : childs) {
        std::cin >> c;
    }
    
    std::sort(childs.begin(), childs.end());

    int64_t lPtr = 0;
    int64_t rPtr = n - 1;

    size_t ans = 0;

    while (lPtr <= rPtr) {
        while (lPtr < rPtr && childs.at(lPtr) + childs.at(rPtr) > x) {
            ++ans;
            --rPtr;
        }
        
        if (lPtr <= rPtr) {
            ++ans;
        }

        ++lPtr;
        --rPtr;
    }

    std::cout << ans << '\n';
}
