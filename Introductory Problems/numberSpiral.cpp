#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int t;
    cin>>t;
    while(t--) {
        ll x, y;
        cin>>x>>y;
        ll m = max(x, y) - 1;
        if (m % 2) {
            if (x > y) cout<<(m + 1) * (m + 1) - y + 1;
            else cout<<m * m + x;
        } else {
            if (x > y) cout<<m * m + y;
            else cout<<(m + 1) * (m + 1) - x + 1;
        }
        cout<<endl;
    }
    return 0;
}