#include <bits/stdc++.h>
using namespace std;

#define output(a) for(auto it: a) cout << it << " ";
#define newline cout << '\n';

vector<pair<int,int>> nextPos = {
    {2,1}, {1,2}, {2,-1}, {-1,2},
    {-2,-1}, {-1,-2}, {-2,1}, {1,-2}
};

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n, -1));

    queue<pair<int,int>> q;

    q.push({0,0});
    grid[0][0] = 0;

    while(!q.empty()) {
        auto [i,j] = q.front();
        q.pop();

        for(auto [dx,dy] : nextPos) {
            int r = i + dx;
            int c = j + dy;

            if(r >= 0 && c >= 0 && r < n && c < n && grid[r][c] == -1) {
                grid[r][c] = grid[i][j] + 1;
                q.push({r,c});
            }
        }
    }

    for(auto &row : grid) {
        output(row)
        newline
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}