#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;
ll MOD = 1000000007;

vector<string> mat;
queue<pair<int,int>> mons;
queue<pair<int,int>> you;
vector<vector<int>> dMons;
vector<vector<int>> dYou;
vector<vector<int>> pathGrid;
int n,m;

int dirx[] = {-1,1,0,0};
int diry[] = {0,0,-1,1};
char dirName[] = {'U','D','L','R'};

bool isExit(int x, int y){ return x==0||y==0||x==n-1||y==m-1; }

void printPath(int x,int y){
    string p;
    while (dYou[x][y]!=0){
        int i = pathGrid[x][y];
        p.push_back(dirName[i]);
        x -= dirx[i];
        y -= diry[i];
    }
    reverse(p.begin(), p.end());
    cout << p << '\n';
}

void solve(){
    while (!mons.empty()) {
        auto v = mons.front(); mons.pop();
        for (int i=0;i<4;++i){
            int nx = v.first + dirx[i], ny = v.second + diry[i];
            if (nx<0||nx>=n||ny<0||ny>=m) continue;
            if (mat[nx][ny]=='#') continue;
            if (dMons[nx][ny] != INF) continue;
            dMons[nx][ny] = dMons[v.first][v.second] + 1;
            mons.push({nx, ny});
        }
    }

    pathGrid = dYou;
    while (!you.empty()){
        auto v = you.front(); you.pop();
        if (isExit(v.first, v.second) && dYou[v.first][v.second] < dMons[v.first][v.second]) {
            cout << "YES\n" << dYou[v.first][v.second] << '\n';
            printPath(v.first, v.second);
            return;
        }
        for (int i=0;i<4;++i){
            int nx = v.first + dirx[i], ny = v.second + diry[i];
            if (nx<0||nx>=n||ny<0||ny>=m) continue;
            if (mat[nx][ny] == '#') continue;
            if (dYou[nx][ny] != INF) continue;
            dYou[nx][ny] = dYou[v.first][v.second] + 1;
            pathGrid[nx][ny] = i;
            you.push({nx, ny});
        }
    }
    cout << "NO\n";
}

int main(){
    cin >> n >> m;
    mat.assign(n, "");
    dMons.assign(n, vector<int>(m, INF));
    dYou.assign(n, vector<int>(m, INF));
    pathGrid.assign(n, vector<int>(m, -1));
    for (int i=0;i<n;++i){
        cin >> mat[i];
        for (int j=0;j<m;++j){
            if (mat[i][j] == 'M'){ mons.push({i,j}); dMons[i][j] = 0; }
            else if (mat[i][j] == 'A'){ you.push({i,j}); dYou[i][j] = 0; }
        }
    }
    solve();
    return 0;
}
