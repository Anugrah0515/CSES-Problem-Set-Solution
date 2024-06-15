#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll mod = 1e9 + 7;

int main() {
    int t;
    cin>>t;
    while(t--) {
        ll a, b;
        cin>>a>>b;
        if (max(a, b) > 2 * min(a, b) || (a + b) % 3) cout<<"NO"<<endl; 
        else cout<<"YES"<<endl;
    }
    return 0;
}