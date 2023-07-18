#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct Edge {
    int destination, weight;
};

void Dijkstra(vector<vector<Edge>>& graph, int V, int source) {
    vector<int> distance(V, INT_MAX);
    distance[source] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (Edge& edge : graph[u]) {
            int v = edge.destination;
            int wt = edge.weight;
            if (distance[u] != INT_MAX && distance[u] + wt < distance[v]) {
                distance[v] = distance[u] + wt;
                pq.push({distance[v], v});
            }
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
    E = 7;
    source = 0;

    vector<vector<Edge>> graph(V);

    // Initialize the graph
    graph[0].push_back({1, 2});
    graph[0].push_back({2, 4});
    graph[1].push_back({2, 1});
    graph[1].push_back({3, 7});
    graph[2].push_back({3, 3});
    graph[2].push_back({4, 5});
    graph[3].push_back({4, 2});

    Dijkstra(graph, V, source);

    return 0;
}
