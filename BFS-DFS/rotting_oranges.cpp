#include <bits/stdc++.h>
using namespace std;


int orangesRotting(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    int minutes = 0;

    queue<pair<int,int>> q;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if(grid[i][j] == 2)
                q.push(make_pair(i, j));
        }
    }

    q.push(make_pair(-1, -1));


    while (!q.empty()) {
        
        pair<int, int> current = q.front();        
        
        while (!(current.first == -1 && current.second == -1)) {
            int i = current.first, j = current.second; 
            int neighbors[4][2] = {{i,j+1}, {i+1, j}, {i, j-1}, {i-1,j}};
            for (int k = 0; k < 4; k++) {
                int r = neighbors[k][0], c = neighbors[k][1];
                if(r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == 1){
                    grid[r][c] = 2;
                    q.push(make_pair(r,c));
                }
            }

            q.pop();
            current = q.front();
        }
        
        q.pop();

        if(!q.empty()) {
            minutes++;
            q.push(make_pair(-1, -1));
        }
    }
    



    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if(grid[i][j] == 1) { 
                return -1;           
            }
        }
    }

    return minutes;
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