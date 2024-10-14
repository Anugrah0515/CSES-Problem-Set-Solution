#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n;
    cin>>n;
    vector<pair<int, int>> a;
    for(int i=0;i<n;i++) {
        int start, end;
        cin>>start>>end;
        a.push_back({end, start});
    }
    int ans = 0, last = 0;
    sort(a.begin(), a.end());
    for(auto it: a) {
        if (it.second >= last) {
            ans++;
            last = it.first;
        }
    }
    cout<<ans<<endl;
    return 0;
}