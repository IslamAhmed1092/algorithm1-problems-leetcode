#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
    int n = s.size();
    int longestSubstring = 0;
    
    for (int i=0; i<n; i++) {
        int foundCharacters[128]{0};
        foundCharacters[s[i]] = 1;
        int currentSubstring = 1;
        for (int j = i+1; j < n; j++) {
            if(foundCharacters[s[j]] == 1) {
                break;
            } else {
                currentSubstring++;
                foundCharacters[s[j]] = 1;
            }
        }

        if(currentSubstring > longestSubstring) {
            longestSubstring = currentSubstring;
        }
           
    }
    
    return longestSubstring;
}

int main() {
    string s;    
    getline(cin,s);
    
    cout<<lengthOfLongestSubstring(s)<<endl;
    return 0;
}