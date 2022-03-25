#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& image, vector<vector<bool>>& visited, int sr, int sc, int srcColor, int newColor) {
    
    image[sr][sc] = newColor;
    visited[sr][sc] = true;

    int rows[] = {sr, sr, sr-1, sr+1};
    int columns[] = {sc-1, sc+1, sc, sc};

    for (int i = 0; i < 4; i++) {
        int r = rows[i], c = columns[i];
        if(r < 0 || r >= image.size() || c < 0 || c >= image[0].size() ||
                image[r][c] != srcColor || visited[r][c]) 
            continue;
        
        dfs(image, visited, r, c, srcColor, newColor);
    }
    
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    vector<vector<bool>> visited(image.size(), vector<bool>(image[0].size()));
    dfs(image, visited, sr, sc, image[sr][sc], newColor);
    return image;
}

int main() {
    int m, n;
    cin>>m>>n;

    int sr, sc, newColor;
    cin>>sr>>sc>>newColor;

    vector<vector<int>> image(m, vector<int> (n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin>>image[i][j];
        }        
    }
    
    floodFill(image, sr, sc, newColor);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout<<image[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}