// 2023_2024_LA_MX_Finals
// ForwardAndBackward
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

bool is_palindrome(int64_t n, int64_t base) {
    std::list<int64_t> num;

    while (n != 0) {
        num.push_back(n % base);
        n /= base;
    }

    auto bit = num.rbegin();
    auto fit = num.begin();

    auto sz = num.size() >> 1;

    for (size_t i = 0; i < sz; ++i) {
        if (*bit != *fit) {
            return false;
        }

        ++bit;
        ++fit;
    }

    return true;
}

int main(int argc, char *argv[]) {
    std::ios_base::sync_with_stdio(false), 
        std::cin.tie(nullptr), 
        std::cout.tie(nullptr);

    int64_t n;

    std::cin >> n;

    if (n == 2) {
        std::cout << "*\n";
        return 0;
    }

    std::set<int64_t> ans;

    ans.insert(n - 1);

    for (int64_t i = 2; i <= std::ceil(std::sqrt(n - 1)); ++i) {
        if (n % i) {
            if (is_palindrome(n, i)) {
                ans.insert(i);
            }
        }
    }

    for (int i = -1 + std::sqrt(1 + n); i >= 1; --i) {
        if ((n % i) == 0) {
            if ((n / i - 1) >= 2) {
                ans.insert(n / i - 1);
            }
        }
    }

    for (auto v : ans) {
        std::cout << v << ' ';
    }

    std::cout << '\n';
}
