#pragma once

#include <bits/stdc++.h>

std::vector<int> ZFunction(std::string_view str) {
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
