#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll mod = 1e9 + 7;

vector<pair<int, int>> steps;

void solve(int disks, int from, int to, int aux) {
    if (disks == 0)
        return;
    solve(disks - 1, from, aux, to);
    steps.push_back({from, to});
    solve(disks - 1, aux, to, from);
}

int main() {
    int n;
    cin>>n;
    solve(n, 1, 3, 2);
    cout<<steps.size()<<endl;
    for(auto it: steps) {
        cout<<it.first<<" "<<it.second<<endl;
    }
    return 0;
}