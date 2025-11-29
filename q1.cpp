#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;
public:
    Graph(int vertices): V(vertices), adj(vertices) {}
    void addEdge(int u, int v, bool directed = false) {
        adj[u].push_back(v);
        if (!directed) adj[v].push_back(u);
    }
    vector<int> bfs(int start) {
        vector<bool> visited(V, false);
        queue<int> q;
        vector<int> order;
        visited[start] = true;
        q.push(start);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            order.push_back(u);
            for (int v: adj[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        return order;
    }
};
int main() {
    int V = 7;
    Graph g(V);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    g.addEdge(2, 6);
    int start = 0;
    vector<int> res = g.bfs(start);
    for (int u: res) {
        cout << u << " ";
    }
    cout << "\n";
    return 0;
}
