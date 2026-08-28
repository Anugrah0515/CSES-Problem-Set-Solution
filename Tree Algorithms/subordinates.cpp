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
    vector<int> a(n - 1);
    input(a, n - 1);

    vector<vector<int>> adj(n + 1);
    for(int i=0;i<n - 1;i++) 
        adj[a[i]].pb(i + 2);
    vector<int> subs(n + 1);
    function<int(int)> f = [&](int node) {
        int cnt = 0;
        for(auto adjNode: adj[node]) {
            cnt += f(adjNode);
        }
        subs[node] = cnt;
        return cnt + 1;
    };
    f(1);
    for(int i=1;i<=n;i++) {
        cout << subs[i] << " ";
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