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
#define impossible cout << "IMPOSSIBLE" << endl;

void solve() {
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    input(a, n);

    int j = 0, cnt = 0;
    ll sum = 0;
    for(int i=0;i<n;i++) {
        while(i > j && sum > x) {
            sum -= a[j];
            j++;
        }
        if (sum == x) 
            cnt++;
        sum += a[i];
    }
    while(j < n && sum > x) {
        sum -= a[j];
        j++;
    }
    if (sum == x) 
        cnt++;
    cout << cnt << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}