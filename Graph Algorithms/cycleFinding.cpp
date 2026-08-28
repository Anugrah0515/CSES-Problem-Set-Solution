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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges;
    while(m--) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.pb({a, b, c});
    }
    
    vector<ll> dist(n + 1, 0);
    vector<int> parent(n + 1, -1);

    int x = -1;

    for (int i = 0; i < n; i++) {
        x = -1;

        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            ll wt = it[2];

            if (dist[v] > dist[u] + wt) {
                dist[v] = dist[u] + wt;
                parent[v] = u;

                if (i == n - 1) {
                    x = v;
                }
            }
        }
    }

    if (x == -1) {
        no
        return;
    }

    // Move inside the cycle
    for (int i = 0; i < n; i++) {
        x = parent[x];
    }

    // Reconstruct cycle
    vector<int> cycle;
    int cur = x;

    do {
        cycle.pb(cur);
        cur = parent[cur];
    } while (cur != x);

    cycle.pb(x);
    rev(cycle)
    yes
    output(cycle)
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}