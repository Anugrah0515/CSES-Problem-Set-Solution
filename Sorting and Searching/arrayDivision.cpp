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
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    input(a, n);

    ll low = *max_element(a.begin(), a.end()), high = 0;
    for(auto it: a) 
        high += it;
    while(low < high) {
        ll mid = low + (high - low) / 2;
        int sub = 1, flag = 0;
        ll sum = 0;
        for(auto it: a) {
            if (sum + it > mid) {
                sum = 0;
                sub++;
            } 
            sum += it;
        }
        if (sub <= k) {
            flag = 1;
        }
        if (flag) high = mid;
        else low = mid + 1;
    }
    cout << low << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}