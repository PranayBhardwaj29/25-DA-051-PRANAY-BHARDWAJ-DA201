// Name: Pranay Bhardwaj
// Roll Number: 25/DA/051
// Write a program to find the Minimum Spanning Tree of a weighted graph using Prims and Kruskal's algorithm.
#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int u, v, w;
};

class DSU
{
    vector<int> parent, rnk;

public:
    DSU(int n) : parent(n), rnk(n, 0)
    {
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x)
    {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }
    bool unite(int a, int b)
    {
        a = find(a);
        b = find(b);
        if (a == b)
            return false;
        if (rnk[a] < rnk[b])
            swap(a, b);
        parent[b] = a;
        if (rnk[a] == rnk[b])
            rnk[a]++;
        return true;
    }
};

void kruskal(int V, vector<Edge> edges)
{
    sort(edges.begin(), edges.end(),
         [](const Edge &a, const Edge &b)
         { return a.w < b.w; });

    DSU dsu(V);
    vector<Edge> mst;
    long long total = 0;

    for (auto &e : edges)
    {
        if (dsu.unite(e.u, e.v))
        {
            mst.push_back(e);
            total += e.w;
        }
    }

    cout << "\n--- Kruskal's MST ---\n";
    for (auto &e : mst)
        cout << e.u << " - " << e.v << " (w = " << e.w << ")\n";
    cout << "Total weight: " << total << "\n";
    if ((int)mst.size() != V - 1)
        cout << "Graph is disconnected; result is a spanning forest.\n";
}

void prim(int V, const vector<vector<pair<int, int>>> &adj)
{
    vector<bool> inMST(V, false);
    vector<int> key(V, INT_MAX), parent(V, -1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    key[0] = 0;
    pq.push({0, 0});
    long long total = 0;

    while (!pq.empty())
    {
        auto [w, u] = pq.top();
        pq.pop();
        if (inMST[u])
            continue;
        inMST[u] = true;
        total += w;

        for (auto [v, wt] : adj[u])
        {
            if (!inMST[v] && wt < key[v])
            {
                key[v] = wt;
                parent[v] = u;
                pq.push({wt, v});
            }
        }
    }

    cout << "\n--- Prim's MST ---\n";
    int count = 0;
    for (int v = 1; v < V; v++)
    {
        if (parent[v] != -1)
        {
            cout << parent[v] << " - " << v << " (w = " << key[v] << ")\n";
            count++;
        }
    }
    cout << "Total weight: " << total << "\n";
    if (count != V - 1)
        cout << "Graph is disconnected; result covers only the component of vertex 0.\n";
}

int main()
{
    int V, E;
    cout << "Enter vertices and edges: ";
    cin >> V >> E;

    vector<Edge> edges(E);
    vector<vector<pair<int, int>>> adj(V);

    cout << "Enter edges (u v w), 0-indexed:\n";
    for (int i = 0; i < E; i++)
    {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
        adj[edges[i].u].push_back({edges[i].v, edges[i].w});
        adj[edges[i].v].push_back({edges[i].u, edges[i].w});
    }

    prim(V, adj);
    kruskal(V, edges);
    return 0;
}