#include <bits/stdc++.h>
using namespace std;

map<char, vector<pair<char,int>>> graph;
map<char,int> heuristic;

void bestFirst(char start, char goal) {
    priority_queue<pair<int,char>, vector<pair<int,char>>, greater<>> pq;
    set<char> vis;

    pq.push({heuristic[start], start});

    while(!pq.empty()) {
        auto [h, node] = pq.top(); pq.pop();

        if(vis.count(node)) continue;
        vis.insert(node);

        cout << node << " h=" << h << "\n";

        if(node == goal) {
            cout << "Goal reached\n";
            return;
        }

        for(auto [nbr, cost] : graph[node]) {
            if(!vis.count(nbr))
                pq.push({heuristic[nbr], nbr});
        }
    }
}

int main() {
    graph['A'] = {{'B',1},{'C',3}};
    graph['B'] = {{'D',1}};
    graph['C'] = {{'D',1}};
    graph['D'] = {};

    heuristic['A']=3;
    heuristic['B']=2;
    heuristic['C']=1;
    heuristic['D']=0;

    bestFirst('A','D');
}

/*
Sample Input:
Graph + heuristic values (hardcoded)

Sample Output:
A h=3
C h=1
D h=0
Goal reached

Problem: Use Best First Search to find shortest route using heuristic values.
*/