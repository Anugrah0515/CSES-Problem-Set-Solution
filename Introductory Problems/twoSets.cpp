#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define input(a, n) for(int i = 0; i < n; i++) cin >> a[i];
#define output(a, n) for(int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define sort(a) sort(a.begin(), a.end());
#define reverse(a) reverse(a.begin(), a.end());

void solve() {
    ll n;
    cin >> n;
    
    ll sum = n * (n + 1) / 2;
    if (sum % 2) {
        cout << "NO" << endl;
        return;
    } 
    sum /= 2;
    cout << "YES" << endl;
    vector<int> a, b;
    ll last = n;
    while(sum > 0) {
        if (sum >= last) {
            a.pb(last);
            sum -= last;
        }
        last--;
    }
    sort(a);
    for(int i = 1; i <= n; i++) {
        if (!binary_search(a.begin(), a.end(), i)) b.pb(i);
    }
    cout << a.size() << endl;
    output(a, a.size());
    cout << b.size() << endl;
    output(b, b.size());

    return;
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