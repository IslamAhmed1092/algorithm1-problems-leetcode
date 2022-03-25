#include <iostream>
#include <vector>

using namespace std;


int search(vector<int>& nums, int target) {
    int n = nums.size();
    int l = 0, r = n-1;
    
    while(l <= r) {
        int m = (l + r) / 2;
        if(nums[m] == target) {
            return m;
        } else if (nums[m] < target) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }

    return -1;
}

int main() {

    int n, target;

    cin>>n;
    cin>>target;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin>>nums[i];
    }
    
    cout<<search(nums, target);
}