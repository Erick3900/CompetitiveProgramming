#pragma once

#include <bits/stdc++.h>

std::vector<int> KMPFunction(const std::string &pattern) {
    int i = 0, j = -1;
    int m = pattern.size();

    std::vector<int> kmp(m, 0);

    kmp[0] = -1;

    while (i < m) {
        while (j >= 0 && pattern[i] != pattern[j]) {
            j = kmp[j];
        }

        ++i;
        ++j;

        kmp[i] = j;
    }
    
    return kmp;
}

