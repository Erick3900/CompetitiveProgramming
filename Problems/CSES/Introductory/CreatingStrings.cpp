// CSES/Introductory
// CreatingStrings 
// URL: https://cses.fi/problemset/task/1622
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

    std::string str;

    std::cin >> str;

    std::sort(str.begin(), str.end());

    std::set<std::string> possible;
    
    do {
        possible.insert(str);
    } while (std::next_permutation(str.begin(), str.end()));

    std::cout << possible.size() << '\n';

    for (const auto &s : possible) {
        std::cout << s << '\n';
    }
}
