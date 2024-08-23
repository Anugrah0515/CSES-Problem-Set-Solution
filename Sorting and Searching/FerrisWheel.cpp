#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int main() {
    int n, x;
    cin>>n>>x;
    vector<int> a(n);
    for(auto &it: a) 
        cin>>it;
    sort(a.begin(), a.end());
    int start = 0, end = n - 1, count = 0;
    while(start <= end) {
        if (start == end) {
            count++;
            break;
        }
        if (a[start] + a[end] <= x) {
            start++;
            end--;
            count++;
        } else {
            end--;
            count++;
        }
    }
    cout<<count<<endl;
    return 0;
}