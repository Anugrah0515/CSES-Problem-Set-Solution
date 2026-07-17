#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MOD = 1e9 + 7;

int n, m;
vector<vector<int>> dp;

void generateMasks(int row, int currMask, int nextMask, vector<int>& nextMasks) {
    if (row == n) {
        nextMasks.push_back(nextMask);
        return;
    }

    if (currMask & (1 << row)) {
        generateMasks(row + 1, currMask, nextMask, nextMasks);
    } else {
        generateMasks(row + 1, currMask, nextMask | (1 << row), nextMasks);

        if (row + 1 < n && !(currMask & (1 << (row + 1)))) {
            generateMasks(row + 2, currMask, nextMask, nextMasks);
        }
    }
}

int solve(int col, int mask) {

    if (col == m)
        return (mask == 0);

    if (dp[col][mask] != -1)
        return dp[col][mask];

    vector<int> nextMasks;
    generateMasks(0, mask, 0, nextMasks);

    ll ans = 0;

    for (int nextMask : nextMasks) {
        ans += solve(col + 1, nextMask);
        ans %= MOD;
    }

    return dp[col][mask] = ans;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    dp.assign(m + 1, vector<int>(1 << n, -1));

    cout << solve(0, 0) << '\n';

    return 0;
}