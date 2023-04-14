// UVA Online Judge
// Potentiometers 
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=16&page=show_problem&problem=3238
// Date: Thursday April 13, 2023
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

// File: 'DataStructures/SegmentTree.hpp'

inline int64_t STMin(int64_t a, int64_t b) {
    return std::min(a, b);
}

inline int64_t STMax(int64_t a, int64_t b) {
    return std::max(a, b);
}

inline int64_t eval(int64_t a, int64_t b) {
    return a + b;
}

template <int64_t neutro = std::numeric_limits<int64_t>::max()>
struct SegmentTree {
    int n;
    std::vector<int64_t> tree;

    SegmentTree() 
        : n(0)
        , tree() {}

    SegmentTree(const std::vector<int> &values)
        : n(values.size())
        , tree(4 * n, 0) {
        build(values);
    }

    void build(const std::vector<int> &values) {
        if (tree.size() < values.size()) {
            n = values.size();
            tree.resize(4 * n, 0);
        }

        std::function<void(int, int, int)> self;
        self = [&] (int i, int itl, int itr) -> void {
            if (itl == itr) {
                tree[i] = values[itl];
            }
            else {
                int mid = itl + ((itr - itl) / 2);

                self(i * 2, itl, mid);
                self(i * 2 + 1, mid + 1, itr);

                tree[i] = eval(tree[i * 2], tree[i * 2 + 1]);
            }
        };

        self(1, 0, n - 1);
    }

    int64_t query(int l, int r) {
        std::function<int64_t(int, int, int, int, int)> self;
        self = [&] (int i, int tl, int tr, int l, int r) -> int64_t {
            if (l > r) {
                return neutro;
            }

            if (l == tl && r == tr) {
                return tree[i];
            }

            int mid = tl + (tr - tl) / 2;

            return eval(
                self(i * 2, tl, mid, l, std::min(r, mid)),
                self(i * 2 + 1, mid + 1, tr, std::max(l, mid + 1), r)
            );
        };

        return self(1, 0, n - 1, l, r);
    }

    void update(int idx, int64_t newVal) {
        std::function<void(int, int, int)> self;
        self = [&] (int i, int itl, int itr) -> void {
            if (itl == itr) {
                tree[i] = newVal;
            }
            else {
                int mid = itl + (itr - itl) / 2;

                if (idx <= mid) {
                    self(i * 2, itl, mid);
                }
                else {
                    self(i * 2 + 1, mid + 1, itr);
                }

                tree[i] = eval(tree[i * 2], tree[i * 2 + 1]);
            }
        };

        self(1, 0, n - 1);
    }
};

// EOF: DataStructures/SegmentTree.hpp

int main(int argc, char *argv[]) {
    std::ios_base::sync_with_stdio(false), 
        std::cin.tie(nullptr), 
        std::cout.tie(nullptr);

    int n;
    int cse = 0;

    while ((std::cin >> n) && n != 0) {
        if (cse > 0) {
            std::cout << '\n';
        }

        std::cout << "Case " << ++cse << ":\n";

        std::vector<int> ohms(n);

        for (auto &e : ohms) {
            std::cin >> e;
        }

        SegmentTree<0> t{ ohms };

        int l, r;
        std::string q;

        while ((std::cin >> q) && q[0] != 'E') {
            std::cin >> l >> r;
            --l;

            if (q[0] == 'S') {
                t.update(l, r);
            }
            else {
                --r;

                std::cout << t.query(l, r) << '\n';
            }
        }
    }

}

