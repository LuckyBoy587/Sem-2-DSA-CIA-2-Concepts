#include <bits/stdc++.h>
using namespace std;

void bfs(int start, map<int, vector<int>>& graph) {
    set<int> visited;
    queue<int> q;

    visited.insert(start);
    q.push(start);

    while (!q.empty()) {
        int currVertex = q.front();
        cout << currVertex << ' ';
        q.pop();

        for (int dest: graph[currVertex]) {
            if (visited.find(dest) == visited.end()) {
                visited.insert(dest);
                q.push(dest);
            }
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
    int startVertex;
    cin >> startVertex;
    cout << "BFS Traversal: ";
    bfs(startVertex, graph);
}