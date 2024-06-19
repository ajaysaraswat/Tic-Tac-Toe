#include <iostream>
#include <queue>
#include <vector>
using namespace std;
// function to perform bfs on A graph
// represent using adjacency list

void bfs(vector<vector<int>> &adjList, int startNode, vector<bool> &visited)
{
    // crete a queue for bfs
    queue<int> q;
    // make the current node as visited and enqueue it
    visited[startNode] = true;

    q.push(startNode);
    // iterate over the queue
    while (!q.empty())
    {
        // dequeue the vertex and from queue and print it
        int currentNode = q.front();
        q.pop();
        cout << currentNode << " ";
        // get all the adjacent vertex of the dequeued vertex
        // current node if an adjacent is not visited
        // then make it visited and enqueue it
        for (auto neighbor : adjList[currentNode])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}
// function to add an edge to the graph
void addEdge(vector<vector<int>> &adjList, int u, int v)
{
    adjList[u].push_back(v);
}

// main function
int main()
{

    int vertices, edges;
    cout << "Enter the value of vertices";
    cin >> vertices;
    cin >> edges;
    vector<vector<int>> adjList(vertices);
    for (int i = 0; i < edges; i++)
    {
        // vetices u,v
        int u, v;
        cin >> u >> v;
        addEdge(adjList, u, v);
    }

    // mark all vertices as not visited
    vector<bool> visited(vertices, false);
    // perform bfs traversal starting from vertex 0
    cout << "BFS traversal is starting from vertex 0" << endl;
    bfs(adjList, 0, visited);
    return 0;
}