#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool checkValidChessboard(vector<vector<bool>>& board, vector<vector<bool>>& input, int n) {
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if (board[i][j] && input[i][j])
                return false;
        }
    }
    return true;
}

bool checkUnderAttack(vector<vector<bool>>& board, int n, int row, int col) {
    for(int i = 0; i < n; i++)
        if(board[row][i] || board[i][col])
            return false;
    for(int i = 0; row-i >= 0 && col-i >= 0; i++)
        if(board[row-i][col-i])
            return false;
    for(int i = 0; row-i >= 0 && col+i < n; i++)
        if(board[row-i][col+i])
            return false;
    return true;
}

void solve(int row, vector<vector<bool>>& board, int n, int& ans, vector<vector<bool>>& input) {
    if (row == n) {
        if (checkValidChessboard(board, input, n))
            ans++;
        return;
    }
    for(int col=0;col<n;col++) {
        if (checkUnderAttack(board, n, row, col)) {
            board[row][col] = true;
            solve(row + 1, board, n, ans, input);
            board[row][col] = false;
        }
    }
}

int main() {
    int n = 8;
    vector<vector<bool>> input(n, vector<bool>(n)), board(n, vector<bool>(n, false));
    char ch;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin>>ch;
            input[i][j] = (ch == '*');
        }
    }
    int ans = 0;
    solve(0, board, n, ans, input);
    cout<<ans<<endl;
    return 0;    
}