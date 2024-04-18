#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;

class Graph {
    int V; 
    list<int> *adj; 
public:
    Graph(int V); 
    void addEdge(int v, int w); 
    int greedyColoring(); 
};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
    adj[w].push_back(v); 
}

int Graph::greedyColoring() {
    vector<int> result(V, -1);
    vector<bool> available(V, false); 

    
    result[0] = 0;

    
    for (int u = 1; u < V; u++) {
       
        for (auto i : adj[u]) {
            if (result[i] != -1)
                available[result[i]] = true;
        }

      
        int cr;
        for (cr = 0; cr < V; cr++) {
            if (available[cr] == false)
                break;
        }

        result[u] = cr; 

        
        for (auto i : adj[u]) {
            if (result[i] != -1)
                available[result[i]] = false;
        }
    }

    
    int maxColor = *max_element(result.begin(), result.end()) + 1;

    return maxColor;
}

int main() {
    int V, E;
    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;

    Graph g(V);

    cout << "Enter the edges (format: vertex1 vertex2):" << endl;
    for (int i = 0; i < E; i++) {
        int v, w;
        cin >> v >> w;
        g.addEdge(v, w);
    }

    cout << "Minimum number of colors required: " << g.greedyColoring() << endl;

    return 0;
}
