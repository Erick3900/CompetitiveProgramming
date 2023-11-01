// 2023_GPM2
// AlaricMagicPartition 
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

    static constexpr std::array<bool, 10> count{
        0, 1, 1, 1, 1, 1, 0, 1, 0, 1
    };

    int n;
    char v;

    int ans = 0;

    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        std::cin >> v;
        if (count.at(v - '0')) {
            ans++;
        }
    }

    std::cout << ans << '\n';
}
