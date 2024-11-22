#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/permutation-in-string/
bool checkInclusion(string s1, string s2) {
    if(s1.size()>s2.size())
        return false;
    map<int,int> s1_chars;
    map<int,int> s2_chars;
    int n1 = s1.size(),n2=s2.size();
    int l=0, r=n1-1,matching_score=0;
    for(char c  : s1){
        s1_chars[c]++;
    }
    // check the letters of s2 in range [0,length_s1] to initialize s2_chars map
    for(int i = 0;i<=r;i++) {
        if (s1_chars[s2[i]] != 0) {
            s2_chars[s2[i]]++;
        }
        if (s1_chars[s2[i]] == s2_chars[s2[i]] && s1_chars[s2[i]] != 0)
            matching_score++;
    }
    while(r<n2){
        if(matching_score==n1){
            return true;
        }
        if(s2_chars[s2[l]]==s1_chars[s2[l]] && s1_chars[s2[l]] != 0 ) {
            matching_score--;
            s2_chars[s2[l]]--;
        }
        l++;
        if(s2_chars[s2[r]]==s1_chars[s2[r]]-1 && s1_chars[s2[r]] != 0 ) {
            matching_score++;
            s2_chars[s2[l]]++;
        }
        r++;
    }

    return false;
}

int main(){

    cout << checkInclusion("ab","eidbaooo");
}
