#include <bits/stdc++.h>
using namespace std;

bool dfs(int start, map<int, vector<int>>& graph, set<int> visited) {
    visited.insert(start);
    cout << start << ' ';

    for (int dest: graph[start]) {
        if (visited.find(dest) == visited.end()) {
            if (dfs(dest, graph, visited)) return true;
        } else return true;
    }

    return false;
}

int main(){
    int vertex, edges;
    cin >> vertex >> edges;
    map<int, vector<int>> graph;
    for (int i = 0; i < edges; ++i) {
        int st, end;
        cin >> st >> end;
        graph[st].push_back(end);
    }

    cout << "DFS Traversal: ";
    dfs(0, graph, set<int>());
}