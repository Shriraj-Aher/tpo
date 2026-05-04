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

void bestFirst(string start) {
    priority_queue<pair<int,string>, vector<pair<int,string>>, greater<>> pq;
    set<string> vis;

    pq.push({heuristic(start), start});

    while(!pq.empty()) {
        auto [h, cur] = pq.top(); pq.pop();

        if(vis.count(cur)) continue;
        vis.insert(cur);

        cout << cur << " h=" << h << "\n";

        if(cur == goal) {
            cout << "Goal reached\n";
            return;
        }

        for(auto nxt : getNext(cur)) {
            if(!vis.count(nxt))
                pq.push({heuristic(nxt), nxt});
        }
    }
}

int main() {
    string start = "123456708";
    bestFirst(start);
}

/*
Sample Input:
123456708

Sample Output:
123456708 h=1
123456780 h=0
Goal reached

Problem: Use Best First Search with heuristic (misplaced tiles) to solve 8-puzzle.
*/