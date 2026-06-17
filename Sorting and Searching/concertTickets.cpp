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
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    input(a, n)
    input(b, m)

    multiset<int> s;
    // s = a;
    for(auto it: a)
        s.insert(it);

    // sortFcn(a)
    for(auto t: b) {
        auto it = s.upper_bound(t);
        if(it != s.begin()) {
            it--;
            cout << *it;
            s.erase(it);
        } else {
            cout << -1;
        }
        newline
    }
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