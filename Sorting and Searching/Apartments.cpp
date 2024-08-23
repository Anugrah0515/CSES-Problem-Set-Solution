#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n, m, k;
    cin>>n>>m>>k;
    vector<int> a(n), b(m);
    for(auto &it: a)
        cin>>it;
    for(auto &it: b) 
        cin>>it;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int count = 0, i = 0, j = 0;    
    while(i < n && j < m) {
        while(j < m && b[j] < a[i] - k) j++;
        if (b[j] <= a[i] + k && b[j] >= a[i] - k) {
            j++;
            i++;
            count++;
        } else i++;
    }
    cout<<count<<endl;
    return 0;
}