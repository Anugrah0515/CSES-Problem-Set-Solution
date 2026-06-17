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

bool check(vector<ll>& a, ll t, ll time) {
    ll cnt = 0;
    for(auto it: a) {
        cnt += time / it;
        if (cnt >= t) return true;
    }
    return false;
}

void solve() {
    ll n, t;
    cin >> n >> t;
    vector<ll> a(n);
    input(a, n);

    sortFcn(a)
    ll low = 1, high = 1e18;
    while(low < high) {
        ll mid = low + (high - low) / 2;
        if (check(a, t, mid)) high = mid;
        else low = mid + 1;
    }
    cout << low << endl;
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