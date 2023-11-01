// 2023_GPM1
// BucketStoring 
// 
// Date: Thursday May 18, 2023
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

    int n, k, l;

    std::cin >> n >> k >> l;

    std::cout << std::ceil(double(n * k) / double(l)) << std::endl;
}
