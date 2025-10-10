#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<vector<int>> adj;
vector<vector<int>> dp;


void dfs(int u, int p) {
    dp[u][0] = 0;
    dp[u][1] = 0;
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        dp[u][0] += max(dp[v][0], dp[v][1]);
    }
    for (int v : adj[u]) {
        if (v == p) continue;
        int match = 1 + dp[v][0] + (dp[u][0] - max(dp[v][0], dp[v][1]));
        dp[u][1] = max(dp[u][1], match);
    }
}

int main() {
    int n;
    cin >> n;
    adj.assign(n + 1, vector<int>());
    dp.assign(n + 1, vector<int>(2, 0));
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    cout << max(dp[1][0], dp[1][1]) << endl;
    return 0;
}