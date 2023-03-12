// CSES/SortingAndSearching
// DistinctNumbers 
// URL: https://cses.fi/problemset/task/1621
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

    int64_t n, t;
    
    std::cin >> n;

    std::vector<int64_t> nums;

    nums.reserve(n);

    for (int64_t i = 0; i < n; ++i) {
        std::cin >> t;
        nums.push_back(t);
    }

    std::sort(nums.begin(), nums.end());

    size_t diffs = 1;

    for (size_t i = 1; i < nums.size(); ++i) {
        if (nums[i] != nums[i - 1]) {
            ++diffs;
        }
    }

    std::cout << diffs << '\n';
}
