#include <bits/stdc++.h>
using namespace std;


int robRecursive(int i, vector<int>& nums, vector<int>& dp) {
    if(i >= nums.size())
        return 0;
    
    if(dp[i] != -1)
        return dp[i];
    
    dp[i] = max(robRecursive(i+1, nums, dp), nums[i] + robRecursive(i+2, nums, dp));

    return dp[i];
}

int rob(vector<int>& nums) {
    vector<int> dp(nums.size(), -1);
    return robRecursive(0, nums, dp);
}

int main() {
    int n;
    cin>>n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin>>nums[i];
    }
    
    cout<<rob(nums);
    
    
    return 0;
}