#pragma once
#include <bits/stdc++.h>

void KMPFunction(int *kmp, const std::string &pattern) {
    int i = 0, j = -1;
    int m = pattern.size();

    kmp[0] = -1;

    while (i < m) {
        while (j >= 0 && pattern[i] != pattern[j]) {
            j = kmp[j];
        }

        ++i;
        ++j;

        kmp[i] = j;
    }
}

std::vector<int> KMPFunction(const std::string &pattern) {
    std::vector<int> kmp(pattern.size(), 0);
    
    KMPFunction(kmp.data(), pattern);

    return kmp;
}
