// CSES/RangeQueries
// StaticRangeSumQueries 
// https://cses.fi/problemset/task/1646
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

int main(int argc, char *argv[]) {
    std::ios_base::sync_with_stdio(false), 
        std::cin.tie(nullptr), 
        std::cout.tie(nullptr);

    int n, m;

    std::cin >> n >> m;

    std::vector<int64_t> nums(n);

    for (auto &e : nums) {
        std::cin >> e;
    }

    std::vector<int64_t> prefixSum(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
        prefixSum[i] = prefixSum[i - 1] + nums[i - 1];
    }

    int l, r;

    while (m--) {
        std::cin >> l >> r;

        std::cout << (prefixSum[r] - prefixSum[l - 1]) << '\n';
    }

}
