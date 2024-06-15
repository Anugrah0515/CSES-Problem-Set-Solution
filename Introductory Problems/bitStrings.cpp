#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll mod = 1e9 + 7;

int main() {
    ll n;
    cin>>n;
    ll ans = 1;
    for(int i=1;i<=n;i++) {
        ans = (ans * 2) % mod;
    }
    cout<<ans<<endl;
    return 0;
}