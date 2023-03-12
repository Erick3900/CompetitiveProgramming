// CSES/Introductory
// PalindromeReorder 
// URL: https://cses.fi/problemset/task/1755
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

    std::string line;

    std::cin >> line;

    std::array<int64_t, ('Z' - 'A' + 1)> chars = { 0 };

    for (const auto &c : line) {
        chars[c - 'A']++;
    }
    
    int64_t oddPos = -1;

    for (size_t i = 0; i < chars.size(); ++i) {
        auto &c = chars[i];
        if (c & 1) {
            if (oddPos != -1) {
                std::cout << "NO SOLUTION\n";
                return 0;
            }
            else {
                oddPos = i;
            }
        }
    }

    std::string ans;

    for (size_t i = 0; i < chars.size(); ++i) {
        if (i == oddPos) {
            continue;
        }

        for (int j = 0; j < (chars[i] >> 1); ++j) {
            ans += ('A' + i);
        }
    }

    deb(oddPos);

    std::cout << ans;

    if (oddPos != -1) {
        for (int i = 0; i < chars[oddPos]; ++i) {
            std::cout << char('A' + oddPos);
        }
    }
    
    std::reverse(ans.begin(), ans.end());

    std::cout << ans << '\n';
}
