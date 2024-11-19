#include <bits/stdc++.h>
using namespace std;
// Problem description link: https://leetcode.com/problems/trapping-rain-water/description/
int trap(vector<int>& height) {
    int n = height.size();
    int il=0,ir=n-1,ml=0,mr=0;
    int water = 0;
    while(il<=ir && ir>=0 & il<n){
        while(ml<=mr && il<=ir && ir>=0 & il<n)
        {
            water+=max(ml-height[il],0);
            if(height[il]>ml)
                ml=height[il];
            il++;
        }
        while(ml>mr && il<=ir && ir>=0 & il<n)
        {
            water+=max(mr-height[ir],0);
            if(height[ir]>mr)
                mr=height[ir];
            ir--;
        }
    }

    return water;
}

int main() {
    vector<int> v = {4,2,0,3,2,5};
    cout << trap(v) << std::endl;
    return 0;
}
