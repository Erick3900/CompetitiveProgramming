// CSES/SortingAndSearching
// Apartments 
// URL: https://cses.fi/problemset/task/1084
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

    int64_t n, m, k;

    std::cin >> n >> m >> k;

    std::vector<int64_t> applicants(n);
    std::vector<int64_t> apartments(m);

    for (auto &a : applicants) {
        std::cin >> a;
    }

    for (auto &a : apartments) {
        std::cin >> a;
    }

    std::sort(applicants.begin(), applicants.end());
    std::sort(apartments.begin(), apartments.end());

    size_t apartId = 0;
    size_t appliId = 0;

    size_t ans = 0;

    while (appliId < n && apartId < m) {
        while (appliId < n && apartId < m && std::abs(apartments[apartId] - applicants[appliId]) > k) {
            if (apartments[apartId] > applicants[appliId]) {
                ++appliId;
            }
            else ++apartId;
        }
       
        if (appliId < n && apartId < m) {
            ++ans;
        }

        ++appliId;
        ++apartId;
    }

    std::cout << ans << '\n';
}
