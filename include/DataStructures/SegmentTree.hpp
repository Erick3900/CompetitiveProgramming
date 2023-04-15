#pragma once

#include <bits/stdc++.h>

inline int FTaskISum(int a, int b) {
    return a + b;
}

inline int FTaskIMin(int a, int b) {
    return std::min(a, b);
}

inline int FTaskIMax(int a, int b) {
    return std::max(a, b);
}

template <typename Type>
using FTast_t = Type (*)(Type, Type);

template <
    typename Type = int, 
    typename FTask = FTast_t<Type>
>
struct SegmentTree {
    std::size_t n;
    std::vector<Type> tree;

    Type Neutral;
    FTask eval;

    SegmentTree(FTask &&task, Type neutro)
        : n(0)
        , tree{}
        , Neutral(neutro)
        , eval(task) {}

    SegmentTree(FTask &&task, const std::vector<Type> &values) 
        : n(values.size())
        , tree(4 * n, Neutral)
        , eval(task) {
        build(values, [] (const Type &t) -> Type { return t; });
    }

    template <typename IType, typename FTransform>
    SegmentTree(FTask &&task, const std::vector<IType> &values, FTransform &&transform) 
        : n(values.size())
        , tree(4 * n, Neutral)
        , eval(task) {
        build(values, std::forward<FTransform>(transform));
    }
    
    void build(const std::vector<Type> &values) {
        build(values, [] (const Type &t) -> Type { return t; });
    }

    template <typename IType, typename FTransform>
    void build(const std::vector<IType> &values, FTransform &&transform) {
        if (tree.size() != (values.size() * 4)) {
            n = values.size();
            tree.resize(4 * n, Neutral);
        }

        auto build_impl = [&] (int i, int itl, int itr, auto &&self) -> void {
            if (itl == itr) {
                tree[i] = transform(values[itl]);
                return;
            }

            int mid = itl + ((itr - itl) >> 1);

            self(i << 1, itl, mid, self);
            self((i << 1) + 1, mid + 1, itr, self);

            tree[i] = eval(tree[i << 1], tree[(i << 1) + 1]);
        };

        build_impl(1, 0, n - 1, build_impl);
    }

    Type query(int l, int r) {
        auto query_impl = [&] (int i, int itl, int itr, int l, int r, auto &&self) -> Type {
            if (l > r) {
                return Neutral;
            }

            if (l == itl && r == itr) {
                return tree[i];
            }

            int mid = itl + ((itr - itl) >> 1);

            return eval(
                self(i << 1, itl, mid, l, std::min(r, mid), self),
                self((i << 1) + 1, mid + 1, itr, std::max(l, mid + 1), r, self)
            );
        };

        return query_impl(1, 0, n - 1, l, r, query_impl);
    }

    void update(int idx, Type newVal) {
        auto update_impl = [&, val = std::move(newVal)] (int i, int itl, int itr, auto &&self) {
            if (itl == itr) {
                tree[i] = std::move(val);
                return;
            }

            int mid = itl + ((itr - itl) >> 1);

            if (idx <= mid) {
                self(i << 1, itl, mid, self);
            }
            else {
                self((i << 1) + 1, mid + 1, itr, self);
            }

            tree[i] = eval(tree[i << 1], tree[(i << 1) + 1]);
        };

        update_impl(1, 0, n - 1, update_impl);
    }

    template <typename IType, typename FTransform>
    void update(int idx, IType newVal, FTransform &&transform) {
        auto update_impl = [&, val = std::move(newVal)] (int i, int itl, int itr, auto &&self) {
            if (itl == itr) {
                tree[i] = transform(val);
                return;
            }

            int mid = itl + ((itr - itl) >> 1);

            if (idx <= mid) {
                self(i << 1, itl, mid, self);
            }
            else {
                self((i << 1) + 1, mid + 1, itr, self);
            }

            tree[i] = eval(tree[i << 1], tree[(i << 1) + 1]);
        };

        update_impl(1, 0, n - 1, update_impl);
    }
};

inline auto STreeIntMin() {
    return SegmentTree<int>{ &FTaskIMin, std::numeric_limits<int>::max() };
}

inline auto STreeIntMax() {
    return SegmentTree<int>{ &FTaskIMax, std::numeric_limits<int>::min() };
}

inline auto STreeIntSum() {
    return SegmentTree<int>{ &FTaskISum, 0 };
}
