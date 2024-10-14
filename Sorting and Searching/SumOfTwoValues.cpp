#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n, x;
    cin>>n>>x;
    vector<pair<int, int>> a;
    for(int i=0;i<n;i++) {
        int temp;
        cin>>temp;
        a.push_back({temp, i});
    }
    int start = 0, end = n - 1;
    sort(a.begin(), a.end());
    while(start < end) {
        if (x == a[start].first + a[end].first) break;
        else if (x > a[start].first + a[end].first) start++;
        else end--;
    }
    if (start >= end) cout<<"IMPOSSIBLE"<<endl;
    else cout<<a[start].second + 1<<" "<<a[end].second + 1<<endl;
    return 0;
}