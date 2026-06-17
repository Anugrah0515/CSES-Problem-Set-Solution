#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define input(a, n) for(int i = 0; i < n; i++) cin >> a[i];
#define output(a) for(auto it: a) cout << it << " ";
#define sortFcn(a) sort(a.begin(), a.end());
#define lowerBound(a, x) lower_bound(a.begin(), a.end(), x)
#define upperBound(a, x) upper_bound(a.begin(), a.end(), x)
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define newline cout << endl;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    input(a, n);

    int ans = 0, i = 0, j = 0;
    set<int> s;
    while(j < n) {
        if (s.find(a[j]) != s.end()) {
            while(a[i] != a[j])
                s.erase(a[i]), i++;
            if (i != j) i++;
            s.erase(a[j]);
        }
        s.insert(a[j]);
        ans = max(ans, j - i + 1);
        j++;        
    }
    cout << ans << endl;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}