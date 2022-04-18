#include <bits/stdc++.h>
using namespace std;

vector<int> combination;

void combineRecursive(int number, int n, int k, vector<vector<int>> &combinations) {

    if(k == 0) {
        combinations.push_back(combination);
        return;
    }
    
    for (int i = number; i <= n - k + 1; i++) {
        combination.push_back(i);
        combineRecursive(i+1, n, k-1, combinations);
        combination.pop_back();
    }
}

vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> combinations;

    combineRecursive(1, n, k, combinations);
    
    return combinations;
}

int main() {
    int n, k;
    cin>>n>>k;
    
    vector<vector<int>> result = combine(n, k);

    cout<<"["<<endl;
    for (int i = 0; i < result.size(); i++) {
        cout<<"\t[";
        for (int j = 0; j < result[i].size(); j++) {
            cout<<result[i][j];
            if(j != result[i].size()-1)
                cout<<",";
        }
        cout<<"],"<<endl;
    }
    
    cout<<"]"<<endl;

    return 0;
}