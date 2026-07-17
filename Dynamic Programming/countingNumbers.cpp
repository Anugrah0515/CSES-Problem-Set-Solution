#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    ll a, b;
    cin >> a >> b;

    auto count = [&](ll x) -> ll {
        if (x < 0) return 0;

        string s = to_string(x);
        int n = s.size();

        ll dp[20][2][11][2];
        memset(dp, -1, sizeof(dp));

        function<ll(int, int, int, int)> f = [&](int i, int tight, int last, int started) -> ll {

            if (i == n)
                return 1;

            if (dp[i][tight][last][started] != -1)
                return dp[i][tight][last][started];

            int limit = tight ? (s[i] - '0') : 9;

            ll ans = 0;

            for (int d = 0; d <= limit; d++) {

                int newTight = tight && (d == limit);

                if (!started && d == 0) {
                    ans += f(i + 1, newTight, 10, 0);
                }
                else {

                    if (started && d == last)
                        continue;

                    ans += f(i + 1, newTight, d, 1);
                }
            }

            return dp[i][tight][last][started] = ans;
        };

        return f(0, 1, 10, 0);
    };

    cout << count(b) - count(a - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}