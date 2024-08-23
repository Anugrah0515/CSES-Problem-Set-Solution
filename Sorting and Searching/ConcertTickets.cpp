#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n, m;
    cin>>n>>m;
    multiset<int> a;
    for(int i=0;i<n;i++) {
        int x;
        cin>>x;
        a.insert(-x);
    }
    for(int i=0;i<m;i++) {
        int b;
        cin>>b;
        b = -b;
        if (a.lower_bound(b) == a.end()) {
            cout<<-1;
        } else {
            cout<<-(*a.lower_bound(b))<<endl;
            a.erase(b);
        }
    }
    return 0;
}