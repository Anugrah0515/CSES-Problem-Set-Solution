#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n;
    cin>>n;
    vector<ll> a(n);
    for(auto &it: a)
        cin>>it;
    sort(a.begin(), a.end());
    if (a[0] != 1) {
        cout<<1<<endl;
        return 0;
    }
    ll ans = 1;
    for(int i=0;i<n && a[i] <= ans;i++)
        ans += a[i];
    cout<<ans<<endl;
    return 0;
}