#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/minimum-size-subarray-sum/description/
int minSubArrayLen(int target, vector<int>& nums) {
    int l = 0, r = 0, s = nums[0], lgth = INT_MAX;
    int n = nums.size();
    while (l < n && r < n && l <= r) {
        if (s == target) {
            lgth = min(lgth, r - l + 1);
            s -= nums[l];
            l++;
        } else if (s < target) {
            r++;
            if (r < n)
                s += nums[r];
        } else if (s > target) {
            if (l < n)
                s -= nums[l];
            l++;
        }
    }
    if (lgth == INT_MAX)
        lgth = 0;
    return lgth;
}
int main(){
    vector<int> v = {2,3,1,2,4,3};
    cout<< minSubArrayLen(7,v);

}

