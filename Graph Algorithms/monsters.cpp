#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define input(a, n) for (int i = 0; i < n; i++) cin >> a[i];
#define output(a) for (auto it : a) cout << it << " ";
#define sortFcn(a) sort(a.begin(), a.end());
#define revPrint(a, n) for(int i=n-1;i>=0;i--) cout << a[i] << " ";
#define rev(a) reverse(a.begin(), a.end());
#define lowerBound(a, x) lower_bound(a.begin(), a.end(), x)
#define upperBound(a, x) upper_bound(a.begin(), a.end(), x)
#define impossible cout << "IMPOSSIBLE" << endl;
#define newline cout << endl;
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;

int MOD = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    input(grid, n);

    const int INF = 1e9;

    vector<vector<int>> monsterTime(n, vector<int>(m, INF));

    queue<vector<int>> q;
    pair<int, int> start;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'M') {
                monsterTime[i][j] = 0;
                q.push({i, j, 0});
            }
            else if (grid[i][j] == 'A') {
                start = {i, j};
            }
        }
    }

    vector<int> dr = {0, 1, 0, -1};
    vector<int> dc = {1, 0, -1, 0};

    // Monster BFS
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        int row = cur[0], col = cur[1], time = cur[2];

        for (int k = 0; k < 4; k++) {
            int r = row + dr[k];
            int c = col + dc[k];

            if (r >= 0 && r < n && c >= 0 && c < m &&
                grid[r][c] != '#' &&
                monsterTime[r][c] > time + 1) {

                monsterTime[r][c] = time + 1;
                q.push({r, c, time + 1});
            }
        }
    }

    // If already on boundary
    if (start.first == 0 || start.first == n - 1 ||
        start.second == 0 || start.second == m - 1) {
        yes
        cout << 0 << '\n';
        cout << '\n';
        return;
    }

    vector<vector<int>> dist(n, vector<int>(m, INF));
    vector<vector<pair<int, int>>> parent(
        n, vector<pair<int, int>>(m, {-1, -1}));
    vector<vector<char>> moveTaken(n, vector<char>(m));

    vector<pair<pair<int, int>, char>> dir = {
        {{0, 1}, 'R'},
        {{0, -1}, 'L'},
        {{1, 0}, 'D'},
        {{-1, 0}, 'U'}
    };

    dist[start.first][start.second] = 0;
    q.push({start.first, start.second, 0});

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        int row = cur[0], col = cur[1], time = cur[2];

        if (row == 0 || row == n - 1 || col == 0 || col == m - 1) {
            string path;

            pair<int, int> node = {row, col};

            while (node != start) {
                path += moveTaken[node.first][node.second];
                node = parent[node.first][node.second];
            }

            reverse(path.begin(), path.end());

            yes
            cout << path.size() << '\n';
            cout << path << '\n';
            return;
        }

        for (auto [d, ch] : dir) {
            int r = row + d.first;
            int c = col + d.second;

            if (r >= 0 && r < n && c >= 0 && c < m &&
                grid[r][c] != '#' &&
                dist[r][c] > time + 1 &&
                time + 1 < monsterTime[r][c]) {

                dist[r][c] = time + 1;
                parent[r][c] = {row, col};
                moveTaken[r][c] = ch;
                q.push({r, c, time + 1});
            }
        }
    }

    no
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}