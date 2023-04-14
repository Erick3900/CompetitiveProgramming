#pragma once

#include <bits/stdc++.h>

struct FenwickTree {
    int n;
    std::vector<int64_t> tree;

    FenwickTree(int n)
        : n(n + 1)
        , tree(n + 1, 0) {}

    FenwickTree(const std::vector<int> &values) 
        : FenwickTree(values.size()) {
        for (int i = 1; i < n; ++i) {
            tree[i] += values[i - 1];
            int r = i + (i & -i);
            if (r < n) {
                tree[r] += tree[i];
            }
        }
    }

    int64_t querySum(int r) {
        int64_t ret = 0;

        for (++r; r > 0; r -= (r & -r)) {
            ret += tree[r];
        }

        return ret;
    }

    int64_t querySum(int l, int r) {
        return querySum(r) - querySum(l - 1);
    }

    void updateAdd(int idx, int64_t delta) {
        for (++idx; idx < n; idx += (idx & -idx)) {
            tree[idx] += delta;
        }
    }

    void updateRangeAdd(int l, int r, int64_t val) {
        updateAdd(l, val);
        updateAdd(r + 1, -val);
    }
};
