// OmegaUp
// ContandoMenores
//
// Date: Monday March 20, 2023
//
// Author: Erick Saúl
// Github: @Erick3900
// Twitter: @Erick_Alcachofa
// Mastodon: @alcachofa@social.linux.pizza

#include <bits/stdc++.h>
#include <type_traits>

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

// template <typename It, typename Comp>
// requires(std::is_same_v<typename It::iterator_category, std::random_access_iterator_tag> &&
//          std::is_same_v<std::invoke_result_t<Comp, typename It::value_type, typename It::value_type>, bool>)
// void mergeSort(It begin, It end, Comp &&comp) {
//     auto merge = [&comp](It l, It m, It r) {
//         std::list<typename It::value_type> hb;

//         auto i = l;
//         auto j = m + 1;

//         while (i <= m && j <= r) {
//             if (! comp(*i, *j)) {
//                 hb.push_back(std::move(*i));
//                 ++i;
//             }
//             else {
//                 hb.push_back(std::move(*j));
//                 ++j;
//             }
//         }
        
//         while (i <= m) {
//             hb.push_back(std::move(*i));
//             ++i;
//         } 

//         while (j <= m) {
//             hb.push_back(std::move(*j));
//             ++j;
//         }

//         for (auto it = hb.begin(); it != hb.end(); ++it, ++l) {
//             *l = std::move(*it);
//         }
//     };

//     auto sort = [&merge] (auto &&self, It l, It r) -> void {
//         if (l < r) {
//             auto m = l + (l - r) / 2;
//             self(self, l, m);
//             self(self, m + 1, r);
//             merge(l, m, r);
//         }
//     };

//     sort(sort, begin, end - 1);
// }

// template <typename T>
// class GetType;

int main(int argc, char *argv[]) {
    std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);

    // std::vector<int> values{ 10, 3, 58, 123, 581, 1, 6, 2 };

    // mergeSort(values.begin(), values.end(), std::less<>());

    // for (auto &v : values) {
    //     std::cout << v << ' ';
    // }
    // std::cout << std::endl;
}
