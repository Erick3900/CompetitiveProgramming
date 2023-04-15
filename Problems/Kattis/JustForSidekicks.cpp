// Kattis
// JustForSidekicks 
// https://open.kattis.com/problems/justforsidekicks
// Date: Thursday April 13, 2023
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

#include "DataStructures/SegmentTree.hpp"

using Gems = std::array<int, 6>;
constexpr auto GemsZero = std::array<int, 6>{ 0, 0, 0, 0, 0, 0 };

Gems FTaskGemsSum(const Gems &a, const Gems &b) {
    return Gems {
        a[0] + b[0], a[1] + b[1],
        a[2] + b[2], a[3] + b[3],
        a[4] + b[4], a[5] + b[5]
    };
}

Gems FTransform(int gemType) {
    auto ret = GemsZero;
    ret[gemType] = 1;
    return ret;
}

int main(int, char *[]) {
    std::ios_base::sync_with_stdio(false), 
        std::cin.tie(nullptr), 
        std::cout.tie(nullptr);

    int n, q;

    std::cin >> n >> q;

    std::array<int64_t, 6> gems;

    for (auto &v : gems) {
        std::cin >> v;
    }

    std::vector<int> listGems;
    listGems.reserve(n);

    char g;

    for (int i = 0; i < n; ++i) {
        std::cin >> g;
        listGems.push_back(g - '1');
    }

    int t, l, r;

    SegmentTree<Gems, decltype(&FTaskGemsSum)> st{ &FTaskGemsSum, GemsZero };

    st.build(listGems, FTransform);

    while (q--) {
        std::cin >> t >> l >> r;
        --l;

        if (t == 1) {
            --r;
            st.update(l, r, FTransform);
        }
        else if (t == 2) {
            gems[l] = r;
        }
        else {
            --r;
            auto quant = st.query(l, r);
            int64_t ans = 0;
            
            for (int i = 0; i < 6; ++i) {
                ans += (static_cast<int64_t>(quant[i]) * gems[i]);
            }

            std::cout << ans << '\n';
        }
    }
}

