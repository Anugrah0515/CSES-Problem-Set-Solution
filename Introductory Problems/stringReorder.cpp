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

bool possible(vector<int>& freq, int rem) {
    int mx = 0;
    
    for(int i = 0; i < 26; i++) {
        mx = max(mx, freq[i]);
    }

    return mx <= (rem + 1) / 2;
}

void solve() {
    string s;
    cin >> s;

    int n = s.size();

    vector<int> freq(26, 0);

    for(char c : s) {
        freq[c - 'A']++;
    }

    if(!possible(freq, n)) {
        cout << -1;
        return;
    }

    string ans = "";

    for(int pos = 0; pos < n; pos++) {

        for(int ch = 0; ch < 26; ch++) {

            if(freq[ch] == 0) continue;

            char c = 'A' + ch;

            if(!ans.empty() && ans.back() == c) continue;

            freq[ch]--;

            int rem = n - pos - 1;

            if(possible(freq, rem)) {
                ans += c;
                break;
            }

            freq[ch]++;
        }
    }

    cout << ans;    
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