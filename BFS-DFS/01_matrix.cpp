#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int m = mat.size(), n = mat[0].size();
    vector<vector<int>> distances(m, vector<int>(n, INT32_MAX - 10e5));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if(mat[i][j] == 0)
                distances[i][j] = 0;
            else {
                if(i != 0) distances[i][j] = min(distances[i][j], distances[i-1][j]+1);
                if(j != 0) distances[i][j] = min(distances[i][j], distances[i][j-1]+1);
            }
        }
    }

    for (int i = m-1; i >= 0; i--) {
        for (int j = n-1; j >= 0; j--) {
            if(i != m-1) distances[i][j] = min(distances[i][j], distances[i+1][j]+1);
            if(j != n-1) distances[i][j] = min(distances[i][j], distances[i][j+1]+1);
        }
    }


    return distances;
}

int main() {
    int m,n;
    cin>>m>>n;

    vector<vector<int>> mat(m, vector<int>(n));
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin>>mat[i][j];
        }
    }
    
    vector<vector<int>> distances = updateMatrix(mat);
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout<<distances[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}