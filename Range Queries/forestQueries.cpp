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
    int n, m;

    // tree[rowNode][colNode]
    vector<vector<ll>> tree;

    // Build column segment tree for a particular row-segment node
    void buildY(
        int nodeX,
        int lx, int rx,
        int nodeY,
        int ly, int ry,
        vector<vector<int>>& a
    ) {
        if (ly == ry) {
            if (lx == rx) {
                // leaf row + leaf column
                tree[nodeX][nodeY] = a[lx][ly];
            } else {
                // combine the two row children
                tree[nodeX][nodeY] =
                    tree[2 * nodeX][nodeY] +
                    tree[2 * nodeX + 1][nodeY];
            }
            return;
        }

        int midY = (ly + ry) / 2;

        buildY(nodeX, lx, rx, 2 * nodeY, ly, midY, a);
        buildY(nodeX, lx, rx, 2 * nodeY + 1, midY + 1, ry, a);

        tree[nodeX][nodeY] =
            tree[nodeX][2 * nodeY] +
            tree[nodeX][2 * nodeY + 1];
    }

    // Build segment tree over rows
    void buildX(
        int nodeX,
        int lx, int rx,
        vector<vector<int>>& a
    ) {
        if (lx != rx) {
            int midX = (lx + rx) / 2;

            buildX(2 * nodeX, lx, midX, a);
            buildX(2 * nodeX + 1, midX + 1, rx, a);
        }

        // Every row node has its own column segment tree
        buildY(nodeX, lx, rx, 1, 0, m - 1, a);
    }

    // Query columns for ONE selected row node
    ll queryY(
        int nodeX,
        int nodeY,
        int ly, int ry,
        int qly, int qry
    ) {
        // no overlap
        if (ry < qly || ly > qry)
            return 0;

        // complete overlap
        if (qly <= ly && ry <= qry)
            return tree[nodeX][nodeY];

        int midY = (ly + ry) / 2;

        return queryY(nodeX, 2 * nodeY, ly, midY, qly, qry)
             + queryY(nodeX, 2 * nodeY + 1, midY + 1, ry, qly, qry);
    }

    // Query rows
    ll queryX(
        int nodeX,
        int lx, int rx,
        int qlx, int qrx,
        int qly, int qry
    ) {
        // no row overlap
        if (rx < qlx || lx > qrx)
            return 0;

        // full row overlap
        if (qlx <= lx && rx <= qrx) {
            // Query columns inside this row segment
            return queryY(nodeX, 1, 0, m - 1, qly, qry);
        }

        int midX = (lx + rx) / 2;

        return queryX(
                   2 * nodeX,
                   lx, midX,
                   qlx, qrx,
                   qly, qry
               )
             + queryX(
                   2 * nodeX + 1,
                   midX + 1, rx,
                   qlx, qrx,
                   qly, qry
               );
    }

public:
    SegmentTree(vector<vector<int>>& a) {
        n = a.size();
        m = a[0].size();

        tree.resize(4 * n, vector<ll>(4 * m, 0));

        buildX(1, 0, n - 1, a);
    }

    ll query(
        int r1, int c1,
        int r2, int c2
    ) {
        return queryX(
            1,
            0, n - 1,
            r1, r2,
            c1, c2
        );
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> a(n, vector<int>(n));
    for(int i=0;i<n;i++) 
        for(int j=0;j<n;j++) {
            char ch;
            cin >> ch;
            a[i][j] = (ch == '*' ? 1 : 0);
        }

    SegmentTree forest(a);    
    while(q--) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        cout << forest.query(r1 - 1, c1 - 1, r2 - 1, c2 - 1) << endl;
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