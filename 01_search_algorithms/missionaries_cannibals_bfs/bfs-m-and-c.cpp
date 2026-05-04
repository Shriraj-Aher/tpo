#include <bits/stdc++.h>
using namespace std;

struct State {
    int m, c, boat;
};

bool valid(int m, int c) {
    if(m<0 || c<0 || m>3 || c>3) return false;
    if(m>0 && m<c) return false;
    if((3-m)>0 && (3-m)<(3-c)) return false;
    return true;
}

void bfs() {
    queue<State> q;
    set<tuple<int,int,int>> vis;

    q.push({3,3,1});
    vis.insert({3,3,1});

    while(!q.empty()) {
        auto [m,c,b] = q.front(); q.pop();
        cout << "M="<<m<<" C="<<c<<" Boat="<<b<<"\n";

        if(m==0 && c==0) {
            cout << "Goal reached\n";
            return;
        }

        vector<pair<int,int>> moves = {
            {1,0},{0,1},{1,1},{2,0},{0,2}
        };

        for(auto [dm,dc]:moves) {
            int nm = b ? m-dm : m+dm;
            int nc = b ? c-dc : c+dc;
            int nb = 1-b;

            if(valid(nm,nc) && !vis.count({nm,nc,nb})) {
                q.push({nm,nc,nb});
                vis.insert({nm,nc,nb});
            }
        }
    }
}

int main() {
    bfs();
}

/*
Sample Input:
3 missionaries, 3 cannibals, boat on left

Sample Output:
M=3 C=3 Boat=1
M=3 C=1 Boat=0
...
M=0 C=0 Boat=0
Goal reached

Problem: Use BFS to safely move all missionaries and cannibals across the river.
*/