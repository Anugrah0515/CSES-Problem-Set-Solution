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
 
void solve() {
    int n;
    cin >> n;
    vector<array<int, 3>> ranges(n);

    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        ranges[i] = {l, r, i};
    }

    sort(ranges.begin(), ranges.end(), [](auto &a, auto &b) {
        if (a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    });

    vector<int> contains(n, 0), contained(n, 0);

    int maxR = 0;
    for (int i = 0; i < n; i++) {
        int r = ranges[i][1];
        int idx = ranges[i][2];

        if (maxR >= r) contained[idx] = 1;
        maxR = max(maxR, r);
    }

    int minR = INT_MAX;
    for (int i = n - 1; i >= 0; i--) {
        int r = ranges[i][1];
        int idx = ranges[i][2];

        if (minR <= r) contains[idx] = 1;
        minR = min(minR, r);
    }
    output(contains)
    newline
    output(contained)
    newline
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