#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n;
    cin>>n;
    vector<pair<int, int>> a;
    for(int i=0;i<n;i++) {
        int arrival, dept;
        cin>>arrival>>dept;
        a.push_back({arrival, 1});
        a.push_back({dept + 1, -1});
    }
    sort(a.begin(), a.end());
    int maxCustomers = 0, currCustomers = 0;
    for(auto it: a) {
        currCustomers += it.second;
        maxCustomers = max(maxCustomers, currCustomers);
    }
    cout<<maxCustomers<<endl;
    return 0;
}