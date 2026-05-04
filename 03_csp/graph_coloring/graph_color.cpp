#include <iostream>
using namespace std;

#define MAX 100

int graph[MAX][MAX];
int color[MAX];
int n, m; // n = vertices, m = colors

// Check if it's safe to color vertex v with color c
bool isSafe(int v, int c) {
    for (int i = 0; i < n; i++) {
        if (graph[v][i] == 1 && color[i] == c)
            return false;
    }
    return true;
}

// Backtracking function
bool graphColoring(int v) {
    // If all vertices are colored
    if (v == n)
        return true;

    // Try all colors
    for (int c = 1; c <= m; c++) {
        if (isSafe(v, c)) {
            color[v] = c;

            if (graphColoring(v + 1))
                return true;

            // Backtrack
            color[v] = 0;
        }
    }
    return false;
}

int main() {
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];

    cout << "Enter number of colors: ";
    cin >> m;

    // Initialize colors
    for (int i = 0; i < n; i++)
        color[i] = 0;

    if (graphColoring(0)) {
        cout << "\nSolution exists:\n";
        for (int i = 0; i < n; i++)
            cout << "Vertex " << i << " -> Color " << color[i] << endl;
    } else {
        cout << "\nNo solution exists.";
    }

    return 0;
}

/*
---------------- SAMPLE INPUT ----------------
Enter number of vertices: 4

Enter adjacency matrix:
0 1 1 1
1 0 1 0
1 1 0 1
1 0 1 0

Enter number of colors: 3

---------------- SAMPLE OUTPUT ----------------
Solution exists:
Vertex 0 -> Color 1
Vertex 1 -> Color 2
Vertex 2 -> Color 3
Vertex 3 -> Color 2

---------------------------------------------

Problem Description:
Color a graph such that no two adjacent vertices have the same color using backtracking.
*/