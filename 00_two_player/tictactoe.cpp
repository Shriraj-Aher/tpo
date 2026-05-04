#include <bits/stdc++.h>
using namespace std;

char board[3][3];

void printBoard() {
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
}

bool isMovesLeft() {
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(board[i][j]=='_') return true;
    return false;
}

int evaluate() {
    for(int i=0;i<3;i++) {
        if(board[i][0]==board[i][1] && board[i][1]==board[i][2]) {
            if(board[i][0]=='X') return +10;
            if(board[i][0]=='O') return -10;
        }
    }
    for(int j=0;j<3;j++) {
        if(board[0][j]==board[1][j] && board[1][j]==board[2][j]) {
            if(board[0][j]=='X') return +10;
            if(board[0][j]=='O') return -10;
        }
    }
    if(board[0][0]==board[1][1] && board[1][1]==board[2][2]) {
        if(board[0][0]=='X') return +10;
        if(board[0][0]=='O') return -10;
    }
    if(board[0][2]==board[1][1] && board[1][1]==board[2][0]) {
        if(board[0][2]=='X') return +10;
        if(board[0][2]=='O') return -10;
    }
    return 0;
}

int minimax(bool isMax) {
    int score = evaluate();

    if(score==10 || score==-10) return score;
    if(!isMovesLeft()) return 0;

    if(isMax) {
        int best=-1000;
        for(int i=0;i<3;i++) {
            for(int j=0;j<3;j++) {
                if(board[i][j]=='_') {
                    board[i][j]='X';
                    best=max(best,minimax(false));
                    board[i][j]='_';
                }
            }
        }
        return best;
    } else {
        int best=1000;
        for(int i=0;i<3;i++) {
            for(int j=0;j<3;j++) {
                if(board[i][j]=='_') {
                    board[i][j]='O';
                    best=min(best,minimax(true));
                    board[i][j]='_';
                }
            }
        }
        return best;
    }
}

pair<int,int> findBestMove() {
    int bestVal=-1000;
    pair<int,int> bestMove={-1,-1};

    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            if(board[i][j]=='_') {
                board[i][j]='X';
                int moveVal=minimax(false);
                board[i][j]='_';

                if(moveVal>bestVal) {
                    bestMove={i,j};
                    bestVal=moveVal;
                }
            }
        }
    }
    return bestMove;
}

int main() {
    memset(board,'_',sizeof(board));

    board[0][0]='O';
    board[1][1]='X';

    printBoard();

    auto move=findBestMove();
    cout<<"AI Move: "<<move.first<<" "<<move.second<<endl;
}



/*

Sample Input:

Pre-filled board (hardcoded)

Sample Output:

O _ _

_ X _

_ _ _

AI Move: 0 1

Problem: Implement a two-player Tic Tac Toe game using Minimax AI.

*/