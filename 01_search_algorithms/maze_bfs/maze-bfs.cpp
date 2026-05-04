#include <bits/stdc++.h>
using namespace std;

int maze[5][5] = {
    {1,1,0,1,1},
    {0,1,0,1,0},
    {1,1,1,1,1},
    {0,0,1,0,1},
    {1,1,1,1,1}
};

bool vis[5][5];

void bfs() {
    queue<pair<int,int>> q;
    q.push({0,0});
    vis[0][0] = true;

    int dx[] = {-1,1,0,0};
    int dy[] = {0,0,-1,1};

    while(!q.empty()) {
        auto [x,y] = q.front(); q.pop();
        cout << "(" << x << "," << y << ")\n";

        if(x==4 && y==4) {
            cout << "Reached goal\n";
            return;
        }

        for(int i=0;i<4;i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx>=0 && ny>=0 && nx<5 && ny<5 &&
               maze[nx][ny]==1 && !vis[nx][ny]) {
                vis[nx][ny] = true;
                q.push({nx,ny});
            }
        }
    }
}

int main() {
    bfs();
}

/*
Sample Input:
Maze (1 = path, 0 = blocked)
Start: (0,0), End: (4,4)

Sample Output:
(0,0)
(0,1)
(1,1)
...
(4,4)
Reached goal

Problem: Use BFS to find a path from start to goal in a maze.
*/