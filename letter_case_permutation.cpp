#include <bits/stdc++.h>
using namespace std;

void casePermutationRecursive(string s, int idx, vector<string> &permutations) {
    if(idx == s.size()) {
        permutations.push_back(s);
        return;
    }
    
    casePermutationRecursive(s, idx+1, permutations);
    
    if(s[idx] >= 'A' && s[idx] <= 'Z') {
        s[idx] = s[idx] - 'A' + 'a';
    } else if(s[idx] >= 'a' && s[idx] <= 'z') {
        s[idx] = s[idx] - 'a' + 'A';
    } else {
        return;
    }
    
    casePermutationRecursive(s, idx+1, permutations);

}

vector<string> letterCasePermutation(string s) {
    vector<string> permutations;
    casePermutationRecursive(s, 0, permutations);
    return permutations;
}

int main() {
    string s;
    cin>>s;
    
    vector<string> permutations = letterCasePermutation(s);
    
    cout<<"[";
    for (int i = 0; i < permutations.size(); i++) {
        cout<<"\""<<permutations[i]<<"\"";
        if(i != permutations.size()-1)
            cout<<",";
    }
    cout<<"]";

    return 0;
}