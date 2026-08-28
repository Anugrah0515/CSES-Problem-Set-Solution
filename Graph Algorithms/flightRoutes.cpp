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
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<pair<int, ll>>> adj(n + 1);

    while (m--) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        adj[a].pb({b, c});
    }

    // cnt[i] = how many times city i has been processed
    vector<int> cnt(n + 1, 0);

    // {cost, city}
    priority_queue<
        pair<ll, int>,
        vector<pair<ll, int>>,
        greater<pair<ll, int>>
    > pq;

    pq.push({0, 1});

    vector<ll> ans;

    while (!pq.empty()) {
        auto [cost, u] = pq.top();
        pq.pop();

        // We only need the k shortest routes to each city
        if (cnt[u] >= k)
            continue;

        cnt[u]++;

        // Reached destination
        if (u == n) {
            ans.pb(cost);

            if (ans.size() == k)
                break;
        }

        for (auto [v, weight] : adj[u]) {
            pq.push({cost + weight, v});
        }
    }

    output(ans);
    newline;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}