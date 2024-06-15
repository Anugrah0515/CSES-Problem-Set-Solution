#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll mod = 1e9 + 7;

ll solve(int i, ll sum1, ll sum2, vector<ll>& a, int n) {
    if (i == n)
        return abs(sum1 - sum2);
    return min(solve(i+1, sum1 + a[i], sum2, a, n), solve(i+1, sum1, sum2 + a[i], a, n));
}

int main() {
    int n;
    cin>>n;
    vector<ll> a(n);
    for(auto &it: a)
        cin>>it;
    cout<<solve(0, 0, 0, a, n)<<endl;
    return 0;
}