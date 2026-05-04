#include <bits/stdc++.h>
using namespace std;

bool safe(vector<int>& board, int row, int col) {
    for(int i=0;i<row;i++) {
        int c = board[i];
        if(c==col || abs(c-col)==abs(i-row))
            return false;
    }
    return true;
}

void bfs() {
    queue<vector<int>> q;
    q.push(vector<int>(8,-1));

    while(!q.empty()) {
        auto board = q.front(); q.pop();

        int row = 0;
        while(row<8 && board[row]!=-1) row++;

        if(row==8) {
            cout<<"Solution:\n";
            for(int i=0;i<8;i++)
                cout<<board[i]<<" ";
            cout<<"\n";
            return;
        }

        for(int col=0;col<8;col++) {
            if(safe(board,row,col)) {
                auto newBoard = board;
                newBoard[row] = col;
                q.push(newBoard);
            }
        }
    }
}

int main() {
    bfs();
}

/*
Sample Input:
N = 8 (fixed)

Sample Output:
Solution:
0 4 7 5 2 6 1 3

Problem: Use BFS to place 8 queens such that no two attack each other.
*/
