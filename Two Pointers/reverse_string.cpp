#include <bits/stdc++.h>
using namespace std;

void reverseString(vector<char>& s) {
    int n = s.size();
    
    char temp;
    for (int i = 0; i < n/2; i++) {
        temp = s[i];
        s[i] = s[n-i-1];
        s[n-i-1] = temp;
    }
    
}

int main() {
    int n;
    cin>>n;

    vector<char> s(n);
    for (int i = 0; i < n; i++) {
        cin>>s[i];
    }
    
    reverseString(s);

    for (int i = 0; i < n; i++) {
        cout<<s[i]<<" ";
    }
    
    
    return 0;
}