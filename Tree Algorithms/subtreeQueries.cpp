#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define input(a, n) for (int i = 0; i < n; i++) cin >> a[i];
#define output(a) for (auto it : a) cout << it << " ";
#define sortFcn(a) sort(a.begin(), a.end());
#define revPrint(a, n) for(int i=n-1;i>=0;i--) cout << a[i] << " ";
#define rev(a) reverse(a.begin(), a.end());
#define lowerBound(a, query) lower_bound(a.begin(), a.end(), query)
#define upperBound(a, query) upper_bound(a.begin(), a.end(), query)
#define impossible cout << "IMPOSSIBLE" << endl;
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define newline cout << endl;

int MOD = 1e9 + 7;

class SegmentTree {
private:
    vector<ll> seg;
    int n;
    void build(int l, int r, vector<ll>& arr, int idx) {
        if (l == r) {
            seg[idx] = arr[l];
            return;
        }
        int mid = l + (r - l) / 2;
        build(l, mid, arr, 2 * idx);
        build(mid + 1, r, arr, 2 * idx + 1);
        seg[idx] = seg[2 * idx] + seg[2 * idx + 1];
        return;
    }

    void update(int l, int r, int idx, int pos, int val) {
        if (l == r) {
            seg[idx] = val;
            return;
        }

        int mid = l + (r - l) / 2;
        if (pos <= mid) update(l, mid, 2 * idx, pos, val);
        else update(mid + 1, r, 2 * idx + 1, pos, val);
        seg[idx] = seg[2 * idx] + seg[2 * idx + 1];
        return;
    }

    ll sum(int l, int r, int idx, int ql, int qr) {
        if (l > qr || r < ql) return 0;
        if (ql <= l && qr >= r) return seg[idx];
        int mid = l + (r - l) / 2;
        return sum(l, mid, 2 * idx, ql, qr) + sum(mid + 1, r, 2 * idx + 1, ql, qr);
    }
public: 
    SegmentTree(vector<ll> arr) {
        n = arr.size();
        seg.resize(4 * n + 1);
        build(0, n - 1, arr, 1);
    }

    ll sum(int ql, int qr) {
        return sum(0, n - 1, 1, ql, qr);
    }

    void update(int pos, int val) {
        update(0, n - 1, 1, pos, val);
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> adj(n + 1);
    vector<int> values(n + 1);
    for(int i=0;i<n;i++) 
        cin >> values[i + 1];
    for(int i=0;i<n-1;i++) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    vector<ll> tin(n + 1), tout(n + 1), flatten(n);
    int time = 0;
    function<void(int, int)> f = [&](int node, int parent) {
        tin[node] = time;
        flatten[time] = values[node];
        time++;
        for(auto it: adj[node]) 
            if (it != parent) 
                f(it, node);
        tout[node] = time - 1;
    };
    f(1, 0);
    SegmentTree seg(flatten);

    while(q--) {
        int query, node;
        cin >> query >> node;
        if (query == 1) {
            int val;
            cin >> val;
            seg.update(tin[node], val);
        } else {
            cout << seg.sum(tin[node], tout[node]) << endl;
        }
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