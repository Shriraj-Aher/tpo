#include <bits/stdc++.h>
using namespace std;

string goal="123456780";

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

void bfs(string start) {
    queue<string> q;
    set<string> vis;

    q.push(start);
    vis.insert(start);

    while(!q.empty()) {
        string cur=q.front(); q.pop();
        cout<<cur<<"\n";

        if(cur==goal) {
            cout<<"Goal reached\n";
            return;
        }

        for(auto nxt:getNext(cur)) {
            if(!vis.count(nxt)) {
                q.push(nxt);
                vis.insert(nxt);
            }
        }
    }
}

int main() {
    string start="123456708";
    bfs(start);
}

// 123456708

/*

Sample Input:

123456708

Sample Output:

123456708

123456780

Goal reached

Problem: Use BFS to solve the 8-puzzle problem.

*/