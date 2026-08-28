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

struct Node {
    int dist;
    int row;
    int col;
    string path;
};

void solve() {
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    input(grid, n);

    pair<int, int> start, dest;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'A')
                start = {i, j};
            if (grid[i][j] == 'B')
                dest = {i, j};
        }
    }

    vector<vector<int>> vis(n, vector<int>(m, 0));
    vector<vector<pair<int, int>>> parent(n,
        vector<pair<int, int>>(m, {-1, -1}));
    vector<vector<char>> moveTaken(n,
        vector<char>(m));

    queue<pair<int, int>> q;
    q.push(start);
    vis[start.first][start.second] = 1;

    vector<pair<pair<int, int>, char>> dir = {
        {{0, 1}, 'R'},
        {{1, 0}, 'D'},
        {{0, -1}, 'L'},
        {{-1, 0}, 'U'}
    };

    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        if (make_pair(r, c) == dest)
            break;

        for (auto [d, ch] : dir) {
            int nr = r + d.first;
            int nc = c + d.second;

            if (nr >= 0 && nr < n &&
                nc >= 0 && nc < m &&
                !vis[nr][nc] &&
                grid[nr][nc] != '#') {

                vis[nr][nc] = 1;
                parent[nr][nc] = {r, c};
                moveTaken[nr][nc] = ch;
                q.push({nr, nc});
            }
        }
    }

    if (!vis[dest.first][dest.second]) {
        cout << "NO" << endl;
        return;
    }

    string ans;
    pair<int, int> cur = dest;

    while (cur != start) {
        ans += moveTaken[cur.first][cur.second];
        cur = parent[cur.first][cur.second];
    }

    reverse(ans.begin(), ans.end());

    cout << "YES" << endl;
    cout << ans.length() << endl;
    cout << ans << endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}