#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int main() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) 
        cin>>a[i];
    sort(a.begin(), a.end());
    int minLength = a[n / 2];
    ll minCost = 0;
    for(auto it: a) {
        minCost += abs(it - minLength);
    }
    cout<<minCost<<endl;
    return 0;
}