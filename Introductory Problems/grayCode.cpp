#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n;
    cin>>n;
    vector<int> arr(n+1);
    for(int i=0;i<n;i++)
        cout<<arr[i];
    cout<<endl;
    for(int i=1;i<(1<<n);i++) {
        int lsb = __builtin_ffs(i);
        arr[lsb] ^= 1;
        for(int i=n;i>=1;i--)
            cout<<arr[i];
        cout<<endl;
    }
    return 0;
}