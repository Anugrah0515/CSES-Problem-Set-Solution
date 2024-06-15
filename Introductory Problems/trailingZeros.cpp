#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll mod = 1e9 + 7;

ll countNumberOfDivisor(int n, int divisor) {
    int count = 0;
    while(n % divisor == 0) {
        count++;
        n /= divisor;
    }
    return count;
}

int main() {
    ll n, countFive = 0;
    cin>>n;
    for(int i=5;i<=n;i+=5) {
        countFive += countNumberOfDivisor(i, 5);
    }
    cout<<countFive<<endl;
    return 0;
}