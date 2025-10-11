#include <bits/stdc++.h>
using namespace std;
#define ll long long

class DSU {
public:
    vector<int> parent, size;
    DSU(int n) {
        for(int i=0;i<=n;i++) {
            parent.push_back(i);
            size.push_back(1);
        }
    }

    int findPar(int node) {
        if (node == parent[node]) return node;
        return parent[node] = findPar(parent[node]);
    }

    void unite(int u, int v) {
        int x = findPar(u), y = findPar(v);
        if (x == y) return;
        size[x] += size[y];
        parent[y] = x;
        return;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    DSU ds(n + 1);
    while(m--) {
        int u, v;
        cin >> u >> v;
        ds.unite(u, v);
    }
    vector<int> ans;
    for(int i=1;i<=n;i++) {
        if (i == ds.parent[i]) 
            ans.push_back(i);
    }
    cout << ans.size() - 1 << endl;
    for(int i=1;i<ans.size();i++) {
        cout << ans[i - 1] << " " << ans[i] << endl;
    }
    return 0;
}