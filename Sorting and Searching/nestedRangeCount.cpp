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

struct BIT {
    int n;
    vector<int> bit;

    BIT(int n) : n(n), bit(n + 1, 0) {}

    void update(int idx, int val) {
        while (idx <= n) {
            bit[idx] += val;
            idx += idx & -idx;
        }
    }

    int query(int idx) {
        int sum = 0;
        while (idx > 0) {
            sum += bit[idx];
            idx -= idx & -idx;
        }
        return sum;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<array<int, 3>> ranges(n);
    vector<int> rights;

    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        ranges[i] = {l, r, i};
        rights.push_back(r);
    }

    sort(rights.begin(), rights.end());
    rights.erase(unique(rights.begin(), rights.end()), rights.end());

    auto getRank = [&](int r) {
        return lower_bound(rights.begin(), rights.end(), r) - rights.begin() + 1;
    };

    sort(ranges.begin(), ranges.end(), [](auto &a, auto &b) {
        if (a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    });

    vector<int> contains(n), contained(n);

    // contains count
    BIT bit1(rights.size());

    for (int i = n - 1; i >= 0; i--) {
        int r = ranges[i][1];
        int idx = ranges[i][2];

        int pos = getRank(r);

        contains[idx] = bit1.query(pos);
        bit1.update(pos, 1);
    }

    // contained count
    BIT bit2(rights.size());
    int processed = 0;

    for (int i = 0; i < n; i++) {
        int r = ranges[i][1];
        int idx = ranges[i][2];

        int pos = getRank(r);

        contained[idx] = processed - bit2.query(pos - 1);

        bit2.update(pos, 1);
        processed++;
    }

    output(contains)
    newline
    output(contained)
    newline

    return 0;
}