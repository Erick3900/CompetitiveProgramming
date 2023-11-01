// Random
// SunAndMoon 
// 
// Date: Saturday August 12, 2023
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

    int ss, sc, ms, mc;

    std::cin >> ss >> sc >> ms >> mc;

    int cs, cm;

    cs = sc - (ss % sc);
    cm = mc - (ms % mc);

    while (cs != cm) {
        if (cs < cm) {
            cs += sc;
        }
        else {
            cm += mc;
        }
    }

    std::cout << cs << '\n';
}
