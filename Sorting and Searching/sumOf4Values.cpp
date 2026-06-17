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
    int n;
    ll x;
    cin >> n >> x;

    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    map<ll, pair<int, int>> mp;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ll need = x - a[i] - a[j];

            if (mp.count(need)) {
                auto [p, q] = mp[need];

                if (p != i && p != j && q != i && q != j) {
                    cout << p + 1 << " "
                         << q + 1 << " "
                         << i + 1 << " "
                         << j + 1 << "\n";
                    return;
                }
            }
        }

        for (int j = 0; j < i; j++) {
            mp[a[i] + a[j]] = {j, i};
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