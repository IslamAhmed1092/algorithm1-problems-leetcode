#include <bits/stdc++.h>
using namespace std;

bool isPermutation(string& s1, int* frequency) {
    int n = s1.size();
    int temp[26];
    for (int i = 0; i < 26; i++) {
        temp[i] = frequency[i];
    }
    
    for (int i = 0; i < n; i++) {
        if(temp[s1[i]-'a'] == 0)
            return false;
        else
            temp[s1[i]-'a'] -= 1;
    }

    return true;
}

bool checkInclusion(string s1, string s2) {
    int n = s1.size(), m = s2.size();

    if(n > m) return false;

    int frequency[26]{0};

    for (int i = 0; i < n; i++) {
        frequency[s2[i]-'a'] += 1;
    }

    if(isPermutation(s1, frequency)) return true;

    for (int i = n; i < m; i++) {
        frequency[s2[i]-'a'] += 1;
        frequency[s2[i-n]-'a'] -= 1;
        if(isPermutation(s1, frequency)) return true;
    }
    

    return false;
}

int main() {
    string s1, s2;
    cin>>s1>>s2;
    cout<<checkInclusion(s1, s2);
    return 0;
}