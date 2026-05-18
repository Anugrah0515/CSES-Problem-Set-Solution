#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define input(a, n) for(int i = 0; i < n; i++) cin >> a[i];
#define output(a, n) for(int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define sort(a) sort(a.begin(), a.end());
#define reverse(a) reverse(a.begin(), a.end());

bool isValid(int i, int j, vector<string>& a) {
    for(int k=0;k<8;k++) {
        if (a[i][k] == 'Q' || a[k][j] == 'Q') 
            return false;
    }

    for(int k=0;k<8;k++) {
        if ((i + k < 8 && j + k < 8 && a[i + k][j + k] == 'Q') || 
        (i + k < 8 && j - k >= 0 && a[i + k][j - k] == 'Q') || 
        (i - k >= 0 && j - k >= 0 && a[i - k][j - k] == 'Q') || 
        (i - k >= 0 && j + k < 8 && a[i - k][j + k] == 'Q'))
            return false;
    }
    return true;
}

int f(int i, int n, vector<string>& a) {
    if (i == 8) return 1;
    int ans = 0;
    for(int j=0;j<8;j++) {
        if (a[i][j] != '*' && isValid(i, j, a)) {
            a[i][j] = 'Q';
            ans += f(i + 1, n - 1, a);
            a[i][j] = '.';
        }
    }
    return ans;
}

void solve() {
    vector<string> a(8);
    for(auto &it: a)
        cin >> it;

    cout << f(0, 8, a) << endl;
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