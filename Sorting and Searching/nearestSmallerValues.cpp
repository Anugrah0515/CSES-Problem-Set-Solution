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
    cin >> n;
    vector<ll> a(n);
    input(a, n);

    stack<pair<ll, int>> st;
    vector<int> ans;
    ans.pb(0);
    st.push({a[0], 1});
    for(int i=1;i<n;i++) {
        while(!st.empty() && st.top().first >= a[i])
            st.pop();
        if (!st.empty()) 
            ans.pb(st.top().second);
        else 
            ans.pb(0);
        st.push({a[i], i + 1});
    }
    output(ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}