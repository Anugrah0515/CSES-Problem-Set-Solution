#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll n;
    cin>>n;
    bool flag = ((n * (n + 1)) / 2) % 2;
    if (flag) {
        cout<<"NO"<<endl;
        return 0;
    }
    ll targetSum = (n * (n + 1)) / 4;
    int i = 1, j = n;
    ll sum = 0;
    flag = false;
    set<int> st;
    while(sum != targetSum) {
        if (flag) {
            sum += i;
            st.insert(i);
            i++;
        } else {
            sum += j;
            st.insert(j);
            j--;
        }
        flag = !flag;
    }
    cout<<"YES"<<endl;
    cout<<st.size()<<endl;
    for(auto it: st)
        cout<<it<<" ";
    cout<<endl;
    cout<<n - st.size()<<endl;
    for(int i=1;i<n;i++) {
        if (st.find(i) == st.end())
            cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}