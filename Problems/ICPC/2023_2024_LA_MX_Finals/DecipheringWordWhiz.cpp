// 2023_2024_LA_MX_Finals
// DecipheringWordWhiz 
// 
// Date: Wednesday October 25, 2023
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

    std::vector<std::string> dictionary(n);

    for (auto &str : dictionary) {
        std::cin >> str;
    }

    const auto &secret_word = dictionary[0];

    std::array<char, 26> secret_letters = { 0 };

    for (const auto &c : secret_word) {
        ++secret_letters[c - 'a'];
    }

    int q;

    std::string pattern;

    std::cin >> q;

    auto eval = [&](char c, int idx, const auto &letters) {
        if (letters[c - 'a'] != 0 and letters[c - 'a'] <= secret_letters[c - 'a']) {
            if (c == secret_word[idx]) {
                return '*';
            }

            return '!';
        }

        return 'X';
    };

    while (q--) {
        std::cin >> pattern;

        int counter = 0;

        for (int it = 0; it < dictionary.size(); ++it) {
            std::array<char, 26> letters = { 0 };

            bool valid = true;

            for (int i = 0; i < pattern.size(); ++i) {
                ++letters[dictionary[it][i] - 'a'];

                if (eval(dictionary[it][i], i, letters) != pattern[i]) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                counter++;
            }
        }

        std::cout << counter << '\n';
    }

}
