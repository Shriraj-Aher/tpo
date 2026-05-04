#include <bits/stdc++.h>
using namespace std;

set<pair<int,int>> vis;

void dfs(int x, int y, int m, int n, int d) {
    if(vis.count({x,y})) return;

    cout << "(" << x << "," << y << ")\n";
    vis.insert({x,y});

    if(x==d || y==d) {
        cout << "Goal reached\n";
        return;
    }

    vector<pair<int,int>> next = {
        {m,y},{x,n},{0,y},{x,0},
        {x-min(x,n-y), y+min(x,n-y)},
        {x+min(y,m-x), y-min(y,m-x)}
    };

    for(auto [nx,ny] : next) {
        dfs(nx,ny,m,n,d);
    }
}

int main() {
    int m=4,n=3,d=2;
    dfs(0,0,m,n,d);
}

/*
Sample Input:
Jug1 = 4, Jug2 = 3, Target = 2

Sample Output:
(0,0)
(4,0)
(4,3)
...
Goal reached

Problem: Use DFS to find steps to measure target water using two jugs.
*/