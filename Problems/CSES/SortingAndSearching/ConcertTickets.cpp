// CSES/SortingAndSearching
// ConcertTickets *
// URL: https://cses.fi/problemset/task/1091
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

    int64_t n, m;

    std::cin >> n >> m;

    using pi = std::pair<int64_t, int64_t>;

    std::vector<int64_t> tickets(n);
    std::vector<int64_t> clients(m);
    std::vector<bool> bought(m, false);

    for (auto &t : tickets) {
        std::cin >> t;
    }

    int64_t maxC = 0;

    for (size_t idx = 0; idx < clients.size(); ++idx) {
        std::cin >> clients[idx];
        maxC = std::max(maxC, clients[idx]);
    }

    std::sort(tickets.begin(), tickets.end());

    while (tickets.back() > maxC)
        tickets.pop_back();

    for (int64_t cIdx = 0; cIdx < clients.size(); ++cIdx) {
        auto it = --std::upper_bound(tickets.begin(), tickets.end(), clients[cIdx]);

        if (*it > clients[cIdx]) {
            std::cout << "-1\n"; 
        }
        else {
            int64_t idx = it - tickets.begin();

            while (idx >= 0 && bought[idx]) {
                --idx;
            }

            if (idx < 0) {
                std::cout << "-1\n";
            }
            else {
                std::cout << tickets[idx] << '\n';
                bought[idx] = true;

                if (idx == (tickets.size() - 1)) {
                    tickets.pop_back();
                }
            }
        }
    }
}
