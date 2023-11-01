// UVA Online Judge
// CaesarCipher 
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4282
// Date: Tuesday April 11, 2023
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


// File: 'Strings/AhoCorasick.hpp'

struct Vertex {
    bool leaf;
    int parent;
    char parentChar;
    int suffixLink;
    int endWordLink;
    int wordId;
    std::unordered_map<char, int> children;

    Vertex()
        : leaf(false)
        , parent(-1)
        , parentChar()
        , suffixLink(-1)
        , endWordLink(-1)
        , wordId(-1)
        , children{} { }
};

struct AhoCorasick {
    int size;
    int root;
    std::vector<Vertex> trie;

    AhoCorasick()
        : size(0)
        , root(0)
        , trie{} {
        trie.push_back(Vertex());
        size++;
    }

    void addString(const std::string &s, int wordId) {
        int currVertex = root;

        for (auto c : s) {
            if (!trie[currVertex].children.count(c)) {
                trie.push_back(Vertex());

                trie[size].suffixLink = -1;
                trie[size].parent = currVertex;
                trie[size].parentChar = c;
                trie[currVertex].children[c] = size;
                size++;
            }

            currVertex = trie[currVertex].children[c];
        }

        trie[currVertex].leaf = true;
        trie[currVertex].wordId = wordId;
    }

    void prepareAho() {
        std::queue<int> vertexQueue;

        vertexQueue.push(root);

        while (!vertexQueue.empty()) {
            auto currVertex = vertexQueue.front();
            vertexQueue.pop();

            calcSuffixLink(currVertex);

            for (auto it : trie[currVertex].children) {
                vertexQueue.push(it.second);
            }
        }
    }

    void calcSuffixLink(int vertex) {
        if (vertex == root) {
            trie[vertex].suffixLink = root;
            trie[vertex].endWordLink = root;
            return;
        }

        if (trie[vertex].parent == root) {
            trie[vertex].suffixLink = root;

            if (trie[vertex].leaf) {
                trie[vertex].endWordLink = vertex;
            }
            else {
                trie[vertex].endWordLink = trie[trie[vertex].suffixLink].endWordLink;
            }

            return;
        }

        auto currBetterVertex = trie[trie[vertex].parent].suffixLink;
        char chVertex = trie[vertex].parentChar;

        while (true) {
            if (trie[currBetterVertex].children.count(chVertex)) {
                trie[vertex].suffixLink = trie[currBetterVertex].children[chVertex];
                break;
            }

            if (currBetterVertex == root) {
                trie[vertex].suffixLink = root;
                break;
            }

            currBetterVertex = trie[currBetterVertex].suffixLink;
        }

        if (trie[vertex].leaf) {
            trie[vertex].endWordLink = vertex;
        }
        else {
            trie[vertex].endWordLink = trie[trie[vertex].suffixLink].endWordLink;
        }
    }

    template <typename Callback>
    void preprocessString(const std::string &text, Callback &&callback) {
        int currentState = root;

        for (int j = 0; j < text.length(); ++j) {
            while (true) {
                if (trie[currentState].children.count(text[j])) {
                    currentState = trie[currentState].children[text[j]];
                    break;
                }

                if (currentState == root) {
                    break;
                }

                currentState = trie[currentState].suffixLink;
            }

            int checkState = currentState;

            while (true) {
                checkState = trie[checkState].endWordLink;

                if (checkState == root)
                    break;

                callback(trie[checkState].wordId, j + 1);

                checkState = trie[checkState].suffixLink;
            }
        }
    }
};

// EOF: Strings/AhoCorasick.hpp

void solve();

int main(int, char *[]) {
    std::ios_base::sync_with_stdio(false), 
        std::cin.tie(nullptr), 
        std::cout.tie(nullptr);

    int n;

    std::cin >> n;

    while (n--) {
        solve();
    }

}

void solve() {
    std::string alphabet;
    std::string word;
    std::string text;

    std::cin >> alphabet >> word >> text;

    std::unordered_map<char, int> idx;

    for (int i = 0;  i< alphabet.size(); ++i) {
        idx[alphabet[i]] = i;
    }

    int X = alphabet.size();

    auto dsChar = [&] (char c, int ds) {
        return alphabet[(idx.at(c) + ds) % X];
    };

    std::string dsStr = word;
    AhoCorasick trie;

    for (int i = 0; i < X; ++i) {
        trie.addString(dsStr, i);

        for (int j = 0; j < word.size(); ++j) {
            dsStr[j] = dsChar(word[j], i + 1);
        }
    }
    trie.prepareAho();

    std::vector<int> possible;
    possible.reserve(alphabet.size());

    std::vector<int> appearances(alphabet.size(), 0);

    trie.preprocessString(text, [&] (int ds, int) {
        appearances[ds]++;
    });
    
    for (int i = 0; i < appearances.size(); ++i) {
        if (appearances[i] == 1) {
            possible.push_back(i);
        }
    }

    switch(possible.size()) {
        case 0:
            std::cout << "no solution\n";
            break;
        case 1:
            std::cout << "unique: " << possible[0] << "\n";
            break;
        default:
            std::sort(possible.begin(), possible.end());
            std::cout << "ambiguous: ";
            for (const auto &c : possible) {
                std::cout << c;
                if (c != possible.back()) {
                    std::cout << " ";
                }
            }
            std::cout << '\n';
            break;
    }
}

