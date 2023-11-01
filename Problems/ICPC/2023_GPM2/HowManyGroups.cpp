// 2023_GPM2
// HowManyGroups 
// 
// Date: Sunday June 04, 2023
//
// Author: Erick Saúl
// Github: @Erick3900
// Twitter: @Erick_Alcachofa
// Mastodon: @alcachofa@social.linux.pizza

#include <bits/stdc++.h>

struct tnode {
    int id;
    int ans;

    std::vector<int> subordinates;
};

std::vector<tnode> tree;

int ans_c = 0;
std::unordered_map<int, int> h;

void dfs(int n) {
    if (h[tree[n].id] == 0) {
        ans_c++;
    }

    h[tree[n].id]++;
    tree[n].ans = ans_c;

    for (auto c : tree[n].subordinates) {
        dfs(c);
    }

    if (--h[tree[n].id] == 0) {
        ans_c--;
    }
}

int main(int argc, char *argv[]) {
    std::ios_base::sync_with_stdio(false), 
        std::cin.tie(nullptr), 
        std::cout.tie(nullptr);

    int n, t, boss;

    std::cin >> n;

    tree.resize(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> t;

        if (t == 0) {
            boss = i;
        }
        else {
            tree[t - 1].subordinates.push_back(i);
        }
    }

    for (int i = 0; i < n; ++i) {
        std::cin >> t;
        tree[i].id = t;
    }

    dfs(boss);

    for (int i = 0; i < n; ++i) {
        std::cout << tree[i].ans << " \n"[(i + 1) == n];
    }
}
