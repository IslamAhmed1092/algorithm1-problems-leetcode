#include <bits/stdc++.h>
using namespace std;

#define MAX 46
int dp[MAX];


int climbStairs(int n) {
    if(n == 0) {
        return 1;
    }

    if(n < 0 )
        return 0;

    if(dp[n] != 0)
        return dp[n];
    
    dp[n] = climbStairs(n-1) + climbStairs(n-2);

    return dp[n];
}

int main() {
    int n;
    cin>>n;
    
    cout<<climbStairs(n)<<endl;

    return 0;
}