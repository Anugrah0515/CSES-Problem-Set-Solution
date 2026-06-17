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
    vector<pair<ll, ll>> a(n);
    for(int i=0;i<n;i++) {
        cin >> a[i].first;
        a[i].second = i + 1;
    }

    sortFcn(a);
    vector<ll> ans(3);

    for(int k=0;k<n;k++) {
        int i = 0, j = n - 1;
        ll target = x - a[k].first;
        bool flg = 0;
        while(i < j) {
            if (i == k) {
                i++;
                continue;
            }
            if (j == k) {
                j--;
                continue;
            }
            ll sum = a[i].first + a[j].first;
            if (sum == target) {
                flg = 1;
                ans = {a[i].second, a[j].second, a[k].second};
                break;
            } else if (sum < target) {
                i++;
            } else {
                j--;
            }
        }
        if(flg) {
            output(ans)
            return;
        }
    }
    impossible
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}