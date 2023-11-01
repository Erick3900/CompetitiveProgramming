// Random
// TriangleContainment
//
// Date: Saturday August 12, 2023
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

struct coord {
    int x, y;
    int points;
};

std::vector<coord> treasures;

coord p1;
coord p2;

bool isInside(const coord &p3, const coord &p) {
    double denominator = ((p2.y - p3.y) * (p1.x - p3.x) + (p3.x - p2.x) * (p1.y - p3.y));
    double a = ((p2.y - p3.y) * (p.x - p3.x) + (p3.x - p2.x) * (p.y - p3.y)) / denominator;
    double b = ((p3.y - p1.y) * (p.x - p3.x) + (p1.x - p3.x) * (p.y - p3.y)) / denominator;
    double c = 1 - a - b;

    return (a >= 0 && b >= 0 && c >= 0);
}

int64_t getPoints(int n) {
    int64_t ans = 0;

    for (int i = 0; i < treasures.size(); ++i) {
        if (i != n) {
            if (isInside(treasures[n], treasures[i])) {
                ans += treasures[i].points;
            }
        }
    }

    return ans;
}

int main(int argc, char *argv[]) {
    std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);

    int n, m;

    std::cin >> n >> m;

    treasures.resize(n);

    p1 = coord{ 0, 0, 0 };
    p2 = coord{ m, 0, 0 };

    for (int i = 0; i < n; ++i) {
        std::cin >> treasures[i].x >> treasures[i].y >> treasures[i].points;
    }

    for (int i = 0; i < n; ++i) {
        std::cout << getPoints(i) << '\n';
    }
}
