#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define input(a, n) for (int i = 0; i < n; i++) cin >> a[i];
#define output(a) for (auto it : a) cout << it << " ";
#define sortFcn(a) sort(a.begin(), a.end());
#define rev(a) reverse(a.begin(), a.end());
#define lowerBound(a, x) lower_bound(a.begin(), a.end(), x)
#define upperBound(a, x) upper_bound(a.begin(), a.end(), x)

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    input(a, n);

    ll sum = 0, max = *max_element(a.begin(), a.end());
    for(auto it: a)
        sum += it;
    if (sum > 2 * max) 
        cout << sum << endl;
    else 
        cout << 2 * max << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) 
        solve();

    return 0;
}