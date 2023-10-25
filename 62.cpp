#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Define a class to represent a graph
class Graph {
public:
    int numVertices;
    vector<vector<int>> adjList;

    Graph(int vertices) {
        numVertices = vertices;
        adjList.resize(vertices);
    }

    // Function to add an undirected edge to the graph
    void addEdge(int src, int dest) {
        adjList[src].push_back(dest);
        adjList[dest].push_back(src);
    }

    // Function to perform BFS traversal
    void BFS(int startVertex) {
        vector<bool> visited(numVertices, false);
        queue<int> q;

        visited[startVertex] = true;
        q.push(startVertex);

        while (!q.empty()) {
            int currentVertex = q.front();
            cout << currentVertex << " ";
            q.pop();

            for (int neighbor : adjList[currentVertex]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }
};

int main() {
    int numVertices = 7;
    Graph graph(numVertices);

    // Add edges to the graph
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 5);
    graph.addEdge(2, 6);

    // Perform BFS traversal starting from vertex 0
    cout << "Breadth-First Search (BFS) starting from vertex 0: ";
    graph.BFS(0);
    cout << endl;

    return 0;
}
