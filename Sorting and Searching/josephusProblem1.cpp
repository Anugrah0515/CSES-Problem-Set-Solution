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


long long MOD = 1e9 + 7;

struct Node {
    int val;
    Node* next;
};


 
void solve() {
    int n;
    cin >> n;

    Node* head = new Node;
    head->val = 1;
    Node* curr = head;
    int tmp = n - 1;
    while(tmp--) {
        Node* next = new Node;
        next->val = curr->val + 1;
        next->next = NULL;
        curr->next = next;
        curr = next;
    }
    curr->next = head;
    curr = head->next;
    Node* prev = head;
    int count = n;
    while(count != 1) {
        cout << curr->val << " ";
        prev->next = curr->next;
        Node* temp = curr;
        curr = curr->next;
        curr = curr->next;
        prev = prev->next;
        delete(temp);
        count--;
    }
    cout << prev->val;
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