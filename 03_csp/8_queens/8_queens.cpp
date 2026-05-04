#include <bits/stdc++.h>
using namespace std;

vector<int> board(8, -1);

bool safe(int row, int col) {
    for(int i=0;i<row;i++) {
        if(board[i]==col || abs(board[i]-col)==abs(i-row))
            return false;
    }
    return true;
}

bool solve(int row) {
    if(row==8) {
        cout << "Solution:\n";
        for(int i=0;i<8;i++)
            cout << board[i] << " ";
        cout << "\n";
        return true;
    }

    for(int col=0;col<8;col++) {
        if(safe(row,col)) {
            board[row] = col;
            if(solve(row+1)) return true;
            board[row] = -1;
        }
    }
    return false;
}

int main() {
    solve(0);
}

/*
Sample Input:
N = 8 (fixed)

Sample Output:
Solution:
0 4 7 5 2 6 1 3

Problem: Solve 8-Queens using CSP (backtracking).
*/