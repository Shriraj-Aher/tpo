#include <bits/stdc++.h>
using namespace std;

map<char, vector<pair<char,int>>> graph;
map<char,int> heuristic;

void aStar(char start, char goal) {
    priority_queue<tuple<int,int,char>, vector<tuple<int,int,char>>, greater<>> pq;
    set<char> vis;

    pq.push({heuristic[start], 0, start}); // f, g, node

    while(!pq.empty()) {
        auto [f, g, node] = pq.top(); pq.pop();

        if(vis.count(node)) continue;
        vis.insert(node);

        cout << node << " f=" << f << "\n";

        if(node == goal) {
            cout << "Goal reached\n";
            return;
        }

        for(auto [nbr, cost] : graph[node]) {
            if(!vis.count(nbr)) {
                int g2 = g + cost;
                int f2 = g2 + heuristic[nbr];
                pq.push({f2, g2, nbr});
            }
        }
    }
}

int main() {
    graph['A'] = {{'B',1},{'C',4}};
    graph['B'] = {{'D',2}};
    graph['C'] = {{'D',1}};
    graph['D'] = {};

    heuristic['A']=3;
    heuristic['B']=2;
    heuristic['C']=1;
    heuristic['D']=0;

    aStar('A','D');
}

/*
Sample Input:
Graph + heuristic values (hardcoded)

Sample Output:
A f=3
B f=3
D f=3
Goal reached

Problem: Use A* search to find shortest path using f = g + h.
*/