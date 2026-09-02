// Name: Pranay Bhardwaj
// Roll Number: 25/DA/051
// Write a program to find the Connected Components of a graph using DFS.

#include <iostream>
using namespace std;

const int MAX = 100;

int graph[MAX][MAX];
bool visited[MAX];
int n;

void DFS(int vertex)
{
    visited[vertex] = true;
    cout << vertex << " ";

    for (int i = 0; i < n; i++)
    {
        if (graph[vertex][i] == 1 && !visited[i])
        {
            DFS(i);
        }
    }
}

int main()
{
    int edges, u, v;
    int components = 0;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> edges;

    for (int i = 0; i < n; i++)
    {
        visited[i] = false;

        for (int j = 0; j < n; j++)
        {
            graph[i][j] = 0;
        }
    }

    cout << "Enter edges (u v):" << endl;

    for (int i = 0; i < edges; i++)
    {
        cin >> u >> v;

        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    cout << "\nConnected Components:" << endl;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            components++;

            cout << "Component " << components << ": ";
            DFS(i);
            cout << endl;
        }
    }

    cout << "\nTotal Connected Components = " << components << endl;

    return 0;
}