#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/container-with-most-water/description/
int maxArea(vector<int>& height) {
    int n = height.size();
    int l = 0,r=n-1;
    int current_max_surface=0;
    while(l<=r && r>=0 && l<n){
        if(height[l]>height[r]){
            current_max_surface=max(current_max_surface,height[r]*(r-l));
            r--;
        }
        else {
            current_max_surface=max(current_max_surface,height[l]*(r-l));
            l++;
        }
    }
    return current_max_surface;
}
int main(){

}

