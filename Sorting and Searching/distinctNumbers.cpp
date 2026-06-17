#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define input(a, n) for(int i = 0; i < n; i++) cin >> a[i];
#define output(a) for(auto it: a) cout << it << " ";
#define sort(a) sort(a.begin(), a.end());
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define newline cout << endl;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &it: a)
        cin >> it;

    int count = 1;
    sort(a);
    for(int i=0;i<n-1;i++)
        if (a[i] != a[i + 1])
            count++;
    cout << count;
    newline
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;

    while(t--) {
        solve();
    }

    return 0;
}