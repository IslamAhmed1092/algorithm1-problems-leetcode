#include <bits/stdc++.h>
using namespace std;

vector<int> sortedSquares(vector<int>& nums) {
    int n = nums.size();
    
    int posIdx = n, negIdx = n-1;
    for (int i = 0; i < n; i++) {
        if(nums[i] > 0) {
            posIdx = i;
            negIdx = i-1;
            break;
        }
    }
    
    vector<int> result;

    while (posIdx < n && negIdx >= 0) {
        int num1 = nums[posIdx] * nums[posIdx];
        int num2 = nums[negIdx] * nums[negIdx];

        if(num1 <= num2) {
            result.push_back(num1);
            posIdx++;
        } else {
            result.push_back(num2);
            negIdx--;
        }
    }
    
    while(posIdx < n) {
        result.push_back(nums[posIdx] * nums[posIdx]);
        posIdx++;
    }

    while(negIdx >= 0) {
        result.push_back(nums[negIdx] * nums[negIdx]);
        negIdx--;
    }

    return result;
}

int main() {
    int n;
    cin>>n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin>>nums[i];
    }
    
    vector<int> result = sortedSquares(nums);
    
    for (int i = 0; i < result.size(); i++) {
        cout<<result[i]<<" ";
    }
    
    return 0;
}