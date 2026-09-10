// Name: Pranay Bhardwaj
// Roll Number: 25/DA/051
// Write a program to identify the Cut Vertices (Articulation Points) in a graph.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Graph
{
    int V;
    vector<vector<int>> adj;
    vector<int> disc, low;
    vector<bool> visited, ap;
    int timer;

    void dfs(int u, int parent)
    {
        visited[u] = true;
        disc[u] = low[u] = timer++;
        int children = 0;

        for (int v : adj[u])
        {
            if (v == parent)
                continue;

            if (!visited[v])
            {
                children++;
                dfs(v, u);

                low[u] = min(low[u], low[v]);

                if (parent != -1 && low[v] >= disc[u])
                    ap[u] = true;
            }
            else
            {
                low[u] = min(low[u], disc[v]);
            }
        }

        if (parent == -1 && children > 1)
            ap[u] = true;
    }

public:
    Graph(int V)
    {
        this->V = V;
        adj.resize(V);
        disc.resize(V);
        low.resize(V);
        visited.resize(V, false);
        ap.resize(V, false);
        timer = 0;
    }

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void findArticulationPoints()
    {
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
                dfs(i, -1);
        }

        cout << "Articulation Points: ";

        bool found = false;

        for (int i = 0; i < V; i++)
        {
            if (ap[i])
            {
                cout << i << " ";
                found = true;
            }
        }

        if (!found)
            cout << "None";

        cout << endl;
    }
};

int main()
{
    int V, E;
    cin >> V >> E;

    Graph g(V);

    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    g.findArticulationPoints();

    return 0;
}