// 2022_2023_LA_Regional
// MazeInBolt 
// 
// Date: Monday March 27, 2023
//
// Author: Erick Saúl
// Github: @Erick3900
// Twitter: @Erick_Alcachofa
// Mastodon: @alcachofa@social.linux.pizza

#include <bits/stdc++.h>
#include <vector>

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

// int total = 100;
// int vSize = 64;
// int lSize = vSize;
// int rSize = total - vSize;

// struct body {
//     uint64_t l;
//     uint64_t r;

//     body rotl(int s) {
//         if (s < 0) {
//             return this->rotr(-s);
//         }

//         auto self = *this;

//         if (s >= vSize) {
//             std::swap(self.l, self.r);
//             s -= vSize;
//         }

//         self.l = std::rotl(self.l, s);
//         self.r = std::rotl(self.r, s);

//         auto lof = (1ULL << s) - 1;
//         auto rof = ((1ULL << (vSize - rSize)) - 1) << rSize;
//         auto rst = s - (vSize - rSize);
        
//         if (rst > 0) {
//             rof |= ((1ULL << rst) - 1);
//         }

//         auto lMask = self.l & lof;
//         auto rMask = std::rotl(self.r & rof, vSize - rSize);

//         self.l = (self.l & (~lof)) | rMask;
//         self.r = (self.r & (~rof)) | lMask;

//         return self;
//     }

//     body rotr(int s) {
//         if (s < 0) {
//             return this->rotl(-s);
//         }
//         return this->rotl(total - s);
//     }
// };

// std::ostream &operator<<(std::ostream &os, const body &b) {
//     std::stringstream ss;
//     ss << std::bitset<64>(b.r) << std::bitset<64>(b.l);
//     return os << (ss.str());
// }

// std::istream &operator>>(std::istream &in, body &b) {
//     b.r = 0;
//     b.l = 0;

//     char n;

//     for (int i = 0; i < total; ++i) {
//         std::cin >> n;
//         if (i < rSize) {
//             b.r |= ((n == '1') ? (1ULL << (rSize - i)) : 0);
//         }
//         else {
//             b.l |= ((n == '1') ? (1ULL << (lSize - i)) : 0);
//         }
//     }

//     return in;
// }

int main(int argc, char *argv[]) {
    std::ios_base::sync_with_stdio(false), 
        std::cin.tie(nullptr), 
        std::cout.tie(nullptr);

    // int n, l;

    // std::cin >> n >> l;

    // total = l;
    // vSize = 64;
    // lSize = vSize;
    // rSize = total - vSize;

    // body nut = { 0 };

    // std::cin >> nut;

    // std::vector<body> b(n);

    // for (int i = 0; i < n; ++i) {
    //     std::cin >> b[i];
    // }

    // std::cout << nut << std::endl;

    // for (int i = 0; i < n; ++i) {
    //     std::cout << b[i] << std::endl;
    // }
}
