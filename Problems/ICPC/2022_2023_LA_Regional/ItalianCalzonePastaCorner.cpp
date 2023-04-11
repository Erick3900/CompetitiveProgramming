// 2022_2023_LA_Regional
// ItalianCalzonePastaCorner 
// URL: https://codeforces.com/gym/104252/problem/I
// Date: Friday March 24, 2023
//
// Author: Erick Saúl
// Github: @Erick3900
// Twitter: @Erick_Alcachofa
// Mastodon: @alcachofa@social.linux.pizza

#include <bits/stdc++.h>
#include <queue>

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

int r;
int c;

std::vector<std::vector<int>> menu;
std::vector<bool> visited;

int solve(int x, int y) {
    visited.assign(r * c, false);

    struct dish {
        int x;
        int y;
        int num;
    };
    
    auto comp = [](const auto &a, const auto &b) {
        return a.num < b.num;
    };

    std::priority_queue<dish, std::vector<dish>, decltype(comp)> q(comp);

    q.push({ x, y, menu[y][x] });
    visited[y * c + x] = true;

    auto valid = [&] (int vx, int vy) {
        return (
            vx >= 0 &&
            vy >= 0 &&
            vy < r &&
            vx < c
        );
    };

    int mealSize = 1;

    auto visit = [&] (int vx, int vy) {
        if (valid(vx, vy) && ! visited[vy * c + vx]) {
            if (menu[y][x] < menu[vy][vx]) {
                q.push({ vx, vy, menu[vy][vx] });
                visited[vy * c + vx] = true;
                mealSize++;
            }
        }
    };

    while (! q.empty()) {
        x = q.top().x;
        y = q.top().y;
        q.pop();

        visit(x + 1, y);
        visit(x - 1, y);
        visit(x, y + 1);
        visit(x, y - 1);
    }

    return mealSize;
}

int main(int argc, char *argv[]) {
    std::ios_base::sync_with_stdio(false), 
        std::cin.tie(nullptr), 
        std::cout.tie(nullptr);

    std::cin >> r >> c;

    menu.resize(r, std::vector<int>(c));
    visited.resize(r * c, false);

    std::vector<std::pair<int, int>> values(r * c + 1);

    for (int y = 0; y < r; ++y) {
        for (int x = 0; x < c; ++x) {
            std::cin >> menu[y][x];
            values[menu[y][x]] = { x, y };
        }
    }

    const auto TOTAL_DISHES = r * c;
    auto maxMeal = std::numeric_limits<int>::min();
    
    for (int i = 1; i < values.size(); ++i) {
        if ((TOTAL_DISHES - i) >= maxMeal) {
            maxMeal = std::max(maxMeal, solve(values[i].first, values[i].second));
        }
        else break;
    }

    std::cout << maxMeal << '\n';
}
