#include <bits/stdc++.h>
using namespace std;

int minimumPathSum(int d, int i, vector<vector<int>>& triangle, vector<vector<int>> &dp) {
    if(d >= triangle.size() || i >= triangle[d].size())
        return 0;
    
    if(dp[d][i] != INT32_MIN)
        return dp[d][i];

    dp[d][i] = min(
        triangle[d][i] + minimumPathSum(d+1,i,triangle,dp),
        triangle[d][i] + minimumPathSum(d+1,i+1,triangle,dp)
    );
    
    return dp[d][i];
}

int minimumTotal(vector<vector<int>>& triangle) {
    vector<vector<int>> dp(triangle.size(), vector<int>(triangle.size(), INT32_MIN));
    return minimumPathSum(0, 0, triangle, dp);
}

int main() {
    int n;
    cin>>n;
    
    vector<vector<int>> triangle(n);

    int temp;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            cin>>temp;
            triangle[i-1].push_back(temp);
        }
        
    }
    

    cout<<minimumTotal(triangle);    

    return 0;
}