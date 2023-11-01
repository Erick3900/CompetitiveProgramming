// 2023_GPM2
// DraconisSubarrays 
// 
// Date: Sunday June 04, 2023
//
// Author: Erick Saúl
// Github: @Erick3900
// Twitter: @Erick_Alcachofa
// Mastodon: @alcachofa@social.linux.pizza

#include <bits/stdc++.h>

// File: 'Strings/ZSearch.hpp'

std::vector<int> ZFunction(const std::vector<int64_t> &str) {
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

// EOF: Strings/ZSearch.hpp

int main(int argc, char *argv[]) {
    std::ios_base::sync_with_stdio(false), 
        std::cin.tie(nullptr), 
        std::cout.tie(nullptr);

    int n, m, last, current;

    std::cin >> n >> m;

    if (n == 1) {
        std::cout << m << '\n';
        return 0;
    }

    std::vector<int64_t> magical_array(n - 1);
    std::vector<int64_t> mystical_array(m - 1);

    std::cin >> last;

    for (auto &e : magical_array) {
        std::cin >> current;
        e = current - last;
        last = current;
    }

    std::cin >> last;

    for (auto &e : mystical_array) {
        std::cin >> current;
        e = current - last;
        last = current;
    }

    std::vector<int64_t> z_array(n + m - 1);

    std::copy_n(magical_array.begin(), n - 1, z_array.begin());
    std::copy_n(mystical_array.begin(), m - 1, z_array.begin() + n);

    z_array[n - 1] = -(1e9 + 10);

    auto ans = ZFunction(z_array);

    std::cout << std::count(ans.begin(), ans.end(), n - 1) << '\n';
}

