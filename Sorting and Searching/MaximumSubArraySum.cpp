#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n;
    cin>>n;
    vector<ll> a(n);
    ll sum = 0, maxSum = -1e9-1;
    for(auto &it: a) {
        cin>>it;
        maxSum = max(maxSum, it);
    }
    for(auto it: a) {
        sum += it;
        maxSum = max(maxSum, sum);
        if (sum < 0) sum = 0;
    }
    cout<<maxSum<<endl;
    return 0;
}