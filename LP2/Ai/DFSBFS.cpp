#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

class Graph {
    int V; // Number of vertices

    // Pointer to an array containing adjacency lists
    vector<vector<int>> adj;

public:
    Graph(int V); // Constructor

    // Function to add an edge to the graph
    void addEdge(int v, int w);

    // DFS traversal of the vertices reachable from a given vertex
    void DFS(int v);

    // BFS traversal of the vertices reachable from a given vertex
    void BFS(int v);
};

Graph::Graph(int V) {
    this->V = V;
    adj.resize(V);
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w); // Add w to v’s list
    adj[w].push_back(v); // Add v to w’s list (for undirected graph)
}

void Graph::DFS(int v) {
    // Mark all the vertices as not visited
    vector<bool> visited(V, false);

    // Create a stack for DFS
    stack<int> stack;

    // Push the current source node
    stack.push(v);

    while (!stack.empty()) {
        // Pop a vertex from stack and print it
        v = stack.top();
        stack.pop();

        // Stack may contain the same vertex twice, so we need to check if it's visited
        if (!visited[v]) {
            cout << v << " ";
            visited[v] = true;

            // Get all adjacent vertices of the popped vertex
            // If an adjacent has not been visited, then push it to the stack
            for (auto i = adj[v].begin(); i != adj[v].end(); ++i) {
                if (!visited[*i]) {
                    stack.push(*i);
                }
            }
        }
    }
}

void Graph::BFS(int v) {
    // Mark all the vertices as not visited
    vector<bool> visited(V, false);

    // Create a queue for BFS
    queue<int> queue;

    // Mark the current node as visited and enqueue it
    visited[v] = true;
    queue.push(v);

    while (!queue.empty()) {
        // Dequeue a vertex from queue and print it
        v = queue.front();
        cout << v << " ";
        queue.pop();

        // Get all adjacent vertices of the dequeued vertex v. If an adjacent
        // has not been visited, then mark it visited and enqueue it
        for (auto i = adj[v].begin(); i != adj[v].end(); ++i) {
            if (!visited[*i]) {
                visited[*i] = true;
                queue.push(*i);
            }
        }
    }
}

int main() {
    Graph g(7); // Create a graph with 7 vertices

    // Add edges for the provided test case
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(1, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(2, 6);

    cout << "Depth First Search (DFS) starting from vertex 0:\n";
    g.DFS(0);
    cout << endl;

    cout << "Breadth First Search (BFS) starting from vertex 0:\n";
    g.BFS(0);
    cout << endl;

    return 0;
}
