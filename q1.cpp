#include <iostream> #include <vector> using namespace std;

class Graph { int V;
vector<vector<int>> adjMatrix; vector<vector<int>> adjList;

public:
Graph(int V) : V(V) {
adjMatrix.assign(V, vector<int>(V, 0)); adjList.assign(V, {});
}


void addEdge(int u, int v) { adjMatrix[u][v] = 1;
adjMatrix[v][u] = 1;


adjList[u].push_back(v); adjList[v].push_back(u);
}


void printAdjMatrix() {
cout << "Adjacency Matrix:\n"; for (int i = 0; i < V; i++) {
for (int j = 0; j < V; j++)
cout << adjMatrix[i][j] << " ";
 
cout << endl;
}
}


void printAdjList() {
cout << "Adjacency List:\n"; for (int i = 0; i < V; i++) {
cout << i << ": ";
for (int v : adjList[i]) cout << v << " "; cout << endl;
}
}


int degree(int v) {
return adjList[v].size();
}


void adjacentVertices(int v) {
cout << "Adjacent vertices of " << v << ": "; for (int x : adjList[v]) cout << x << " ";
cout << endl;
}


int numberOfEdges() { int cnt = 0;
for (int i = 0; i < V; i++) cnt += adjList[i].size();
return cnt / 2;
}
};
 
int main() { Graph g(5);

g.addEdge(0, 1);
g.addEdge(0, 4);
g.addEdge(1, 2);
g.addEdge(1, 3);


g.printAdjMatrix(); g.printAdjList();

cout << "Degree of 1: " << g.degree(1) << endl; g.adjacentVertices(1);
cout << "Number of edges: " << g.numberOfEdges() << endl;
}
