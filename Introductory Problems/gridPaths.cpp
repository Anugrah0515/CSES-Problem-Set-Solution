#include <bits/stdc++.h>

using namespace std;

const int N = 7;
int ans;
char path[N * N + 1];
bool visited[N + 1][N + 1];

bool isValid(int x, int y) {
    return x >= 1 && x <= N && y >= 1 && y <= N;
}

void dfs(int x, int y, int step) {
    if (step == N * N - 1 || (x == N && y == 1)) {
        if (step == N * N - 1 && (x == N && y == 1)) {
            ans++;
        }
        return;
    }

    if ((!isValid(x + 1, y) || visited[x + 1][y]) && (!isValid(x - 1, y) || visited[x - 1][y])) {
        if (isValid(x, y + 1) && !visited[x][y + 1] && isValid(x, y - 1) && !visited[x][y - 1]) {
            return;
        }
    }
    
    if ((!isValid(x, y + 1) || visited[x][y + 1]) && (!isValid(x, y - 1) || visited[x][y - 1])) {
        if (isValid(x + 1, y) && !visited[x + 1][y] && isValid(x - 1, y) && !visited[x - 1][y]) {
            return;
        }
    }

    visited[x][y] = true;
    
    if (path[step] == 'D' || path[step] == '?') {
        if (isValid(x + 1, y) && !visited[x + 1][y]) {
            dfs(x + 1, y, step + 1);
        }
    }
    
    if (path[step] == 'U' || path[step] == '?') {
        if (isValid(x - 1, y) && !visited[x - 1][y]) {
            dfs(x - 1, y, step + 1);
        }
    }
    
    if (path[step] == 'R' || path[step] == '?') {
        if (isValid(x, y + 1) && !visited[x][y + 1]) {
            dfs(x, y + 1, step + 1);
        }
    }
    
    if (path[step] == 'L' || path[step] == '?') {
        if (isValid(x, y - 1) && !visited[x][y - 1]) {
            dfs(x, y - 1, step + 1);
        }
    }
    
    visited[x][y] = false;
}

int main() {
    cin >> path;
    dfs(1, 1, 0);
    cout << ans << endl;
    return 0;
}
