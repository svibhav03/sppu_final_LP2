#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

typedef pair<int, int> pii;

class Graph
{
private:
    int V;
    vector<vector<pii>> adj;

public:
    Graph(int v) : V(v), adj(v) {}

    void addEdge(int u, int v, int weight)
    {
        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight});
    }

    vector<int> dijkstraMST(int source)
    {
        vector<int> dist(V, INT_MAX);
        priority_queue<pii, vector<pii>, greater<pii>> minHeap;
        dist[source] = 0;
        minHeap.push({0, source});

        while (!minHeap.empty())
        {
            int u = minHeap.top().second;
            minHeap.pop();

            for (auto neighbour : adj[u])
            {
                int v = neighbour.first;
                int weight = neighbour.second;

                if (dist[u] + weight < dist[v])
                {
                    dist[v] = dist[u] + weight;
                    minHeap.push({dist[v], v});
                }
            }
        }
        return dist;
    }
};

int main()
{
    int V = 6; // Number of vertices
    Graph g(V);

    // Adding edges to the graph (u, v, weight)
    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 2);
    g.addEdge(2, 3, 4);
    g.addEdge(3, 4, 2);
    g.addEdge(4, 5, 6);

    int source = 0; // Source vertex

    // Run Dijkstra's algorithm from the source vertex
    vector<int> shortestDistances = g.dijkstraMST(source);

    // Print shortest distances from the source vertex
    cout << "Shortest distances from source vertex " << source << ":\n";
    for (int i = 0; i < V; ++i)
    {
        cout << "Vertex " << i << ": " << shortestDistances[i] << "\n";
    }

    return 0;
}