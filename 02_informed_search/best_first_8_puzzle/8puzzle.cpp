#include <bits/stdc++.h>
using namespace std;

string goal = "123456780";

int heuristic(string s) {
    int h = 0;
    for(int i=0;i<9;i++)
        if(s[i] != '0' && s[i] != goal[i]) h++;
    return h;
}

vector<string> getNext(string s) {
    vector<string> res;
    int pos = s.find('0');
    int x = pos/3, y = pos%3;

    int dx[] = {-1,1,0,0};
    int dy[] = {0,0,-1,1};

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

void aStar(string start) {
    priority_queue<tuple<int,int,string>, vector<tuple<int,int,string>>, greater<>> pq;
    set<string> vis;

    pq.push({heuristic(start), 0, start}); // f, g, state

    while(!pq.empty()) {
        auto [f, g, cur] = pq.top(); pq.pop();

        if(vis.count(cur)) continue;
        vis.insert(cur);

        cout << cur << " f=" << f << "\n";

        if(cur == goal) {
            cout << "Goal reached\n";
            return;
        }

        for(auto nxt : getNext(cur)) {
            if(!vis.count(nxt)) {
                int g2 = g + 1;
                int f2 = g2 + heuristic(nxt);
                pq.push({f2, g2, nxt});
            }
        }
    }
}

int main() {
    string start = "123456708";
    aStar(start);
}

/*
Sample Input:
123456708

Sample Output:
123456708 f=1
123456780 f=1
Goal reached

Problem: Use A* Search (f = g + h) to solve 8-puzzle.
*/