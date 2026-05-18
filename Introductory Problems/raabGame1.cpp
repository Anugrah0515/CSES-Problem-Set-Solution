#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define input(a, n) for(int i = 0; i < n; i++) cin >> a[i];
#define sort(a) sort(a.begin(), a.end());
#define reverse(a) reverse(a.begin(), a.end());
#define output(a) for(auto it: a) cout << it << " ";
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define newline cout << endl;

void rotateArray(vector<int>& a, ll k, ll n) {
    while(k--) {
        int tmp = a[0];
        for(int i=0;i<n-1;i++)
            a[i] = a[i + 1];
        a[n - 1] = tmp;
    }
    return;
}

void solve() {
    ll n, a, b;
    cin >> n >> a >> b;

    if (a + b > n) {
        no
        return;
    }

    ll draws = n - a - b;
    ll i = n;
    vector<int> player;
    while(draws--) {
        player.pb(i);
        // player2.pb(i);
        i--;
    }
    vector<int> p1, p2;
    for(int j=1;j<=i;j++) 
        p1.pb(j);
    p2 = p1;
    rotateArray(p1, i - a, i);
    for(auto it: player)
        p1.pb(it), p2.pb(it);
    for(int k=0;k<n;k++) {
        if (p1[k] > p2[k]) a--;
        else if (p1[k] < p2[k]) b--;
    }
    if (a == 0 && b == 0) {
        yes
        output(p1)
        newline
        output(p2)
        newline
    } else {
        no
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}