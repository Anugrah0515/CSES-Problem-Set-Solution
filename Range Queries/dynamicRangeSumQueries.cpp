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
    vector<ll> seg;
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

    void update(int l, int r, int idx, int pos, int val) {
        if (l == r) {
            seg[idx] = val;
            return;
        }
        int mid = l + (r - l) / 2;
        if (pos <= mid) update(l, mid, 2 * idx, pos, val);
        else update(mid + 1, r, 2 * idx + 1, pos, val);
        seg[idx] = seg[2 * idx] + seg[2 * idx + 1];
    }
    
    ll query(int l, int r, int idx, int ql, int qr) {
        if (l > qr || r < ql) return 0;
        if (ql <= l && r <= qr) return seg[idx];
        int mid = l + (r - l) / 2;
        return query(l, mid, 2 * idx, ql, qr) + query(mid + 1, r, 2 * idx + 1, ql, qr);
    }
public:
    SegmentTree(vector<int> arr) {
        n = arr.size();
        seg.resize(4 * n + 1);
        build(0, n - 1, 1, arr);
    }

    void update(int pos, int val) {
        update(0, n - 1, 1, pos, val);
    }

    ll query(int ql, int qr) {
        return query(0, n - 1, 1, ql, qr);
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    input(a, n);
    SegmentTree st(a);
    while(q--) {
        int query, a, b;
        cin >> query >> a >> b;
        if (query == 1) 
            st.update(a - 1, b);
        else 
            cout << st.query(a - 1, b - 1) << endl;
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