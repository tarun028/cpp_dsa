#include <iostream>
#include <vector>

using namespace std;

struct Edge {
    int source, destination, weight;
};

void BellmanFord(vector<Edge>& edges, int V, int E, int source) {
    vector<int> distance(V, INT_MAX);
    distance[source] = 0;

    for (int i = 0; i < V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].source;
            int v = edges[j].destination;
            int wt = edges[j].weight;
            if (distance[u] != INT_MAX && distance[u] + wt < distance[v]) {
                distance[v] = distance[u] + wt;
            }
        }
    }

    // Check for negative-weight cycles
    for (int i = 0; i < E; i++) {
        int u = edges[i].source;
        int v = edges[i].destination;
        int wt = edges[i].weight;
        if (distance[u] != INT_MAX && distance[u] + wt < distance[v]) {
            cout << "Graph contains negative-weight cycle.\n";
            return;
        }
    }

    cout << "Shortest distances from source vertex to all vertices:\n";
    for (int i = 0; i < V; i++) {
        cout << "Vertex " << i << ": " << distance[i] << endl;
    }
}

int main() {
    int V, E, source;
    V = 5;
    E = 8;
    source = 0;

    vector<Edge> edges = {
        {0, 1, 2},
        {0, 2, 4},
        {1, 2, 1},
        {1, 3, 7},
        {2, 3, 3},
        {2, 4, 5},
        {3, 4, 2},
        {4, 3, -6}
    };

    BellmanFord(edges, V, E, source);

    return 0;
}
