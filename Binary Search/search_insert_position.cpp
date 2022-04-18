#include <iostream>
#include <vector>
using namespace std;

int searchInsert(vector<int>& nums, int target) {
    int n = nums.size();
    int l = 0, r = n-1;
    
    while(l <= r) {
        int m = l + (r - l) / 2;
        if(nums[m] == target) {
            return m;
        } else if (nums[m] < target) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }

    return l;
}

int main() {
    int n, target;
    cin>>n>>target;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin>>nums[i];
    }

    cout<<searchInsert(nums, target)<<endl;
    return 0;
}