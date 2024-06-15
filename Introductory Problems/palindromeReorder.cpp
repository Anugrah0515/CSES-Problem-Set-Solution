#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    string s;
    cin>>s;
    map<char, int> mp;
    for(auto it: s) 
        mp[it]++;
    int oddCount = 0;
    string ans = "";
    char ch = '.';
    for(auto it: mp) {
        if (it.second % 2) {
            oddCount++;
            if (oddCount > 1) {
                break;
            } else {
                ch = it.first;
                int temp = it.second / 2;
                while(temp--)
                    ans += it.first;
            }
        } else {
            int temp = it.second / 2;
            while(temp--)
                ans += it.first;
        }
    }
    if (oddCount > 1) {
        cout<<"NO SOLUTION"<<endl;
    } else {
        string tmp = ans;
        reverse(tmp.begin(), tmp.end());
        if (oddCount) {
            ans += ch;
        }
        ans += tmp;
        cout<<ans<<endl;
    }
    return 0;
}