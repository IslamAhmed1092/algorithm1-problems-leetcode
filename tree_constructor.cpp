#include <bits/stdc++.h>
using namespace std;

string TreeConstructor(string strArr[], int arrLength) {
  
    // code goes here  
    map<int, vector<int>> graph;
    for (int i = 0; i < arrLength; i++) {
        int commaIdx = strArr[i].find(',');
        int child = stoi(strArr[i].substr(1, commaIdx));
        int parent = stoi(strArr[i].substr(commaIdx+1, strArr[i].size()-1));
        graph[parent].push_back(child);
        if(graph[parent].size() > 2)
            return "false";
    }



    return "true";
}


int main() {
    int n;
    cin>>n;
    string strArr[n];

    for (int i = 0; i < n; i++) {
        cin>>strArr[i];
    }
    
    cout<<TreeConstructor(strArr, n);
    
    return 0;
}