#pragma once
#include <bits/stdc++.h>

inline std::array<std::byte, 1024 * 1024> memMapBuffer;
inline std::array<std::byte, 1024 * 1024> memVertBuffer;
inline std::pmr::monotonic_buffer_resource memMapRsrc{ memMapBuffer.data(), memMapBuffer.size() };
inline std::pmr::monotonic_buffer_resource memVertRsrc{ memVertBuffer.data(), memVertBuffer.size() };

struct AhoCorasick {
    struct Vertex {
        bool leaf;
        char parentChar;
        int parent;
        int suffixLink;
        int endWordLink;
        int wordId;
        std::pmr::map<char, int> children;

        Vertex()
            : leaf(false)
            , parentChar('$')
            , parent(-1)
            , suffixLink(-1)
            , endWordLink(-1)
            , wordId(-1)
            , children{&memMapRsrc} { }
    };

    int size;
    int root;
    std::pmr::vector<Vertex> trie;

    AhoCorasick()
        : size(0)
        , root(0)
        , trie{&memVertRsrc} {
        trie.reserve(memVertBuffer.size() / sizeof(Vertex));
        trie.push_back(Vertex());
        size++;
    }

    int addString(std::string_view s, int wordId) {
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
    void preprocessString(std::string_view text, Callback &&callback) {
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
