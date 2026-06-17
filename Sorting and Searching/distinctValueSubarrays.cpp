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
 
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    input(a, n);
 
    set<int> st;
    long long l = 0, r = 0, cnt = 0;
    while (r < n) {
        if (st.find(a[r]) != st.end()) {
            // cnt += (r - l + 1);
            while (l < r && a[l] != a[r]) {
                st.erase(a[l]);
                l++;
            }
            st.erase(a[l]);
            l++;
        }
        st.insert(a[r]);
        cnt += (r - l + 1);
        r++;
    }
 
    cout << cnt;
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