#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define ll long long
#define input(a, n) for (int i = 0; i < n; i++) cin >> a[i];
#define output(a) for (auto it : a) cout << it << " ";
#define sortFcn(a) sort(a.begin(), a.end());
#define rev(a) reverse(a.begin(), a.end());
#define lowerBound(a, x) lower_bound(a.begin(), a.end(), x)
#define upperBound(a, x) upper_bound(a.begin(), a.end(), x)
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define newline cout << endl;
 
void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a;
    for(int i=0;i<n;i++) {
        int x, y;
        cin >> x >> y;
        a.pb({x, y, i});
    }
    
    sortFcn(a);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> roomAllocation(n);
    int count = 0;
    for(auto it: a) {
        int start = it[0], end = it[1], idx = it[2];
        if(!pq.empty() && pq.top().first < start) {
            auto [dept, room] = pq.top();
            pq.pop();
            roomAllocation[idx] = room;
            pq.push({end, room});
        } else {
            count++;
            roomAllocation[idx] = count;
            pq.push({end, count});
        }
    }
    cout << count << endl;
    output(roomAllocation)
    newline

}
 
int main()
{
 
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int t = 1;
    // cin >> t;
 
    while (t--)
    {
        solve();
    }
 
    return 0;
}