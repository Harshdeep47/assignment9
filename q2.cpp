#include <iostream> #include <vector>
 
#include <queue> using namespace std;

void BFS(int start, vector<vector<int>>& adj) { vector<bool> visited(adj.size(), false); queue<int> q;

visited[start] = true; q.push(start);

cout << "BFS: "; while (!q.empty()) {
int u = q.front(); q.pop(); cout << u << " ";

for (int v : adj[u]) {
if (!visited[v]) { visited[v] = true; q.push(v);
}
}
}
}


int main() { vector<vector<int>> adj = {
{1, 2}, // 0
{0, 3}, // 1
{0, 3}, // 2
{1, 2}  // 3
};
 
BFS(0, adj);
}
