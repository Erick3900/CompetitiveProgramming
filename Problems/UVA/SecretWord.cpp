// UVA Online Judge
// SecretWord
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3911
// Date: Monday April 10, 2023
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

// File: 'Strings/ZSearch.hpp'

std::vector<int> ZFunction(const std::string &str) {
    int n = str.size();
    
    std::vector<int> z(n, 0);

    int x = 0; 
    int y = 0;

    for (int i = 1; i < n; ++i) {
        z[i] = std::max(0, std::min(z[i - x], y - i  + 1));

        while (i + z[i] < n && str[z[i]] == str[i + z[i]]) {
            x = i;
            y = i + z[i];
            z[i]++;
        }
    }

    return z;
}

std::vector<int> ZFunction(const std::string &pat, const std::string &txt) {
    return ZFunction(pat + '#' + txt);
}

// EOF: Strings/ZSearch.hpp

int main(int, char *[]) {
    std::ios_base::sync_with_stdio(false), 
        std::cin.tie(nullptr), 
        std::cout.tie(nullptr);

    std::string text, pattern;
    int n;
    std::cin >> n;

    while (n--) {
        std::cin >> text;

        pattern = text;
        std::reverse(text.begin(), text.end());

        auto z = ZFunction(pattern, text);
        int sz = pattern.size();

        auto max = 0;

        for (int i = sz + 1; i < z.size(); ++i) {
            max = std::max(max, z[i]);
        }

        for (int i = 0; i < max; ++i) {
            std::cout << pattern[max - i - 1];
        }

        std::cout << "\n";
    }
}

