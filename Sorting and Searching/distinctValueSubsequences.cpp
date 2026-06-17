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
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define newline cout << endl;


long long MOD = 1e9 + 7;
 
void solve() {
    int n;
    cin >> n;

    unordered_map<int, int> freq;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        freq[x]++;
    }

    ll ans = 1;

    for (auto &[x, f] : freq) {
        ans = ans * (f + 1) % MOD;
    }

    ans = (ans - 1 + MOD) % MOD; 

    cout << ans << '\n';
}
 
int main()
{
 
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int t = 1;
    // cin >> t;
 
    while (t--)
    {
        solve();
    }
 
    return 0;
}