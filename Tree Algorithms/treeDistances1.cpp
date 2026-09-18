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
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for(int i=0;i<n-1;i++) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vector<int> d1(n + 1), d2(n + 1);
    int startNode = 1;
    function<int(int)> f = [&](int root) {
        queue<pair<int, int>> q;
        q.push({root, 0});
        vector<int> dist(n + 1, 1e9);
        dist[root] = 0;
        while(!q.empty()) {
            auto [node, d] = q.front();
            q.pop();
            if (d > dist[node]) continue;
            for(auto adjNode: adj[node]) {
                if (dist[adjNode] > d + 1) {
                    dist[adjNode] = d + 1;
                    q.push({adjNode, d + 1});
                }
            }
        }
        startNode = max_element(dist.begin() + 1, dist.end()) - dist.begin();
        d2 = dist;
        return *max_element(dist.begin() + 1, dist.end());
    };
    f(startNode);
    f(startNode);
    d1 = d2;
    f(startNode);
    for(int i=0;i<=n;i++) 
    d1[i] = max(d1[i], d2[i]);
    for(int i=1;i<n + 1;i++)
        cout << d1[i] << " ";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}