#pragma once
#include <bits/stdc++.h>

static int UppercaseOffset(char c) {
    return c - 'A';
}

using OffsetFun_t = int (*)(char);

template <std::size_t ChildsSz = 26, OffsetFun_t Offset = UppercaseOffset>
struct Trie {
    struct Node {
        bool exists;
        char letter;

        std::array<Node *, ChildsSz> childs;

        Node(char l)
            : exists(false)
            , letter(l) {
            std::fill(childs.begin(), childs.end(), nullptr);
        }
    };

    Node *root;

    Trie()
        : root(nullptr) {
        root = new Node('!');
    }

    void insert(std::string_view str) {
        auto curr = root;

        for (auto c : str) {
            auto n = Offset(c);

            if (curr->childs[n] == nullptr) {
                curr->childs[n] = new Node(c);
            }

            curr = curr->childs[n];
        }

        curr->exists = true;
    }

    bool find(std::string_view str) {
        auto curr = root;

        for (auto c : str) {
            auto n = Offset(c);

            if (curr->childs[n] == nullptr) {
                return false;
            }

            curr = curr->childs[n];
        }

        return curr->exists;
    }

    bool findPrefix(std::string_view str) {
        auto curr = root;

        for (auto c : str) {
            auto n = Offset(c);

            if (curr->childs[n] == nullptr) {
                return false;
            }

            curr = curr->childs[n];
        }

        return true;
    }
};
