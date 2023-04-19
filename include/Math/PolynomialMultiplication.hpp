#pragma once
#include "Math/FFT.hpp"

static std::vector<int32_t> PolynomialMultiplication(const std::vector<int32_t> &a, const std::vector<int32_t> &b) {
    std::vector<std::complex<double>> fa(a.begin(), a.end());
    std::vector<std::complex<double>> fb(b.begin(), b.end());

    int32_t n = 1;

    while (n < (a.size() + b.size())) {
        n <<= 1;
    }

    fa.resize(n);
    fb.resize(n);

    FFT(fa, false);
    FFT(fb, false);

    for (int32_t i = 0; i < n; ++i) {
        fa[i] *= fb[i];
    }

    FFT(fa, true);

    std::vector<int32_t> result(n);

    for (int i = 0; i < n; ++i) {
        result[i] = std::round(fa[i].real());
    }

    return result;
}
