#include <iostream>
using namespace std;

class Graph
{
    int a[20][20];
    int visited[20];
    int n;

public:

    void create()
    {
        int edges, u, v, weight;

        cout << "Enter number of cities: ";
        cin >> n;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                a[i][j] = 0;
            }
            visited[i] = 0;
        }

        cout << "Enter number of flights: ";
        cin >> edges;

        for(int i = 0; i < edges; i++)
        {
            cout << "Enter source, destination and weight: ";
            cin >> u >> v >> weight;

            a[u][v] = weight;
            a[v][u] = weight;
        }
    }

    void display()
    {
        cout << "\nAdjacency Matrix:\n";

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }

    void DFS(int v)
    {
        visited[v] = 1;

        for(int i = 0; i < n; i++)
        {
            if(a[v][i] != 0 && visited[i] == 0)
            {
                DFS(i);
            }
        }
    }

    void connected()
    {
        DFS(0);

        for(int i = 0; i < n; i++)
        {
            if(visited[i] == 0)
            {
                cout << "\nGraph is not connected";
                return;
            }
        }

        cout << "\nGraph is connected";
    }
};

int main()
{
    Graph g;

    g.create();
    g.display();
    g.connected();

    return 0;
}
