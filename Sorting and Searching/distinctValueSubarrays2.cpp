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
#define impossible cout << "IMPOSSIBLE" << endl;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    input(a, n);
    long long ans = 0;
    int l = 0;
    unordered_map<int,int> freq;

    for(int r = 0; r < n; r++) {
        freq[a[r]]++;

        while(freq.size() > k) {
            freq[a[l]]--;
            if(freq[a[l]] == 0)
                freq.erase(a[l]);
            l++;
        }

        ans += (r - l + 1);
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}