#pragma once
#include <bits/stdc++.h>

static void FFT(std::vector<std::complex<double>> &vec, bool invert) {
    int32_t n = vec.size();
    const double PI = std::acos(-1);

    for (int32_t i = 1, j = 0; i < n; ++i) {
        int32_t bit = n >> 1;

        for (; j & bit; bit >>= 1) {
            j ^= bit;
        }

        j ^= bit;

        if (i < j) {
            std::swap(vec[i], vec[j]);
        }
    }

    for (int32_t len = 2; len <= n; len <<= 1) {
        const double ang = 2 * PI / len * (invert ? -1.0 : 1.0);

        std::complex<double> wlen(std::cos(ang), std::sin(ang));

        for (int i = 0; i < n; i += len) {
            std::complex<double> w(1);

            for (int j = 0; j < len / 2; ++j) {
                auto u = vec[i + j];
                auto v = vec[i + j + len / 2] * w;
                vec[i + j] = u + v;
                vec[i + j + len / 2] = u - v;
                w *= wlen;
            }
        }
    }

    if (invert) {
        for (auto &x : vec) {
            x /= n;
        }
    }
}

