#include <iostream>
#include <unordered_map>
#include <list>
#include <stack>
#include <vector>
using namespace std;
void dfs(int node, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adjList, vector<int> &component)
{
    component.push_back(node);
    visited[node] = true;
    // recursive call for every connected component k
    for (auto i : adjList[node])
    {
        if (!visited[i])
        {
            cout << i << " ";
            dfs(i, visited, adjList, component);
        }
    }
}

vector<vector<int>> depthfirstsearch(vector<vector<int>> &edges, int V, int U)
{

    unordered_map<int, list<int>> adjList;

    // preparing adjacency list
    for (int i = 0; i < V; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    vector<vector<int>> ans;
    unordered_map<int, bool> visited;

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            vector<int> component;
            dfs(i, visited, adjList, component);
            ans.push_back(component);
        }
    }
    return ans;
}

int main()
{
    int U = 5, V = 5;
    vector<vector<int>> edges;
    edges = {{0, 1}, {0, 2}, {0, 3}, {2, 3}, {2, 4}};
    depthfirstsearch(edges, U, V);
}
