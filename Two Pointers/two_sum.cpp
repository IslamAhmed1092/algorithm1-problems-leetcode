#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
    int n = numbers.size();
    vector<int> result(2);

    for (int i = 0; i < n; i++) {
        int l = i+1;
        int r = n-1;
        while(l <= r) {
            int m = l + (r-l)/2;
            if(numbers[m] + numbers[i] == target) {
                result[0] = i+1;
                result[1] = m+1;
                return result; 
            } else if(numbers[m] + numbers[i] > target) {
                r = m-1;
            } else {
                l = m+1;
            }
        }
    }   
    
    return result;
}

int main() {
    int n, target;
    cin>>n>>target;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin>>nums[i];
    }

    vector<int> result = twoSum(nums, target);
    
    for (int i = 0; i < (int)result.size(); i++) {
        cout<<result[i]<<" ";
    }
    
    return 0;
}