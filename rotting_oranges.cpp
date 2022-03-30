#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& grid, int i, int j, int time, vector<vector<int>>& times) {
    int m = grid.size(), n = grid[0].size();
    
    int neighbors[4][2] = {{i,j+1}, {i+1, j}, {i, j-1}, {i-1,j}};

    for (int k = 0; k < 4; k++) {
        int r = neighbors[k][0], c = neighbors[k][1];
        if(r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == 1 && time+1 < times[r][c]){
            times[r][c] = time+1;
            dfs(grid, r, c, time+1, times);
        }
    }
    
}

int orangesRotting(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> times(m, vector<int>(n, INT32_MAX));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if(grid[i][j] == 2)
                dfs(grid, i, j, 0, times);
        }
    }

    int maxTime = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if(grid[i][j] == 1) { 
                if(times[i][j] == INT32_MAX) return -1;
                maxTime = max(maxTime, times[i][j]);           
            }
        }
    }

    return maxTime;
}

int main() {
    int m, n;
    cin>>m>>n;
    
    vector<vector<int>> grid(m, vector<int>(n));
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin>>grid[i][j];
        }
    }
    
    cout<<orangesRotting(grid);
    
    return 0;
}