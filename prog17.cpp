//prim
#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

struct Edge {
    int to;
    int weight;
    Edge(int t, int w) : to(t), weight(w) {}
};


struct Compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
        return a.second > b.second;
    }
};

// Prim's algorithm
vector<Edge> prim(vector<vector<Edge>>& graph, int source, int& total_weight) {
    int n = graph.size();
    vector<Edge> mst; 
    vector<bool> visited(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;

    visited[source] = true;
    for (const Edge& e : graph[source])
        pq.push({e.to, e.weight});

    
    while (!pq.empty()) {
        int u = pq.top().first;
        int w = pq.top().second;
        pq.pop();

        if (visited[u])
            continue;

        visited[u] = true;
        mst.push_back(Edge(u, w));
        total_weight += w;

        for (const Edge& e : graph[u]) {
            if (!visited[e.to])
                pq.push({e.to, e.weight});
        }
    }

    return mst;
}

int main() {
    vector<vector<Edge>> graph(6);

    // Adding edges to the graph
    graph[0].push_back(Edge(1, 2));
    graph[0].push_back(Edge(2, 5));
    graph[1].push_back(Edge(2, 1));
    graph[1].push_back(Edge(3, 7));
    graph[1].push_back(Edge(4, 6));
    graph[2].push_back(Edge(4, 3));
    graph[3].push_back(Edge(5, 9));
    graph[4].push_back(Edge(5, 4));

    int source = 0; 
    int total_weight = 0;

    
    vector<Edge> minimum_spanning_tree = prim(graph, source, total_weight);

    cout << "Edges of the minimum spanning tree:\n";
    for (const Edge& e : minimum_spanning_tree)
        cout << source << " - " << e.to << " (weight " << e.weight << ")\n";

 
    cout << "Total weight of the minimum spanning tree: " << total_weight << endl;

    return 0;
}
