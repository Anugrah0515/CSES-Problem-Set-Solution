#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define input(a, n) for (int i = 0; i < n; i++) cin >> a[i];
#define output(a) for (auto it : a) cout << it << " ";
#define sortFcn(a) sort(a.begin(), a.end());
#define rev(a) reverse(a.begin(), a.end());
#define lowerBound(a, x) lower_bound(a.begin(), a.end(), x)
#define upperBound(a, x) upper_bound(a.begin(), a.end(), x)
#define impossible cout << "IMPOSSIBLE" << endl;

int MOD = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    input(grid, n);

    vector<vector<int>> vis(n, vector<int>(m));
    vector<int> dx{0, 1, 0, -1}, dy{1, 0, -1, 0};
    function<void(int, int)> dfs = [&](int r, int c) {
        vis[r][c] = 1;
        for(int i=0;i<4;i++) {
            int row = r + dx[i];
            int col = c + dy[i];
            if (row < n && col < m && row >= 0 && col >= 0 && grid[row][col] == '.' && !vis[row][col]) {
                dfs(row, col);
            }
        }
    };
    int rooms = 0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++) {
            if (!vis[i][j] && grid[i][j] == '.') {
                dfs(i, j);
                rooms++;
            }
        }
    cout << rooms << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}