// 2023_GPM2
// KnockoutSpell 
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

    int n, k, ans = 0;

    std::cin >> n >> k;

    std::vector<std::vector<int>> matr(n, std::vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> matr[i][j];
        }
    }

    for (int i = 0; i <= (n - k); ++i) {
        for (int j = 0; j <= (n - k); ++j) {
            if (
                matr[i][j] == matr[i + k - 1][j] &&
                matr[i][j] == matr[i][j + k - 1] &&
                matr[i][j] == matr[i + k - 1][j + k - 1]
            ) {
                ans++;
            }
        }
    }

    std::cout << ans << '\n';
}
