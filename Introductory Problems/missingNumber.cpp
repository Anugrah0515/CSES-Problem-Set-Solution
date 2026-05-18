#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define input(a, n) for(int i = 0; i < n; i++) cin >> a[i];
#define output(a, n) for(int i = 0; i < n; i++) cout << a[i] << " "; cout << "\n";
#define sort(a) sort(a.begin(), a.end());
#define reverse(a) reverse(a.begin(), a.end());

void solve() {
    int n;
    cin >> n;
    vector<int> a(n-1);
    input(a, n-1);

    int x = 0;
    for(auto it: a)
        x ^= it;
    for(int i=1;i<=n;i++) 
        x ^= i;
    cout << x << endl;
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