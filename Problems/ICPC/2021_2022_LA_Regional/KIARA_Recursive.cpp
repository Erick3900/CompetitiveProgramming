// KIARA is a recursive acronym
// GluingPictures 
// 
// Date: Wednesday October 18, 2023
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

    std::array<bool, 26> letters;

    std::fill(letters.begin(), letters.end(), false);

    std::string s;

    int n;

    std::cin >> n;

    std::vector<std::string> strs;

    strs.reserve(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> s;

        strs.push_back(s);

        letters[s[0] - 'A'] = true;
    }

    for (int i = 0; i < n; ++i) {
        bool all = true;

        for (auto c : strs[i]) {
            if (not letters[c - 'A']) {
                all = false;
                break;
            }
        }

        if (all) {
            std::cout << "Y\n";
            return 0;
        }
    }

    std::cout << "N\n";
}

