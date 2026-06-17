#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define input(a, n)             \
    for (int i = 0; i < n; i++) \
        cin >> a[i];
#define output(a)     \
    for (auto it : a) \
        cout << it << " ";
#define sortFcn(a) sort(a.begin(), a.end());
#define rev(a) reverse(a.begin(), a.end());
#define lowerBound(a, x) lower_bound(a.begin(), a.end(), x)
#define upperBound(a, x) upper_bound(a.begin(), a.end(), x)
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define newline cout << endl;

void solve() {
    int x, n;
    cin >> x >> n;

    set<int> pos;
    multiset<int> len;

    pos.insert(0);
    pos.insert(x);

    len.insert(x);

    while (n--) {
        int p;
        cin >> p;

        auto itR = pos.upper_bound(p);
        auto itL = prev(itR);

        int l = *itL;
        int r = *itR;

        len.erase(len.find(r - l));

        len.insert(p - l);
        len.insert(r - p);

        pos.insert(p);

        cout << *len.rbegin() << " ";
    }
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