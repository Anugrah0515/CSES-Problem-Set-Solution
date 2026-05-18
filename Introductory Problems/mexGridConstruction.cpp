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

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> mex(n, vector<int>(n, 0));
    
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            vector<int> tmp;
            for(int k=0;k<i;k++) tmp.pb(mex[k][j]);
            for(int k=0;k<j;k++) tmp.pb(mex[i][k]);
            sort(tmp);
            int k = 0;
            for(auto it: tmp) 
                if (k == it) k++;
                else break;
            mex[i][j] = k;
        }
    }

    for(auto it: mex) {
        output(it)
        cout << endl;
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