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
#define impossible cout << "IMPOSSIBLE" << endl;
#define newline cout << endl;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> a(n);
    for(auto i = 0;i<n;i++) {
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    
    sortFcn(a)
    int i = 0, j = n - 1;
    while(i < j) {
        int sum = a[i].first + a[j].first;
        if (sum == x) {
            cout << a[i].second << " " << a[j].second;
            newline
            break;
        } else if (sum < x){
            i++;
        } else {
            j--;
        }
    }
    if (i >= j) {
        impossible
    }
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