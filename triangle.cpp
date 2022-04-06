#include <bits/stdc++.h>
using namespace std;


int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    vector<int> dp(n+1, 0);

    for (int d = n-1; d >= 0; d--) {
        for (int i = 0; i <= d; i++) {
            dp[i] = min(dp[i], dp[i+1]) + triangle[d][i];
        }
    }
    
    return dp[0];
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