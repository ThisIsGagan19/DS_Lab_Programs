#include <iostream>
#include <vector>
using namespace std;


class Graph {
public:
    int numVertices;
    vector<vector<int>> adjList;

    Graph(int vertices) {
        numVertices = vertices;
        adjList.resize(vertices);
    }


    void addEdge(int src, int dest) {
        adjList[src].push_back(dest);
        adjList[dest].push_back(src);
    }


    void DFSUtil(int vertex, vector<bool>& visited) {
        visited[vertex] = true;
        cout << vertex << " ";

        for (int neighbor : adjList[vertex]) {
            if (!visited[neighbor]) {
                DFSUtil(neighbor, visited);
            }
        }
    }


    void DFS(int startVertex) {
        vector<bool> visited(numVertices, false);
        DFSUtil(startVertex, visited);
    }
};

int main() {
    int numVertices = 7;
    Graph graph(numVertices);


    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 5);
    graph.addEdge(2, 6);


    cout << "Depth-First Search (DFS) starting from vertex 0: ";
    graph.DFS(0);
    cout << endl;

    return 0;
}
