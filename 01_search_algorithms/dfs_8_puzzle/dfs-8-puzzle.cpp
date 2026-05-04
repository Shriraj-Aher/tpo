#include <bits/stdc++.h>
using namespace std;

string goal="123456780";
set<string> vis;

vector<string> getNext(string s) {
    vector<string> res;
    int pos=s.find('0');
    int x=pos/3,y=pos%3;

    int dx[]={-1,1,0,0};
    int dy[]={0,0,-1,1};

    for(int i=0;i<4;i++) {
        int nx=x+dx[i], ny=y+dy[i];
        if(nx>=0 && ny>=0 && nx<3 && ny<3) {
            string t=s;
            swap(t[x*3+y], t[nx*3+ny]);
            res.push_back(t);
        }
    }
    return res;
}

void dfs(string cur) {
    if(vis.count(cur)) return;

    cout << cur << "\n";
    vis.insert(cur);

    if(cur==goal) {
        cout << "Goal reached\n";
        return;
    }

    for(auto nxt:getNext(cur)) {
        dfs(nxt);
    }
}

int main() {
    string start="123456708";
    dfs(start);
}

/*
Sample Input:
123456708

Sample Output:
123456708
...
123456780
Goal reached

Problem: Use DFS to solve the 8-puzzle problem.
*/