#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array
struct TrieNode{
    TrieNode* children[2];
    bool isEnding;
    TrieNode(){
        isEnding = false;
        children[1] = nullptr;
        children[0]=nullptr;
    }
};
struct Trie{
    TrieNode* root;
    Trie(){
        root = new TrieNode();
    }
    void insert(string number){
        TrieNode* currentNode = root;
        for(char digit : number){
            if(!currentNode->children[digit - '0']){
                currentNode->children[digit - '0'] = new TrieNode();
            }
            currentNode = currentNode->children[digit - '0'];
        }
        currentNode->isEnding = true;
    }
    bool search(string number){
        TrieNode* currentNode = root;
        for(char digit : number){
            if(!currentNode->children[digit - '0']){
                return false;
            }
            currentNode = currentNode->children[digit - '0'];
        }
        return true;
    }

    int findMax(string number){
        int  result = 1;
        TrieNode* currentNode = root;
        for(char digit : number){
            if(!currentNode){
                return result;
            }
            if(!currentNode->children[(digit - '0'+1)%2]){
                currentNode = currentNode->children[digit - '0'];
                result =result * 2 + (digit -'0')*1;
            }
            else {
                currentNode = currentNode->children[(digit - '0' + 1) % 2];
                result = result * 2 + ((digit - '0' + 1) % 2)*1;
            }
        }
        return result;
    }
};


string toBinaryString(int number){
    return bitset<32>(number).to_string();
}

int main(){
    vector<int> numbers = {3,10,25,2,8,5};
    vector<string> binary ;
    for(int number : numbers){
        binary.push_back(toBinaryString(number));
    }
    Trie* myTree = new Trie();
    for(string s : binary){
        myTree->insert(s);
    }
    int result=0 ;
    for(string s : binary){
        //cout<< stoi(s,nullptr,2) << " : "<< myTree->findMax(s) <<"="<<(stoi(s,nullptr,2) ^ myTree->findMax(s)) << endl;
       result =  max(result,stoi(s,nullptr,2)^myTree->findMax(s));

    }
    cout<<result<<endl;

}