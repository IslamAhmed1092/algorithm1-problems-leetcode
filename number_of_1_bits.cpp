#include <bits/stdc++.h>
using namespace std;

// #define B2(n) n, n + 1, n + 1, n + 2
// #define B4(n) B2(n) \, B2(n + 1), B2(n + 1), B2(n + 2)
// #define B6(n) B4(n) \, B4(n + 1), B4(n + 1), B4(n + 2)
 
// unsigned int lookuptable[256] = { B6(0), B6(1), B6(1), B6(2) };

int hammingWeight(uint32_t n) {
    int count = 0;
    while(n) {
        n &= (n-1);
        count++;
    }

    return count;
}

int main() {
    uint32_t n;
    cin>>n;
    cout<<hammingWeight(n);
    return 0;
}