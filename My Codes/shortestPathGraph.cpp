#include <bits/stdc++.h>

using namespace std;

int getMinVertex(vector<int> &dist, set<int> &sptSet) {
    int minWeight = INT_MAX, minVertex;
    for (int v = 0; v < dist.size(); v++) {
        if (sptSet.find(v) == sptSet.end() && dist[v] <= minWeight) {
            minWeight = dist[v];
            minVertex = v;
        }
    }

    return minVertex;
}

void shortestPath(int start, vector<vector<int>> &graph, vector<int> &dist) {
    dist[start] = 0;
    set<int> sptSet;

    for (int x = 0; x < dist.size() - 1; x++) {
        int src = getMinVertex(dist, sptSet);
        sptSet.insert(src);

        for (int dest = 0; dest < dist.size(); dest++) {
            if (graph[src][dest] != INT_MAX && sptSet.find(dest) == sptSet.end()) {
                dist[dest] = min(dist[src] + graph[src][dest], dist[dest]);
            }
        }
    }
}

int main() {
    int vertex, edges;
    cin >> vertex >> edges;
    vector<vector<int>> graph(vertex, vector<int>(vertex, INT_MAX));

    for (int i = 0; i < edges; ++i) {
        int st, end, weight;
        cin >> st >> end >> weight;
        graph[st][end] = weight;
    }

    int startVertex;
    cin >> startVertex;

    vector<int> dist(vertex, INT_MAX);
    shortestPath(startVertex, graph, dist);
    for (int i=0; i<vertex; i++) {
        cout << "Shortest path from " << startVertex << " to " << i << " is: " << dist[i] << endl;
    }
}