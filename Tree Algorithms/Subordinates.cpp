#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n;
    cin>>n;
    vector<vector<int>> adj(n+1);
    for(int i=2;i<=n;i++) {
        int x;
        cin>>x;
        adj[x].push_back(i);
    }
    vector<int> ans(n);
    function<int(int)> dfs = [&](int u) {
        int cnt = 0;
        for(auto &v: adj[u]) {
            cnt += dfs(v);
        }
        ans[u - 1] = cnt;
        return cnt + 1;
    };
    dfs(1);
    for(auto it: ans) {
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}