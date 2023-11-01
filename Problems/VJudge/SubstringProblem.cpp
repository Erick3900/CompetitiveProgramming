// VJudge
// SubstringProblem
// 
// Date: Wednesday April 12, 2023
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

// File: 'Graphs/UFDS.hpp'

struct UFDS {
    using Node = int32_t;

    int32_t size;
    std::vector<Node> parents;

    UFDS(Node n) 
        : size(n)
        , parents(n) { 
        std::iota(parents.begin(), parents.end(), 0);
    }

    Node ufind(Node n) {
        if (parents[n] == n) {
            return n;
        }

        return parents[n] = ufind(parents[n]);
    }

    void unite(Node from, Node to) {
        auto toParent = ufind(to);
        auto fromParent = ufind(from);
        
        if (toParent != fromParent) {
            parents[toParent] = fromParent;
            --size;
        }
    }

    bool connected(Node from, Node to) {
        return ufind(from) == ufind(to);
    }
};


// EOF: Graphs/UFDS.hpp

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

int main(int argc, char *argv[]) {
    std::ios_base::sync_with_stdio(false),
        std::cin.tie(nullptr),
        std::cout.tie(nullptr);
 
    std::string text;
    std::string pattern;
 
    std::cin >> text;
 
    int k;
 
    std::cin >> k;
 
    AhoCorasick t;
    
    UFDS uf(k);
 
    int uniques = 0;
    std::vector<bool> results(k, false);
    std::unordered_map<std::string, int> uqs;
 
    for (int i = 0; i < k; ++i) {
        std::cin >> pattern;
        auto uid = 0;
 
        auto it = uqs.find(pattern);
        if (it == uqs.end()) {
            t.addString(pattern, i);
            uqs[pattern] = i;
            uid = i;
        }
        else {
            uid = it->second;
        }
 
        uf.unite(uid, i);
    }
    t.prepareAho();
    t.preprocessString(text, [&](int wid, int) { results[wid] = true; });
 
    for (int i = 0; i < k; ++i) {
        auto p = uf.ufind(i);
 
        if (results[p]) {
            std::cout << "Y\n";
        }
        else {
            std::cout << "N\n";
        }
    }
}

