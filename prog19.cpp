
//cycle detection
#include <iostream>
#include <vector>

using namespace std;

class Graph {
public:
    int vertices;
    vector<int> parent;

    Graph(int V) : vertices(V), parent(V) {
        for (int i = 0; i < V; ++i) {
            parent[i] = i;
        }
    }

    int find(int v) {
        if (parent[v] == v)
            return v;
        return find(parent[v]);
    }

    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        parent[rootX] = rootY;
    }

    bool isCyclic() {
        for (int u = 0; u < vertices; ++u) {
            for (int v : adjacencyList[u]) {
                int rootU = find(u);
                int rootV = find(v);

                if (rootU == rootV)
                    return true;

                unionSets(rootU, rootV);
            }
        }

        return false;
    }

    void addEdge(int u, int v) {
        adjacencyList[u].push_back(v);
        adjacencyList[v].push_back(u);
    }

private:
    vector<vector<int>> adjacencyList;
};

int main() {
    // Create a graph
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(1, 3);
    g.addEdge(3, 4);

    // Check for cycles
    if (g.isCyclic()) {
        cout << "Graph contains a cycle.\n";
    } else {
        cout << "Graph does not contain a cycle.\n";
    }

    return 0;
}
