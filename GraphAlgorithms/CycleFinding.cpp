#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 1e18
 
int main() {
    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, ll>> edges(m);
    for(int i = 0; i < m; i++) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        edges[i] = {a, b, c};
    }
    
    vector<ll> dist(n + 1, INF);
    dist[1] = 0;
    vector<int> parent(n + 1, -1);
    int flag = -1;
    
    for(int i = 0; i < n; i++) {
        flag = -1;
        for(auto it : edges) {
            int a, b;
            ll c;
            tie(a, b, c) = it;
            if (dist[a] + c < dist[b]) {
                dist[b] = dist[a] + c;
                parent[b] = a;
                flag = b;
            }
        }
    }
    
    if (flag == -1) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        for (int i = 0; i < n; i++) {
            flag = parent[flag];
        }
 
        vector<int> cycle;
        for (int v = flag; ; v = parent[v]) {
            cycle.push_back(v);
            if (v == flag && cycle.size() > 1) break;
        }
        reverse(cycle.begin(), cycle.end());
 
        for (int v : cycle) {
            cout << v << " ";
        }
        cout << endl;
    }
 
    return 0;
}