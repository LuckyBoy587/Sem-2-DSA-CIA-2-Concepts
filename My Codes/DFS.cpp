#include <bits/stdc++.h>
using namespace std;

void dfs(int start, map<int, vector<int>>& graph, set<int>& visited) {
    visited.insert(start);
    cout << start << ' ';

    for (int dest: graph[start]) {
        if (visited.find(dest) == visited.end()) {
            dfs(dest, graph, visited);
        }
    }
}

int main(){
    int vertex, edges;
    cin >> vertex >> edges;
    map<int, vector<int>> graph;
    for (int i = 0; i < edges; ++i) {
        int st, end;
        cin >> st >> end;
        graph[st].push_back(end);
        graph[end].push_back(st);
    }

    cout << "DFS Traversal: ";
    set<int> visited;
    int startVertex;
    cin >> startVertex;
    dfs(startVertex, graph, visited);
}