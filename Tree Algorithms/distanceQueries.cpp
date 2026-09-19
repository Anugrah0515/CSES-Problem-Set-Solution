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

void solve() {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> adj(n + 1);
    for(int i=0;i<n-1;i++) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    int LOG = 20;
    vector<int> depth(n + 1);
    vector<vector<int>> up(n + 1, vector<int>(LOG));
    function<void(int, int)> f = [&](int node, int parent) {
        depth[node] = depth[parent] + 1;
        up[node][0] = parent;
        for(int i=1;i<LOG;i++) 
            up[node][i] = up[up[node][i - 1]][i - 1];
        
        for(auto it: adj[node]) {
            if (it == parent) continue;
            f(it, node);
        }
    };

    function<int(int, int)> lca = [&](int a, int b) {
        if (depth[a] < depth[b]) swap(a, b);
        int diff = depth[a] - depth[b];
        for(int i=0;i<LOG;i++) 
            if(diff & (1 << i))
                a = up[a][i];
        if (a != b) {
            for(int i = LOG-1;i>=0;i--) {
                if (up[a][i] != up[b][i]) {
                    a = up[a][i];
                    b = up[b][i];
                }
            }
            a = up[a][0];
        }
        return a;
    };

    f(1, 0);

    while(q--) {
        int a, b;
        cin >> a >> b;
        int c = lca(a, b);
        cout << depth[a] + depth[b] - 2 * depth[c] << endl;        
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