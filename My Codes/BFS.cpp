#include <bits/stdc++.h>
using namespace std;

bool bfs(int start, map<int, vector<int>>& graph) {
    set<int> visited;
    queue<int> q;

    visited.insert(start);
    q.push(start);
    cout << start << ' ';

    while (!q.empty()) {
        int currVertex = q.front();
        cout << currVertex << ' ';
        q.pop();

        for (int dest: graph[currVertex]) {
            if (visited.find(dest) == visited.end()) {
                visited.insert(dest);
                q.push(dest);
            } else return true;
        }
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

    cout << "BFS Traversal: ";
    bfs(0, graph);
}