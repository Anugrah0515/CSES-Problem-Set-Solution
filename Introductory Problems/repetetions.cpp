#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    string s;
    cin>>s;
    int currLength = 0, maxLength = 0;
    char lastChar = '*';
    for(auto it: s) {
        if (it == lastChar) {
            currLength++;
        } else {
            maxLength = max(maxLength, currLength); 
            currLength = 1;
            lastChar = it;
        }
    }
    cout<<max(maxLength, currLength)<<endl;
    return 0;
}