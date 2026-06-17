#include <bits/stdc++.h>
using namespace std;

class BIT {
public:
    int n;
    vector<int> bit;

    BIT(int n) {
        this->n = n;
        bit.assign(n + 1, 0);
    }

    void update(int idx, int val) {
        while (idx <= n) {
            bit[idx] += val;
            idx += idx & (-idx);
        }
    }

    int query(int idx) {
        int sum = 0;
        while (idx > 0) {
            sum += bit[idx];
            idx -= idx & (-idx);
        }
        return sum;
    }

    int kth(int k) {
        int pos = 0;

        int pw = 1;
        while ((pw << 1) <= n) pw <<= 1;

        for (int jump = pw; jump; jump >>= 1) {
            if (pos + jump <= n && bit[pos + jump] < k) {
                k -= bit[pos + jump];
                pos += jump;
            }
        }

        return pos + 1;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long k;
    cin >> n >> k;

    BIT ft(n);

    for (int i = 1; i <= n; i++)
        ft.update(i, 1);

    long long pos = 0;
    int alive = n;

    while (alive) {
        pos = (pos + k) % alive;

        int person = ft.kth(pos + 1);

        cout << person << " ";

        ft.update(person, -1);

        alive--;
    }

    return 0;
}