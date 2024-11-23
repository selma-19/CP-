#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/implement-trie-prefix-tree/description/
struct TrieNode{
    bool isEnding;
    TrieNode* children[26];
    TrieNode() {
        isEnding = false;
        for (int i = 0; i < 26; ++i)
            children[i] = nullptr;
    }
};
class Trie {
public:
    TrieNode* root;

    void insert(string s) {
        TrieNode* currentNode = root;
        for (char c : s) {
            if (!currentNode->children[c - 'a']) {
                currentNode->children[c - 'a'] = new TrieNode();
            }
            currentNode = currentNode->children[c - 'a'];
        }
        currentNode->isEnding = true;
    }

    bool search(string word) {
        TrieNode* currentNode = root;
        for (char c : word) {
            if (!currentNode->children[c - 'a']) {
                return false;
            }
            currentNode = currentNode->children[c - 'a'];
        }
        return currentNode->isEnding;
    }

    bool startsWith(string prefix) {
        TrieNode* currentNode = root;
        for (char c : prefix) {
            if (!currentNode->children[c - 'a']) {
                return false;
            }
            currentNode = currentNode->children[c - 'a'];
        }
        return true;
    }
};
