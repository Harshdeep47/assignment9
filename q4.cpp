#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
typedef pair<int,int> pii;
vector<int> dijkstra(int V, vector<vector<pii>>& adj, int src) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;
    pq.push({0, src});
    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (d > dist[u]) continue;
        for (auto &p : adj[u]) {
            int v = p.first;
            int w = p.second;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}
int main() {
    int V = 5;
    vector<vector<pii>> adj(V);
    adj[0].push_back({1, 4});
    adj[0].push_back({2, 8});
    adj[1].push_back({2, 3});
    adj[1].push_back({4, 6});
    adj[2].push_back({3, 2});
    adj[3].push_back({4, 10});
    int src = 0;
    vector<int> dist = dijkstra(V, adj, src);
    for (int i = 0; i < V; i++) {
        if (dist[i] == INT_MAX) cout << "INF ";
        else cout << dist[i] << " ";
    }
    cout << "\n";
    return 0;
}
