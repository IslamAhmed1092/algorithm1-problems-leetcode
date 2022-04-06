#include <bits/stdc++.h>
using namespace std;

bool isPowerOfTwo(int n) {
    long x = (long) n;
    return (x != 0) && (x & (x - 1)) == 0;
}

int main() {
    int n;
    cin>>n;
    cout<<isPowerOfTwo(n);
    
    return 0;
}