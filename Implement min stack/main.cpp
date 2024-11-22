#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/min-stack/
class MinStack {
public:
    int size = 0;
    int Min=INT_MAX;
    vector<pair<int,int>> s;
    MinStack() {
        s.push_back(make_pair(0,0));
    }

    void push(int val) {
        s[size]=make_pair(val,Min);
        Min=min(Min,val);
        size++;
    }

    void pop() {
        Min = s[size].second;
        s[size]=make_pair(0,0);
        size--;
    }

    int top() {
        return s[size-1].first;
    }

    int getMin() {
        return s[size-1].second;
    }
};
