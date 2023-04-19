// UVA
// ILoveStrings 
// 
// Date: Friday April 14, 2023
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

    int addString(const std::string &s, int wordId) {
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

        if (trie[currVertex].leaf) {
            return trie[currVertex].wordId;
        }
        trie[currVertex].leaf = true;
        trie[currVertex].wordId = wordId;

        return wordId;
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

    while(n--) {
        solve();
    }
}

void solve() {
    std::string text;
    std::string pattern;

    std::cin >> text;

    int n;

    std::cin >> n;

    AhoCorasick ac;
    std::vector<int> parents(n);
    std::vector<bool> isSubstring(n, false);

    for (int i = 0; i < n; ++i) {
        std::cin >> pattern;
        
        auto uid = ac.addString(pattern, i);
        parents[i] = uid;
    }

    ac.prepareAho();
    ac.preprocessString(text, [&] (int i, int) {
        isSubstring[i] = true;
    });

    for (int i = 0; i < n; ++i) {
        auto id = parents[i];

        if (isSubstring[id]) {
            std::cout << "y\n";
        }
        else {
            std::cout << "n\n";
        }
    }
}

