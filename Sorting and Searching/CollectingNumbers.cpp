#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto &it: a) 
        cin>>it;
    vector<int> indices(n+1);
    for(int i=0;i<=n;i++) {
        indices[a[i]] = i;
    }
    int count = 0;
    for(int i=1;i<n;i++) {
        if (indices[i+1] < indices[i])
            count++;
    }
    cout<<count + 1<<endl;
    return 0;
}