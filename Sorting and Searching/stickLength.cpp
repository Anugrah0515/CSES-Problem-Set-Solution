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

ll cost(vector<ll> a, int k) {
    ll cst = 0;
    for(auto it: a) 
        cst += abs(it - k);

    return cst;
}

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    input(a, n);
    sortFcn(a)

    cout << cost(a, a[n / 2]);
    newline
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