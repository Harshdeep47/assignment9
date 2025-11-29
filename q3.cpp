#include <iostream>
#include <vector>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;
    void dfsUtil(int v, vector<bool> &visited, vector<int> &order) {
        visited[v] = true;
        order.push_back(v);
        for (int u : adj[v]) {
            if (!visited[u]) {
                dfsUtil(u, visited, order);
            }
        }
    }
public:
    Graph(int vertices): V(vertices), adj(vertices) {}
    void addEdge(int v, int w, bool directed = false) {
        adj[v].push_back(w);
        if (!directed) adj[w].push_back(v);
    }
    vector<int> dfs(int start) {
        vector<bool> visited(V, false);
        vector<int> order;
        dfsUtil(start, visited, order);
        return order;
    }
};

int main() {
    int V = 5;
    Graph g(V);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    int start = 0;
    vector<int> res = g.dfs(start);
    for (int v : res) {
        cout << v << " ";
    }
    cout << "\n";
    return 0;
}
