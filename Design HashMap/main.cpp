#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/design-hashmap/description/
class MyHashMap {
public:
    const static int size = 19997;
    const static int mult = 12582917;
    list<pair<int, int>> hashTable[size];
    MyHashMap() {}

    void put(int key, int value) {
        int index = hash(key);
        for (auto it = hashTable[index].begin(); it != hashTable[index].end();
             it++) {
            if (it->first == key) {
                it->second = value;
                return;
            }
        }
        hashTable[index].push_front(make_pair(key, value));
        print();
    }

    int get(int key) {
        int index = hash(key);
        for (auto it = hashTable[index].begin(); it != hashTable[index].end();
             it++) {
            if (it->first == key)
                return it->second;
        }
        return -1;
    }

    void remove(int key) {
        int index = hash(key);
        for (auto it = hashTable[index].begin(); it != hashTable[index].end();
             it++) {
            if (it->first == key) {
                hashTable[index].erase(it);
                break;
            }
        }
        print();
    }
    int hash(int key) { return (int)((long)key * mult % size); }
    void print() {
        for (int i = 0; i < size; i++) {
            if (!hashTable[i].empty()) {
                cout << "Bucket " << i << ": ";
                for (auto& p : hashTable[i]) {
                    cout << "[" << p.first << ", " << p.second << "] ";
                }
                cout << endl;
            }
        }
    }
};
