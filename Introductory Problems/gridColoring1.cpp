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
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for(auto &it: grid)
        cin >> it;

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++) {
            if ((i + j) % 2 == 0) {
                if (grid[i][j] == 'A') grid[i][j] = 'B';
                else grid[i][j] = 'A';
            } else {
                if (grid[i][j] == 'C') grid[i][j] = 'D';
                else grid[i][j] = 'C';
            }
        }
    
    for(auto it: grid)
        cout << it << endl;
    newline
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}