#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll n;
    cin>>n;
    ll sum = 0, a;
    for(int i=0;i<n-1;i++) {
        cin>>a;
        sum += a;
    }
    cout<<(n * (n + 1)) / 2 - sum<<endl;
    return 0;
}