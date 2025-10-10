#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<vector<int>> adj(n + 1);
    for(int i=1;i<n;i++) {
        int x;
        cin >> x;
        adj[x].push_back(i + 1);
    }
    vector<vector<int>> up(n + 1, vector<int>(20, -1));
    function<void(int, int)> f = [&](int node, int p) {
        up[node][0] = p;
        for(int i=1;i<20;i++) {
            if (up[node][i - 1] != -1) {
                up[node][i] = up[up[node][i - 1]][i - 1];
            } else {
                up[node][i] = -1;
            }
        }
        for(auto it: adj[node]) {
            if (it != p)
                f(it, node);
        }
    };
    f(1, -1);
    while (q--) {
        int node, k;
        cin >> node >> k;
        for(int i=0;i<20;i++) {
            if (k & (1 << i)) {
                node = up[node][i];
                if (node == -1) 
                    break;
            }
        }
        cout<<node<<endl;
    }
    return 0;
}