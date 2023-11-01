// 2023_GPM2
// IronFistKetil_vs_KingCanute 
// 
// Date: Sunday June 04, 2023
//
// Author: Erick Saúl
// Github: @Erick3900
// Twitter: @Erick_Alcachofa
// Mastodon: @alcachofa@social.linux.pizza

#include <bits/stdc++.h>

int main(int argc, char *argv[]) {
    std::ios_base::sync_with_stdio(false), 
        std::cin.tie(nullptr), 
        std::cout.tie(nullptr);

    int64_t n, m, k;

    std::cin >> n >> m >> k;

    auto required = m * k;

    if (n >= required) {
        std::cout << "Iron fist Ketil\n";
    }
    else {
        std::cout << "King Canute\n";
    }

}
