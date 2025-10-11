#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    for(auto &it: grid)
        for(auto &ch: it)
            cin >> ch;
    vector<int> dx{0, 1, 0, -1}, dy{1, 0, -1, 0};
    vector<vector<int>> vis(n, vector<int>(m));
    int count = 0;
    
    function<void(int, int)> dfs = [&](int x, int y) {
        vis[x][y] = 1;
        for(int i=0;i<4;i++) {
            int r = x + dx[i];
            int c = y + dy[i];
            if (r < n && r >= 0 && c < m && c >= 0 && !vis[r][c] && grid[r][c] == '.')
                dfs(r, c);
        }
    };

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if (!vis[i][j] && grid[i][j] == '.') {
                count++;
                dfs(i, j);
            }
        }
    }

    cout << count << endl;
    return 0;
}