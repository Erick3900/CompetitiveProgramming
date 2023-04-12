// UVA Online Judge
// CaesarCipher 
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4282
// Date: Tuesday April 11, 2023
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

#include "Strings/KMPSearch.hpp"

void solve();

int main(int argc, char *argv[]) {
    std::ios_base::sync_with_stdio(false), 
        std::cin.tie(nullptr), 
        std::cout.tie(nullptr);

    int n;

    std::cin >> n;

    while (n--) {
        solve();
    }

}

int kmp[60000];

void solve() {
    std::string alphabet;
    std::string word;
    std::string text;

    std::cin >> alphabet >> word >> text;

    std::unordered_map<char, int> idx;

    for (int i = 0;  i< alphabet.size(); ++i) {
        idx[alphabet[i]] = i;
    }

    KMPFunction(kmp, word);

    int X = alphabet.size();
    int n = text.size();
    int m = word.size();

    auto dsChar = [&] (char c, int ds) {
        return alphabet[(idx.at(c) + ds) % X];
    };

    std::vector<int> possible;
    possible.reserve(alphabet.size());

    for (int ds = 0; ds < X; ++ds) {
        int foundAt = std::numeric_limits<int>::max();
        bool valid = true;

        int i = 0, j = 0;

        while (i < n) {
            while (j >= 0 && word[j] != dsChar(text[i], ds)) {
                j = kmp[j];
            }

            ++i;
            ++j;

            if (j == m) {
                if (foundAt != std::numeric_limits<int>::max()) {
                    foundAt = std::numeric_limits<int>::max();
                    valid = false;
                    break;
                }
                foundAt = ds;
                j = kmp[j];
            }
        }

        if (! valid) {
            continue;
        }

        if (foundAt != std::numeric_limits<int>::max())
            possible.push_back(((X - foundAt) % X));
    }

    switch(possible.size()) {
        case 0:
            std::cout << "no solution\n";
            break;
        case 1:
            std::cout << "unique: " << possible[0] << "\n";
            break;
        default:
            std::sort(possible.begin(), possible.end());
            std::cout << "ambiguous: ";
            for (const auto &c : possible) {
                std::cout << c;
                if (c != possible.back()) {
                    std::cout << " ";
                }
            }
            std::cout << '\n';
            break;
    }
}
