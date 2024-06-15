#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll mod = 1e9 + 7;

ll pow10(int length) {
    ll ans = 1;
    for(int i=0;i<length;i++)
        ans *= 10;
    return ans;
}

int digitCalculator(ll n) {
    if (n < 9) return n+1;
    int length = 1;
    while(n > 9 * length * pow10(length - 1)) {
        n -= 9 * length * pow10(length - 1);
        length++;
    }
    string s = to_string(pow10(length - 1) + n / length);
    return (int)(s[n % length] - '0');
}

int main() {
    int q;
    cin>>q;
    while(q--) {
        ll k;
        cin>>k;
        cout<<digitCalculator(k - 1)<<endl;
    }
    return 0;
}