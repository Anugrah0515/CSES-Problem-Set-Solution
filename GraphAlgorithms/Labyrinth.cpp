#include <bits/stdc++.h>
using namespace std;
 
vector<int> drow{0, 1, 0, -1}, dcol{1, 0, -1, 0}; // R D L U
vector<char> dir{'R', 'D', 'L', 'U'};
string ans = "";
 
void bfs(int row, int col, vector<vector<char>>& grid, vector<vector<bool>>& vis, int n, int m, pair<int, int> destination) {
    queue<pair<int, int>> q;
    vector<vector<int>> parentDir(n, vector<int>(m, -1));
    q.push({row, col});
    vis[row][col] = true; 
    
    while(!q.empty()) {
        auto node = q.front();
        q.pop();
        
        if (node == destination) {
            string path = "";
            while (node != make_pair(row, col)) {
                int d = parentDir[node.first][node.second];
                path += dir[d];
                node = {node.first - drow[d], node.second - dcol[d]};
            }
            reverse(path.begin(), path.end());
            if (ans.empty() || ans.length() > path.length()) {
                ans = path;
            }
            return; 
        }
        
        for(int i = 0; i < 4; i++) {
            int r = node.first + drow[i], c = node.second + dcol[i];
            if (r < n && c < m && r >= 0 && c >= 0 && !vis[r][c] && grid[r][c] != '#') {
                vis[r][c] = true;
                parentDir[r][c] = i;
                q.push({r, c});
            }
        }
    }
}
 
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    pair<int, int> source, destination;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'A') source = {i, j};
            else if (grid[i][j] == 'B') destination = {i, j};
        }
    }
    
    bfs(source.first, source.second, grid, vis, n, m, destination);
    
    if (ans.empty()) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        cout << ans.length() << endl;
        cout << ans << endl;
    }
    
    return 0;
}