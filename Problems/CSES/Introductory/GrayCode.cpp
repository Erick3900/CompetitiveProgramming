// CSES/Introductory
// GrayCode 
// URL: https://cses.fi/problemset/task/2205
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

    int n;

    std::cin >> n;

    const std::string Zeroes(n, '0');

    std::vector<std::string> grayCode(1LL << n, Zeroes);

    int Count = 1LL << n;

    for (size_t i = 0; i < n; ++i) {
        int curr = Count >> 1;
        bool zero = true;

        for (int j = 0; j < grayCode.size(); ++j) {
            if (zero) {
                grayCode[j][i] = '0';
            }
            else {
                grayCode[j][i] = '1';
            }

            curr++;

            if (curr == Count) {
                curr = 0;
                zero = !zero;
            }
        }

        Count >>= 1;
    }

    for (const auto &str : grayCode) {
        std::cout << str << '\n';
    }
}
