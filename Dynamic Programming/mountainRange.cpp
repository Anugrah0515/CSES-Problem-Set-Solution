#include <bits/stdc++.h>
using namespace std;

struct Range {
    int h;
    int sz;
    int dp;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<Range> range(n);
    vector<int> ord(n);

    for (int i = 0; i < n; i++) {
        cin >> range[i].h;
        range[i].sz = 1;
        range[i].dp = 1;
        ord[i] = i;
    }

    sort(ord.begin(), ord.end(), [&](int a, int b) {
        if (range[a].h != range[b].h)
            return range[a].h < range[b].h;
        return a < b;
    });

    int ans = 1;

    for (int id : ord) {
        Range cur = range[id];

        int L = id;
        while (L > 0 && range[L - 1].h < cur.h) {
            Range t = range[L - 1];
            cur.dp = max(cur.dp, t.dp + 1);
            L -= t.sz;
        }

        int R = id;
        while (R + 1 < n && range[R + 1].h < cur.h) {
            Range t = range[R + 1];
            cur.dp = max(cur.dp, t.dp + 1);
            R += t.sz;
        }

        cur.sz = R - L + 1;
        ans = max(ans, cur.dp);

        range[L] = cur;
        range[R] = cur;
    }

    cout << ans << "\n";
    return 0;
}