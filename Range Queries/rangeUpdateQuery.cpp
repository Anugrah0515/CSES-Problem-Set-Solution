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

class SegmentTree {
private:
    vector<ll> seg, lazy;
    int n;
    void build(int l, int r, int idx, vector<int>& arr) {
        if (l == r) {
            seg[idx] = 1LL * arr[l];
            return;
        }
        int mid = l + (r - l) / 2;
        build(l, mid, 2 * idx, arr);
        build(mid + 1, r, 2 * idx + 1, arr);
        seg[idx] = seg[2 * idx] + seg[2 * idx + 1];
    }

    void push(int node, int l, int r) {
        if (lazy[node] == 0) return;

        seg[node] += lazy[node] * (r - l + 1);

        if (l != r) {
            lazy[2 * node] += lazy[node];
            lazy[2 * node + 1] += lazy[node];
        }

        lazy[node] = 0;
    }

    void rangeUpdate(int l, int r, int node, int ql, int qr, ll val) {
        push(node, l, r);
        if (r < ql || l > qr)
            return;
        if (ql <= l && r <= qr) {
            lazy[node] += val;
            push(node, l, r);
            return;
        }
        int mid = (l + r) / 2;
        rangeUpdate(l, mid, 2 * node, ql, qr, val);
        rangeUpdate(mid + 1, r, 2 * node + 1, ql, qr, val);
        seg[node] = seg[2 * node] + seg[2 * node + 1];
    }

    void update(int l, int r, int idx, int pos, int val) {
        push(idx, l, r);
        if (l == r) {
            seg[idx] = val;
            return;
        }
        int mid = l + (r - l) / 2;
        if (pos <= mid) update(l, mid, 2 * idx, pos, val);
        else update(mid + 1, r, 2 * idx + 1, pos, val);
        seg[idx] = seg[2 * idx] + seg[2 * idx + 1];
    }
    
    ll sum(int l, int r, int idx, int ql, int qr) {
        if (l > qr || r < ql) return 0;
        push(idx, l, r);
        if (ql <= l && r <= qr) return seg[idx];
        int mid = l + (r - l) / 2;
        return sum(l, mid, 2 * idx, ql, qr) + sum(mid + 1, r, 2 * idx + 1, ql, qr);
    }
public:
    SegmentTree(vector<int> arr) {
        n = arr.size();
        seg.resize(4 * n + 1);
        lazy.resize(4 * n + 1);
        build(0, n - 1, 1, arr);
    }

    void update(int pos, int val) {
        update(0, n - 1, 1, pos, val);
    }

    void rangeUpdate(int ql, int qr, ll val) {
        rangeUpdate(0, n - 1, 1, ql, qr, val);
    }

    ll sum(int ql, int qr) {
        return sum(0, n - 1, 1, ql, qr);
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    input(a, n);
    SegmentTree st(a);
    while(q--) {
        int query;
        cin >> query;
        if (query == 1) {
            int a, b, u;
            cin >> a >> b >> u;
            st.rangeUpdate(a - 1, b - 1, u);
        } else {
            int pos;
            cin >> pos;
            cout << st.sum(pos - 1, pos - 1) << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;    while (t--) solve();

    return 0;
}