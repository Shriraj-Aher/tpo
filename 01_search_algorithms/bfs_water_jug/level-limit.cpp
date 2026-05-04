#include <bits/stdc++.h>
using namespace std;

set<pair<int,int>> vis;

void dls(int x, int y, int m, int n, int d, int depth, int limit) {
    if(depth > limit || vis.count({x,y})) return;

    cout << "(" << x << "," << y << ") Depth="<<depth<<"\n";
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

    for(auto [nx,ny]:next) {
        dls(nx,ny,m,n,d,depth+1,limit);
    }
}

int main() {
    int m=4,n=3,d=2;
    int limit=3;
    dls(0,0,m,n,d,0,limit);
}

/*
Sample Input:
Jug1 = 4, Jug2 = 3, Target = 2, Depth Limit = 3

Sample Output:
(0,0) Depth=0
(4,0) Depth=1
...
Goal reached OR search stops at depth limit

Problem: Use Depth Limited Search to solve Water Jug problem.
*/