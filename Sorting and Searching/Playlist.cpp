#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto &it: a)
        cin>>it;    
    int start = 0, ans = 0;
    map<int, bool> mp;
    for(int end = 0;end < n;end++) {
        if (mp[a[end]]) {
            ans = max(ans, end - start);
            while(mp[a[end]]) {
                mp[a[start]] = false;
                start++;
            }
        }
        mp[a[end]] = true;
    }
    ans = max(ans, n - start);
    cout<<ans<<endl;
    return 0;
}