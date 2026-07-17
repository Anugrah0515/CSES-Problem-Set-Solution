#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MOD = 1e9 + 7;

class SegmentTree {
public:
    int n;
    vector<ll> tree;

    SegmentTree(int sz) {
        n = sz;
        tree.assign(4 * n + 5, 0);
    }

    void update(int node, int start, int end, int idx, ll val) {
        if (start == end) {
            tree[node] = (tree[node] + val) % MOD;
            return;
        }

        int mid = (start + end) / 2;

        if (idx <= mid)
            update(2 * node, start, mid, idx, val);
        else
            update(2 * node + 1, mid + 1, end, idx, val);

        tree[node] = (tree[2 * node] + tree[2 * node + 1]) % MOD;
    }

    ll query(int node, int start, int end, int l, int r) {
        if (r < start || end < l)
            return 0;

        if (l <= start && end <= r)
            return tree[node];

        int mid = (start + end) / 2;

        return (query(2 * node, start, mid, l, r) +
                query(2 * node + 1, mid + 1, end, l, r)) % MOD;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> comp = a;
    sort(comp.begin(), comp.end());
    comp.erase(unique(comp.begin(), comp.end()), comp.end());

    SegmentTree st(comp.size());

    for (int x : a) {

        int idx = lower_bound(comp.begin(), comp.end(), x) - comp.begin() + 1;

        ll ways = 0;

        if (idx > 1)
            ways = st.query(1, 1, comp.size(), 1, idx - 1);

        ll dp = (ways + 1) % MOD;

        st.update(1, 1, comp.size(), idx, dp);
    }

    cout << st.query(1, 1, comp.size(), 1, comp.size()) << '\n';
}