//kruskal algo
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

struct Edge {
    int from;
    int to;
    int weight;
    Edge(int f, int t, int w) : from(f), to(t), weight(w) {}
};

struct DisjointSets {
    vector<int> parent;
    DisjointSets(int n) {
        parent.resize(n);
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    int find(int u) {
        if (parent[u] != u)
            parent[u] = find(parent[u]);
        return parent[u];
    }

    void merge(int u, int v) {
        parent[find(u)] = find(v);
    }
};

bool compareEdges(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}

// Kruskal's algorithm
vector<Edge> kruskal(vector<Edge>& edges, int n, int& total_weight) {
    vector<Edge> mst; 
    DisjointSets ds(n);
    total_weight = 0;

    sort(edges.begin(), edges.end(), compareEdges);

    Edge min_edge(-1, -1, numeric_limits<int>::max());

    
    for (const Edge& e : edges) {
       
        if (ds.find(e.from) == ds.find(e.to))
            continue;

        mst.push_back(e);
        ds.merge(e.from, e.to);
        total_weight += e.weight;

      
        if (e.weight < min_edge.weight)
            min_edge = e;
    }

    cout << "Minimum weight edge in the MST: " << min_edge.from << " - " << min_edge.to << " (weight " << min_edge.weight << ")\n";

    return mst;
}

int main() {
    
    int n = 6; 
    vector<Edge> edges = {
        Edge(0, 1, 2),
        Edge(0, 2, 5),
        Edge(1, 2, 1),
        Edge(1, 3, 7),
        Edge(1, 4, 6),
        Edge(2, 4, 3),
        Edge(3, 5, 9),
        Edge(4, 5, 4)
    };

    int total_weight;
    vector<Edge> minimum_spanning_tree = kruskal(edges, n, total_weight);

    cout << "Edges of the minimum spanning tree:\n";
    for (const Edge& e : minimum_spanning_tree)
        cout << e.from << " - " << e.to << " (weight " << e.weight << ")\n";

    cout << "Total weight of the minimum spanning tree: " << total_weight << endl;

    return 0;
}