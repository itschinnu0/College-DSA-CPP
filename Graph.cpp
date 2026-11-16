#include <iostream>
#include <queue>
using namespace std;

struct Graph
{
    int a[10][10];
    int visited[10];
    int n;
};

class Traversal
{
public:

    void DFS(Graph &g, int v)
    {
        cout << v << " ";
        g.visited[v] = 1;

        for (int i = 0; i < g.n; i++)
        {
            if (g.a[v][i] == 1 && g.visited[i] == 0)
            {
                DFS(g, i);
            }
        }
    }

    void BFS(Graph &g, int start)
    {
        queue<int> q;

        g.visited[start] = 1;
        q.push(start);

        while (!q.empty())
        {
            int v = q.front();
            q.pop();

            cout << v << " ";

            for (int i = 0; i < g.n; i++)
            {
                if (g.a[v][i] == 1 && g.visited[i] == 0)
                {
                    g.visited[i] = 1;
                    q.push(i);
                }
            }
        }
    }
};

int main()
{
    Graph g;
    Traversal t;
    int start, choice;

    cout << "Enter number of vertices: ";
    cin >> g.n;

    cout << "Enter adjacency matrix:\n";

    for (int i = 0; i < g.n; i++)
    {
        for (int j = 0; j < g.n; j++)
        {
            cin >> g.a[i][j];
        }
    }

    cout << "Enter starting vertex (0 to " << g.n - 1 << "): ";
    cin >> start;

    cout << "\n1. DFS";
    cout << "\n2. BFS";
    cout << "\nEnter choice: ";
    cin >> choice;

    for (int i = 0; i < g.n; i++)
        g.visited[i] = 0;

    if (choice == 1)
    {
        cout << "DFS Traversal: ";
        t.DFS(g, start);
    }
    else if (choice == 2)
    {
        cout << "BFS Traversal: ";
        t.BFS(g, start);
    }
    else
    {
        cout << "Invalid choice";
    }

    return 0;
}
