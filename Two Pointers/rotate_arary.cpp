#include <bits/stdc++.h>
using namespace std;

void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    int count = 0;
    for (int i=0; i<n && count < n; i++) {
        int currentIndex = i;
        int newIndex = (currentIndex + k) % n;
        
        int currentTemp = nums[currentIndex];
        int nextTemp;
        
        while (newIndex != i) {
            nextTemp = nums[newIndex];
            nums[newIndex] = currentTemp;
            currentIndex = newIndex;
            
            newIndex = (currentIndex + k) % n;
            currentTemp = nextTemp;
            
            //how many replacements has been done
            count ++;
        }
        //assign value from where we started
        nums[newIndex] = currentTemp;
        count ++;
    }
}

int main() {
    int n,k;
    cin>>n>>k;
    
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin>>nums[i];
    }
    
    rotate(nums, k);
    
    for (int i = 0; i < n; i++) {
        cout<<nums[i]<<" ";
    }
    
    return 0;
}