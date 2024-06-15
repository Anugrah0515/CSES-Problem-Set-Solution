#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll mod = 1e9 + 7;

vector<string> ans;

void solve(int ind, int n, string s, vector<int>& freq) {
    if (ind == n) {
        ans.push_back(s);
        return;
    }

    for(int i=0;i<26;i++) {
        if (freq[i] != 0) {
            s.push_back('a' + i);
            freq[i]--;
            solve(ind+1, n, s, freq);
            freq[i]++;
            s.pop_back();
        }   
    }
    return;
}

int main() {
    string s;
    cin>>s;
    vector<int> freq(26);
    for(auto it: s) {
        freq[it - 'a']++;
    }   
    solve(0, s.length(), "", freq);
    cout<<ans.size()<<endl;
    for(auto it: ans) 
        cout<<it<<endl;
    return 0;
}