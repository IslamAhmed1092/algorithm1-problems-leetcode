#include <bits/stdc++.h>
using namespace std;

uint32_t reverseBits(uint32_t n) {
    unsigned int count = sizeof(n) * 8 - 1;
    unsigned int reverse_num = n;
      
    n >>= 1; 
    while(n)
    {
       reverse_num <<= 1;       
       reverse_num |= n & 1;
       n >>= 1;
       count--;
    }
    reverse_num <<= count;
    return reverse_num;
}

int main() {
    uint32_t n;
    cin>>n;
    
    cout<<reverseBits(n);
    
    return 0;
}