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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    input(a, n)
    input(b, m)

    sortFcn(a)
    sortFcn(b)

    // output(a)
    // newline
    // output(b)
    // newline

    int count = 0, i = 0;
    for(int j=0;j<m;j++) {
        while (i < n) {
            if (a[i] <= b[j] + k && a[i] >= b[j] - k) {
                count++;
                i++;
                break;
            }
            if (a[i] > b[j] + k) {
                break;
            }
            i++;
        }
    }

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