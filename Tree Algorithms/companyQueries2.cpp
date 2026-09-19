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
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define newline cout << endl;

int MOD = 1e9 + 7;
int LOG = 20;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> up(n + 1, vector<int>(LOG + 1));
    for (int i = 2; i <= n; i++) {
        cin >> up[i][0];
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=LOG;j++) {
            up[i][j] = up[up[i][j-1]][j-1];
        }
    }
    vector<int> depth(n + 1);
    depth[1] = 0;
    for(int i=2;i<=n;i++)
        depth[i] = depth[up[i][0]] + 1;
    
    while (q--) {
        int a, b;
        cin >> a >> b;

        if (depth[a] < depth[b])
            swap(a, b);

        int diff = depth[a] - depth[b];

        for (int j = 0; j <= LOG; j++) {
            if (diff & (1 << j)) {
                a = up[a][j];
            }
        }

        if (a != b) {
            for (int j = LOG; j >= 0; j--) {
                if (up[a][j] != up[b][j]) {
                    a = up[a][j];
                    b = up[b][j];
                }
            }

            a = up[a][0];
        }

        cout << a << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}