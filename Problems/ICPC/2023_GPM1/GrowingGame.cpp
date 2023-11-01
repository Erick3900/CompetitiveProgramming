// 2023_GPM1
// GrowingGame 
// 
// Date: Wednesday May 24, 2023
//
// Author: Erick Saúl
// Github: @Erick3900
// Twitter: @Erick_Alcachofa
// Mastodon: @alcachofa@social.linux.pizza

#include <bits/stdc++.h>

constexpr bool Jane = true;
constexpr bool John = false;

int main(int argc, char *argv[]) {
    std::ios_base::sync_with_stdio(false), 
        std::cin.tie(nullptr), 
        std::cout.tie(nullptr);

    int n;

    std::cin >> n;

    if (n == 1) {
        std::cout << "Jane\n";
        return 0;
    }

    bool turn = John;
    int nCounter = 1;

    for (int i = 2; nCounter <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            ++nCounter;

            if (nCounter == n) {
                std::cout << (turn ? "Jane" : "John") << '\n';
                return 0;
            }
        }

        turn = !turn;

        for (int j = 0; j < i; ++j) {
            ++nCounter;

            if (nCounter == n) {
                std::cout << (turn ? "Jane" : "John") << '\n';
                return 0;
            }
        }

        turn = !turn;
    }

    std::cout << (turn ? "Jane" : "John") << '\n';
}
