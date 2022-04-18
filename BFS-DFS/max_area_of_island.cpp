#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int r, int c, int& area) {
    area++;
    visited[r][c] = true;

    int rows[] = {r, r, r-1, r+1};
    int columns[] = {c-1, c+1, c, c};

    for (int i = 0; i < 4; i++) {
        int r_new = rows[i], c_new = columns[i];
        if(r_new >= 0 && r_new < grid.size() && c_new >= 0 && c_new < grid[0].size() &&
                grid[r_new][c_new] == 1 && !visited[r_new][c_new]) 
            dfs(grid, visited, r_new, c_new, area);
    }
    
}

int maxAreaOfIsland(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    
    vector<vector<bool>> visited(m, vector<bool>(n));

    int maxArea = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if(!visited[i][j] && grid[i][j] == 1) {
                int currentArea = 0;
                dfs(grid, visited, i, j, currentArea);
                maxArea = max(currentArea, maxArea);
            }
        }
    }
    
    return maxArea;
}

int main() {
    int m, n;
    cin>>m>>n;
    
    vector<vector<int>> grid(m, vector<int> (n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin>>grid[i][j];
        }        
    }
    
    cout<<maxAreaOfIsland(grid)<<endl;

    return 0;
}