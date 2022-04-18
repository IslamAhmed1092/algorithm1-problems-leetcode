#include <bits/stdc++.h>
using namespace std;

vector<int> permutation;

void permuteRecursive(vector<int>& nums, vector<vector<int>> &permutations) {
    int n = nums.size();
    if(permutation.size() == n) {
        permutations.push_back(permutation);
        return;
    }
    
    for (int i = 0; i < n; i++) {
        if(find(permutation.begin(), permutation.end(), nums[i]) != permutation.end())
            continue;
        permutation.push_back(nums[i]);
        permuteRecursive(nums, permutations);
        permutation.pop_back();
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> permutations;
    permuteRecursive(nums, permutations);
    return permutations;
}

int main() {
    int n;
    cin>>n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin>>nums[i];
    }
    
    vector<vector<int>> permutations = permute(nums);
    
    cout<<"[";
    for (int i = 0; i < permutations.size(); i++) {
        cout<<"[";
        for (int j = 0; j < permutations[i].size(); j++) {
            cout<<permutations[i][j];
            if(j != permutations[i].size()-1)
                cout<<",";
        }
        cout<<"]";
        if(i != permutations.size()-1)
            cout<<",";
    }
    
    cout<<"]";
    
    
    return 0;
}