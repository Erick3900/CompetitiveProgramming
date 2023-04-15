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

// File: 'DataStructures/SegmentTree.hpp' // C++11 Version

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

        std::function<void (int, int, int)> build_impl;
        build_impl = [&] (int i, int itl, int itr) -> void {
            if (itl == itr) {
                tree[i] = transform(values[itl]);
                return;
            }

            int mid = itl + ((itr - itl) >> 1);

            build_impl(i << 1, itl, mid);
            build_impl((i << 1) + 1, mid + 1, itr);

            tree[i] = eval(tree[i << 1], tree[(i << 1) + 1]);
        };

        build_impl(1, 0, n - 1);
    }

    Type query(int l, int r) {
        std::function<Type(int, int, int, int, int)> query_impl;
        query_impl = [&] (int i, int itl, int itr, int l, int r) -> Type {
            if (l > r) {
                return Neutral;
            }

            if (l == itl && r == itr) {
                return tree[i];
            }

            int mid = itl + ((itr - itl) >> 1);

            return eval(
                query_impl(i << 1, itl, mid, l, std::min(r, mid)),
                query_impl((i << 1) + 1, mid + 1, itr, std::max(l, mid + 1), r)
            );
        };

        return query_impl(1, 0, n - 1, l, r);
    }

    void update(int idx, Type newVal) {
        std::function <void (int, int, int)> update_impl;
        update_impl = [&, val = std::move(newVal)] (int i, int itl, int itr) -> void {
            if (itl == itr) {
                tree[i] = std::move(val);
                return;
            }

            int mid = itl + ((itr - itl) >> 1);

            if (idx <= mid) {
                update_impl(i << 1, itl, mid);
            }
            else {
                update_impl((i << 1) + 1, mid + 1, itr);
            }

            tree[i] = eval(tree[i << 1], tree[(i << 1) + 1]);
        };

        update_impl(1, 0, n - 1);
    }

    template <typename IType, typename FTransform>
    void update(int idx, IType newVal, FTransform &&transform) {
        std::function <void (int, int, int)> update_impl;
        update_impl = [&, val = std::move(newVal)] (int i, int itl, int itr) -> void {
            if (itl == itr) {
                tree[i] = transform(val);
                return;
            }

            int mid = itl + ((itr - itl) >> 1);

            if (idx <= mid) {
                update_impl(i << 1, itl, mid);
            }
            else {
                update_impl((i << 1) + 1, mid + 1, itr);
            }

            tree[i] = eval(tree[i << 1], tree[(i << 1) + 1]);
        };

        update_impl(1, 0, n - 1);
    }
};

inline auto STreeIntMin() -> SegmentTree<> {
    return SegmentTree<int>{ &FTaskIMin, std::numeric_limits<int>::max() };
}

inline auto STreeIntMax() -> SegmentTree<> {
    return SegmentTree<int>{ &FTaskIMax, std::numeric_limits<int>::min() };
}

inline auto STreeIntSum() -> SegmentTree<> {
    return SegmentTree<int>{ &FTaskISum, 0 };
}

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

        auto t = STreeIntSum();
        t.build(ohms);

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


