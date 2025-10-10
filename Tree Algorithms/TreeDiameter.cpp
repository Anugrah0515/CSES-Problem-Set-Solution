#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for(int i=0;i<n-1;i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    function <vector<int>(int)> f = [&](int node) {
        vector<int> dist(n + 1, 1e9);
        dist[node] = 0;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, node, 0});
        while (!pq.empty())
        {
            auto it = pq.top();
            int d = it[0], x = it[1], p = it[2];
            pq.pop();
            for(auto it: adj[x]) {
                if (it == p) continue;
                if (dist[it] > d + 1) {
                    dist[it] = d + 1;
                    pq.push({d + 1, it, x});
                }
            }
        }
        for(auto &it: dist)
            if (it == 1e9)
                it = -1;
        return dist;
    };

    vector<int> dist = f(1);
    int lastNode = max_element(dist.begin(), dist.end()) - dist.begin();
    dist = f(lastNode);
    cout<<*max_element(dist.begin(), dist.end())<<endl;
    return 0;
}