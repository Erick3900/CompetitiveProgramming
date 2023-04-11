// 2022_2023_LA_Regional
// DailyTrips 
// URL: https://codeforces.com/gym/104252/problem/D
// Date: Monday March 27, 2023
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

int main(int argc, char *argv[]) {
    std::ios_base::sync_with_stdio(false), 
        std::cin.tie(nullptr), 
        std::cout.tie(nullptr);

    int n, h, w;
    char rh, rc;

    std::cin >> n >> h >> w;

    for (int i = 0; i < n; ++i) {
        std::cin >> rh >> rc;

        if (rh == 'Y') {
            if (h > 0) {
                --h;
                ++w;
                std::cout << "Y ";
            }
            else {
                std::cout << "N ";
            }
        }
        else {
            if (h > 0 && w == 0) {
                --h;
                ++w;
                std::cout << "Y ";
            }
            else {
                std::cout << "N ";
            }
        }

        if (rc == 'Y') {
            if (w > 0) {
                --w;
                ++h;
                std::cout << "Y\n";
            }
            else {
                std::cout << "N\n";
            }
        }
        else {
            if (w > 0 && h == 0) {
                --w;
                ++h;
                std::cout << "Y\n";
            }
            else {
                std::cout << "N\n";
            }
        }
    }
}
