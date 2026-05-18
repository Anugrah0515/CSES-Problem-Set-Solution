#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define input(a, n) for(int i = 0; i < n; i++) cin >> a[i];
#define output(a, n) for(int i = 0; i < n; i++) cout << a[i] << " "; cout << "\n";
#define sort(a) sort(a.begin(), a.end());
#define reverse(a) reverse(a.begin(), a.end());

vector<string> graycode(int n) {
    if (n == 1) {
        return {"0", "1"};
    }
    vector<string> prevGrayCode = graycode(n - 1);
    vector<string> reversedPrevGrayCode = prevGrayCode;
    reverse(reversedPrevGrayCode);
    int prevSize = prevGrayCode.size();
    int index = 0;
    while (index < prevSize) {
        string appendedZero = "0" + prevGrayCode[index];
        prevGrayCode[index] = "1" + reversedPrevGrayCode[index];
        prevGrayCode.push_back(appendedZero);
        index++;
    }
    return prevGrayCode;
}

void solve() {
    int n;
    cin >> n;
    vector<string> ans = graycode(n);
    for (auto str: ans) {
        cout << str << endl;
    }    
    return;
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