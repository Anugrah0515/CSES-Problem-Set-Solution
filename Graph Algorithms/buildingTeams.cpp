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

int MOD = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    while(m--) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    vector<int> color(n + 1);
    queue<pair<int, int>> q;
    for(int i=1;i<=n;i++) {
        if (!color[i]) {
            q.push({i, 1});
            color[i] = 1;
            while(!q.empty()) {
                auto it = q.front();
                int node = it.first;
                int team = it.second;
                q.pop();
                for(auto adjNode: adj[node]) {
                    if (!color[adjNode]) {
                        color[adjNode] = (team == 1 ? 2 : 1);
                        q.push({adjNode, color[adjNode]});
                    } else if (team == color[adjNode]) {
                        impossible
                        return;
                    }
                }
            }
        }
    }
    for(int i=1;i<=n;i++)
        cout << color[i] << " ";
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