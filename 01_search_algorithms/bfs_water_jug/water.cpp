#include <bits/stdc++.h>
using namespace std;

struct State { int x,y; };

void bfs(int m,int n,int d) {
    queue<State> q;
    set<pair<int,int>> vis;

    q.push({0,0});
    vis.insert({0,0});

    while(!q.empty()) {
        auto [x,y]=q.front(); q.pop();
        cout<<"("<<x<<","<<y<<")\n";

        if(x==d || y==d) {
            cout<<"Goal reached\n";
            return;
        }

        vector<State> next={
            {m,y},{x,n},{0,y},{x,0},
            {x-min(x,n-y), y+min(x,n-y)},
            {x+min(y,m-x), y-min(y,m-x)}
        };

        for(auto s:next) {
            if(!vis.count({s.x,s.y})) {
                q.push(s);
                vis.insert({s.x,s.y});
            }
        }
    }
}

int main() {
    int m=4,n=3,d=2;
    bfs(m,n,d);
}

// (0,0)
// (4,0)
// (0,3)
// ...
// Goal reached

/*

Sample Input:

Jug1 = 4, Jug2 = 3, Target = 2

Sample Output:

(0,0)

(4,0)

(0,3)

...

Goal reached

Problem: Use BFS to find steps to measure target water using two jugs.

*/