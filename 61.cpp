#include <iostream>
#include <vector>
using namespace std;


struct Edge {
    int destination;
    int weight;

    Edge(int dest, int w) : destination(dest), weight(w) {}
};


class Graph {
public:
    int numVertices;
    vector<vector<Edge>> adjList;

    Graph(int vertices) {
        numVertices = vertices;
        adjList.resize(vertices);
    }


    void addEdge(int src, int dest, int weight) {
        adjList[src].emplace_back(dest, weight);
        adjList[dest].emplace_back(src, weight);
    }


    void printGraph() {
        for (int i = 0; i < numVertices; ++i) {
            cout << "Vertex " << i << ": ";
            for (const Edge& edge : adjList[i]) {
                cout << "(" << edge.destination << ", " << edge.weight << ") ";
            }
            cout << endl;
        }
    }
};

int main() {
    int numVertices = 5;
    Graph graph(numVertices);


    graph.addEdge(0, 1, 2);
    graph.addEdge(0, 2, 4);
    graph.addEdge(1, 2, 1);
    graph.addEdge(1, 3, 7);
    graph.addEdge(2, 4, 3);
    graph.addEdge(3, 4, 5);


    cout << "Graph Representation (Adjacency List):" << endl;
    graph.printGraph();

    return 0;
}
