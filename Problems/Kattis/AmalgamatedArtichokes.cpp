// Kattis
// AmalgamatedArtichokes 
// URL: https://icpc.kattis.com/problems/artichoke
// Date: Thursday March 09, 2023
//
// Author: Erick Saúl
// Github: @Erick3900
// Twitter: @Erick_Alcachofa
// Mastodon: @alcachofa@social.linux.pizza

#include <bits/stdc++.h>

int main(int argc, char *argv[]) {
    std::ios_base::sync_with_stdio(false), 
        std::cin.tie(nullptr), 
        std::cout.tie(nullptr);

    double p, a, b, c, d, n;

    std::cin >> p >> a >> b >> c >> d >> n;

    auto price = [&] (double k) {
        return p * (std::sin(a * k + b) + std::cos(c * k + d) + 2.0);
    };

    double maxPrice = 0.0;
    double maxDiff = 0.0;

    for (int i = 1; i <= n; ++i) {
        auto currPrice = price(i);
        
        if (currPrice > maxPrice) {
            maxPrice = currPrice;
            continue;
        }

        auto diff = maxPrice - currPrice;
        maxDiff = std::max(maxDiff, diff);
    }

    std::cout << std::fixed << std::setprecision(9) << maxDiff << '\n';
}
