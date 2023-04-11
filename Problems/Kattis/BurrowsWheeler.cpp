// Kattis
// BurrowsWheeler 
// https://open.kattis.com/problems/burrowswheeler
// Date: Monday April 10, 2023
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

std::vector<int> buildSuffixArray(const std::string &input) {
    struct Suffix {
        std::size_t idx;
        std::array<int, 2> rank;
    };

    int n = input.size();

    std::vector<Suffix> helper(input.size());
    std::vector<int> ret(input.length());

    auto cmp = [] (const Suffix &a, const Suffix &b) {
        return (
            (a.rank[0] == b.rank[0])
                ? (a.rank[1] < b.rank[1])
                : (a.rank[0] < b.rank[0])
        );
    };

    for (int i = 0; i < n; ++i) {
        helper[i].idx = i;
        helper[i].rank[0] = input[i] - 'a';
        helper[i].rank[1] = (
            (i + 1) < n
                ? (input[i + 1] - 'a')
                : -1
        );
    }

    std::sort(helper.begin(), helper.end(), cmp);

    for (int k = 4; k < (n << 1); k <<= 1) {
        int rank = 0;
        int prev_rank = helper[0].rank[0];
        helper[0].rank[0] = rank;
        ret[helper[0].idx] = 0;

        for (int i = 1; i < n; ++i) {
            if (helper[i].rank[0] == prev_rank && helper[i].rank[1] == helper[i - 1].rank[1]) {
                prev_rank = helper[i].rank[0];
                helper[i].rank[0] = rank;
            }
            else {
                prev_rank = helper[i].rank[0];
                helper[i].rank[0] = ++rank;
            }

            ret[helper[i].idx] = i;
        }

        for (int i = 0; i < n; ++i) {
            int next = helper[i].idx + (k >> 1);
            helper[i].rank[1] = (
                (next < n)
                    ? helper[ret[next]].rank[0]
                    : -1
            );
        }

        std::sort(helper.begin(), helper.end(), cmp);
    }

    for (int i = 0; i < n; ++i) {
        ret[i] = helper[i].idx;
    }

    return ret;
}

int main(int argc, char *argv[]) {
    std::ios_base::sync_with_stdio(false), 
        std::cin.tie(nullptr), 
        std::cout.tie(nullptr);

    std::string input;

    while (std::getline(std::cin, input)) {
        auto suffixArray = buildSuffixArray(input + input);

        for (std::size_t i = 0; i < suffixArray.size(); ++i) {
            if (suffixArray[i] < input.length()) {
                auto c = ((suffixArray[i] == 0) ? input.length() : suffixArray[i]) - 1;
                std::cout << input[c];
            }
        }
        std::cout << '\n';
    }
}

