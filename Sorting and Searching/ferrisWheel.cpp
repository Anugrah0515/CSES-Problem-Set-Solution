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
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    input(a, n);

    sortFcn(a);
    int count = 0, i = 0, j = n - 1;
    while(i <= j) {
        if (a[i] + a[j] <= x) 
            i++;
        j--;
        count++;
    }
    cout << count;
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