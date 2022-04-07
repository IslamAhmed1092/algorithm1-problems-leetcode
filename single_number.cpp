#include <bits/stdc++.h>
using namespace std;

int singleNumber(vector<int>& nums) {
    int number = 0;
    for (int num : nums) {
        number ^= num;
    }
    
    return number;
}

int main() {
    int n;
    cin>>n;
    
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin>>nums[i];
    }
    
    cout<<singleNumber(nums);
    
    return 0;
}