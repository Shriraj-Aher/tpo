#include <bits/stdc++.h>
using namespace std;

set<tuple<int,int,int>> vis;

bool valid(int m, int c) {
    if(m<0 || c<0 || m>3 || c>3) return false;
    if(m>0 && m<c) return false;
    if((3-m)>0 && (3-m)<(3-c)) return false;
    return true;
}

void dfs(int m, int c, int boat) {
    if(vis.count({m,c,boat})) return;

    cout << "M="<<m<<" C="<<c<<" Boat="<<boat<<"\n";
    vis.insert({m,c,boat});

    if(m==0 && c==0) {
        cout << "Goal reached\n";
        return;
    }

    vector<pair<int,int>> moves = {
        {1,0},{0,1},{1,1},{2,0},{0,2}
    };

    for(auto [dm,dc]:moves) {
        int nm = boat ? m-dm : m+dm;
        int nc = boat ? c-dc : c+dc;
        int nb = 1-boat;

        if(valid(nm,nc)) {
            dfs(nm,nc,nb);
        }
    }
}

int main() {
    dfs(3,3,1);
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

Problem: Use DFS to move all missionaries and cannibals safely across the river.
*/