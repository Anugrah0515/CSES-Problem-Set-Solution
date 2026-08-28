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
    vector<vector<int>> adj(n + 1);
    vector<int> indegree(n + 1);
    while(m--) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        indegree[b]++;
    }
    
    vector<int> topo;
    queue<int> q;
    for(int i=1;i<n+1;i++) {
        if (!indegree[i]) {
            q.push(i);
        }
    }
    while(!q.empty()) {
        auto node = q.front();
        q.pop();
        topo.pb(node);
        for(auto adjNode: adj[node]) {
            indegree[adjNode]--;
            if (!indegree[adjNode])
                q.push(adjNode);
        }
    }
    if ((int)topo.size() == n) output(topo)
    else impossible
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}