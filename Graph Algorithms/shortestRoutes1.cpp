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
    vector<vector<pair<int, ll>>> adj(n + 1);
    while(m--) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        adj[a].pb({b, c});
    }

    vector<ll> dist(n + 1, 1e18);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({0, 1});
    dist[1] = 0;
    while(!pq.empty()) {
        auto it = pq.top();
        pq.pop();
        int node = it.second;
        ll d = it.first;
        if (d > dist[node]) continue;
        for(auto [adjNode, wt]: adj[node]) {
            if (dist[adjNode] > d + wt) {
                dist[adjNode] = d + wt;
                pq.push({d + wt, adjNode});
            }
        }
    }
    for(int i=1;i<=n;i++) {
        cout << dist[i] << " ";
    }
    newline
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}