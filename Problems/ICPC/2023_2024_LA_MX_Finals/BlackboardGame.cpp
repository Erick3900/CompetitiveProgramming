// 2023_2024_LA_MX_Finals/
// BlackboardGame 
// 
// Date: Wednesday October 25, 2023
//
// Author: Erick Saúl
// Github: @Erick3900
// Twitter: @Erick_Alcachofa
// Mastodon: @alcachofa@social.linux.pizza

#include <bits/stdc++.h>

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

    n *= 3;

    std::vector<int> values(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> values[i];
    }

    std::ranges::sort(values);

    int count = 1;

    for (int i = 1; i < n; ++i) {
        if (values[i] != values[i - 1]) {
            if (count % 3) {
                std::cout << 'Y' << '\n';
                return 0;
            }

            count = 1;
        }
        else {
            ++count;
        }
    }

    deb(count);

    if (count % 3) {
        std::cout << 'Y' << '\n';
        return 0;
    }

    std::cout << 'N' << '\n';
}
