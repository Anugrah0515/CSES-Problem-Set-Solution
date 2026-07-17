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
    int n;
    cin >> n;
    vector<string> grid(n);
    for(auto &it: grid)
        cin >> it;

    vector<pair<int, int>> curr;
    curr.pb({0, 0});
    string path = "";
    path += grid[0][0];
    vector<vector<int>> vis(n, vector<int>(n));
    for(int k=1;k<2 * n - 1;k++) {
        char ch = 'Z' + 1;
        for(auto [r, c]: curr) {
            if (r < n - 1) ch = min(ch, grid[r + 1][c]);
            if (c < n - 1) ch = min(ch, grid[r][c + 1]);
        }
        path += ch;
        for(auto [r, c]: curr) {
            if (r < n - 1) vis[r + 1][c] = 0;
            if (c < n - 1) vis[r][c + 1] = 0;
        }
        vector<pair<int, int>> next;
        for(auto [r, c]: curr) {
            if (r + 1 < n && grid[r + 1][c] == ch && !vis[r + 1][c])
                vis[r + 1][c] = 1, next.pb({r + 1, c});
            if (c + 1 < n && grid[r][c + 1] == ch && !vis[r][c + 1])
                vis[r][c + 1] = 1, next.pb({r, c + 1});
        }
        curr = next;
    }
    cout << path << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}