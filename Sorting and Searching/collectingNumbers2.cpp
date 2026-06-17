#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define input(a, n) for(int i = 0; i < n; i++) cin >> a[i];
#define output(a) for(auto it: a) cout << it << " ";
#define sortFcn(a) sort(a.begin(), a.end());
#define lowerBound(a, x) lower_bound(a.begin(), a.end(), x)
#define upperBound(a, x) upper_bound(a.begin(), a.end(), x)
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define newline cout << endl;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    input(a, n);

    vector<int> pos(n + 1);
    for(int i=0;i<n;i++) 
        pos[a[i]] = i + 1;

    int cnt = 1;
    for(int i=1;i<n;i++) 
        cnt += (pos[i] > pos[i + 1]);

    while(m--) {
        int l, r;
        cin >> l >> r;
        l--;r--;

        int x = a[l], y = a[r];

        set<pair<int,int>> affected;

        for (int v : {x, y}) {
            if (v > 1) affected.insert({v-1, v});
            if (v < n) affected.insert({v, v+1});
        }

        // remove old contribution
        for (auto [u, v] : affected) {
            if (pos[u] > pos[v]) cnt--;
        }

        // swap
        swap(a[l], a[r]);
        swap(pos[x], pos[y]);

        // add new contribution
        for (auto [u, v] : affected) {
            if (pos[u] > pos[v]) cnt++;
        }

        cout << cnt;
        newline
    }

}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}