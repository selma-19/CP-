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
    TrieNode* root= new TrieNode();

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
    bool isEmpty(TrieNode* root){
        if(!root)
            return false;
            for(int i = 0;i<26;i++){
                if(root->children[i])
                    return false;
            }

        return true ;
    };

    TrieNode* remove(string key){
       return remove(root,key);
    }
    TrieNode* remove(TrieNode* root , string key ,int depth = 0){
        if(!root)
            return root;
        else if(depth == key.size()) {
            if(isEmpty(root)){
                delete(root);
                return nullptr;
        }
            else {
                root->isEnding = false;
                return root;
            }
    }
        if(root->children[key[depth]-'a']){
            root->children[key[depth]-'a']= remove(root->children[key[depth]-'a'],key,depth+1);
        }

        // a root does not have any child and is not ending of the word
        if (isEmpty(root) && root->isEnding == false) {
            root = nullptr;
            delete (root);
        }
        return root;
};
};
int main()
{
    // Input keys (use only 'a' through 'z'
    // and lower case)
    string keys[] = { "the", "a", "there",
                      "answer", "any", "by",
                      "bye", "their", "hero", "heroplane" };
    int n = sizeof(keys) / sizeof(keys[0]);

    Trie* root = new Trie();

    // Construct trie
    for (int i = 0; i < n; i++)
        root->insert( keys[i]);

    // Search for different keys
    root->search("the") ? cout << "Yes\n" : cout << "No\n";
    root->search("these") ? cout << "Yes\n" : cout << "No\n";

    root->remove( "heroplane");
    root->startsWith( "heropla") ? cout << "Yes\n" : cout << "No\n";
    root->search( "hero") ? cout << "Yes\n" : cout << "No\n";
    return 0;
}
