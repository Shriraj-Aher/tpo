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

void dfs(int x, int y) {
    if(x<0 || y<0 || x>=5 || y>=5) return;
    if(maze[x][y]==0 || vis[x][y]) return;

    cout << "(" << x << "," << y << ")\n";
    vis[x][y] = true;

    if(x==4 && y==4) {
        cout << "Reached goal\n";
        return;
    }

    dfs(x-1,y);
    dfs(x+1,y);
    dfs(x,y-1);
    dfs(x,y+1);
}

int main() {
    dfs(0,0);
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

Problem: Use DFS to find a path in a maze.
*/