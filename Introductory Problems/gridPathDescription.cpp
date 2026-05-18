#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define input(a, n) for(int i = 0; i < n; i++) cin >> a[i];
#define output(a) for(auto it: a) cout << it << " ";
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define newline cout << endl;

string s;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

char dir[4] = {'U', 'D', 'L', 'R'};

bool vis[7][7];

int f(int i, int j, int k) {

    if(i == 6 && j == 0) {
        return (k == 48);
    }

    if(k == 48) return 0;

    if ((i == 0 || vis[i - 1][j]) &&
        (i == 6 || vis[i + 1][j]) &&
        j > 0 && !vis[i][j - 1] &&
        j < 6 && !vis[i][j + 1])
        return 0;

    if ((j == 0 || vis[i][j - 1]) &&
        (j == 6 || vis[i][j + 1]) &&
        i > 0 && !vis[i - 1][j] &&
        i < 6 && !vis[i + 1][j])
        return 0;

    vis[i][j] = 1;

    int ans = 0;

    for(int d = 0; d < 4; d++) {

        if(s[k] != '?' && s[k] != dir[d]) continue;

        int r = i + dx[d];
        int c = j + dy[d];

        if(r >= 0 && r < 7 && c >= 0 && c < 7 && !vis[r][c]) {

            ans += f(r, c, k + 1);
        }
    }

    vis[i][j] = 0;

    return ans;
}

void solve() {

    cin >> s;

    memset(vis, 0, sizeof(vis));

    cout << f(0, 0, 0);

    newline
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;

    while(t--) {
        solve();
    }

    return 0;
}