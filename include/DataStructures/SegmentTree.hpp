#pragma once

#include <bits/stdc++.h>

using STTask = int64_t (*)(int64_t, int64_t);

inline int64_t STMin(int64_t a, int64_t b) {
    return std::min(a, b);
}

inline int64_t STMax(int64_t a, int64_t b) {
    return std::max(a, b);
}

inline int64_t STSum(int64_t a, int64_t b) {
    return a + b;
}

template <STTask eval = STMin, int64_t neutro = std::numeric_limits<int64_t>::max()>
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

        auto build_impl = [&] (int i, int itl, int itr, auto &&self) -> void {
            if (itl == itr) {
                tree[i] = values[itl];
            }
            else {
                int mid = itl + ((itr - itl) / 2);

                self(i * 2, itl, mid, self);
                self(i * 2 + 1, mid + 1, itr, self);

                tree[i] = eval(tree[i * 2], tree[i * 2 + 1]);
            }
        };

        build_impl(1, 0, n - 1, build_impl);
    }

    int64_t query(int l, int r) {
        auto query_impl = [&] (int i, int tl, int tr, int l, int r, auto &&self) -> int64_t {
            if (l > r) {
                return neutro;
            }

            if (l == tl && r == tr) {
                return tree[i];
            }

            int mid = tl + (tr - tl) / 2;

            return eval(
                self(i * 2, tl, mid, l, std::min(r, mid), self),
                self(i * 2 + 1, mid + 1, tr, std::max(l, mid + 1), r, self)
            );
        };

        return query_impl(1, 0, n - 1, l, r, query_impl);
    }

    void update(int idx, int64_t newVal) {
        auto update_impl = [&] (int i, int itl, int itr, auto &&self) -> void {
            if (itl == itr) {
                tree[i] = newVal;
            }
            else {
                int mid = itl + (itr - itl) / 2;

                if (idx <= mid) {
                    self(i * 2, itl, mid, self);
                }
                else {
                    self(i * 2 + 1, mid + 1, itr, self);
                }

                tree[i] = eval(tree[i * 2], tree[i * 2 + 1]);
            }
        };

        update_impl(1, 0, n - 1, update_impl);
    }
};
