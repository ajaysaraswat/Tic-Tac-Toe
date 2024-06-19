#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

unordered_map<int, list<int>> ad;
void addEdge(int u, int v, bool direction)
{
    ad[u].push_back(v);
    if (direction == 0)
    {
        ad[v].push_back(u);
    }
}
void printAdList()
{
    for (auto i : ad)
    {
        cout << i.first << "-->";
        for (auto j : i.second)
        {
            cout << j;
        }
        cout << endl;
    }
}

int main()
{
    int n, m;

    cout << "enter the no of nodes";
    cin >> n;
    cout << "enter no of edges";
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        addEdge(u, v, 0);
    }
    // print graph
    printAdList();
    return 0;
}