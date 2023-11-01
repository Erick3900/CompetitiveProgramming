#include <bits/stdc++.h>

#include "Math/PolynomialMultiplication.hpp"

constexpr int64_t MAX = 1e6;

int *data;

int main() {
    // for (int i = 1; i <= 7; ++i) {
    //     matr[i] = 1;
    // }

    // auto res = PolynomialMultiplication(matr, matr);

    // for (int i = 1; i < 16; ++i) {
    //     std::cout << std::setw(2) << i << ' ';
    // }

    // std::cout << '\n';

    // for (int i = 1; i < 16; ++i) {
    //     res[i] = res[i] + res[i - 1];
    //     std::cout << std::setw(2) << res[i] << ' ';
    // }

    // std::cout << std::endl;
    
    // int data[8][8] = {
    //     { 0, 0, 0, 0,  0,  0,  0,  0},
    //     { 0, 0, 2, 3,  4,  5,  6,  7 },
    //     { 0, 0, 0, 6,  8, 10, 12, 14 },
    //     { 0, 0, 0, 0, 12, 15, 18, 21 },
    //     { 0, 0, 0, 0,  0, 20, 24, 28 },
    //     { 0, 0, 0, 0,  0,  0, 30, 35 },
    //     { 0, 0, 0, 0,  0,  0,  0, 42 }
    // };

    // std::vector<std::vector<int>> sums(9, std::vector<int>(9, 0));

    // for (int i = 1; i <= 7; ++i) {
    //     for (int j = 1; j <= 7; ++j) {
    //         sums[i][j] = data[i][j] + sums[i - 1][j] + sums[i][j - 1] - sums[i - 1][j - 1];
    //     }
    // }

    // for (auto &r : sums) {
    //     for (auto &s : r) {
    //         std::cout << std::setw(5) << s << ' ';
    //     }
    //     std::cout << std::endl;
    // }

    // int rm = 1;
    // int rM = 5;

    // std::cout << sums[rM][rM] - sums[rm - 1][rM] - sums[rM][rm - 1] + sums[rm - 1][rm - 1] << '\n';
}
