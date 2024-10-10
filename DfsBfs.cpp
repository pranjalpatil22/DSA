#include <iostream>
#include <vector>
#include <queue>
using namespace std;


void dfs(int v, vector<bool>& visited, vector<int> adj[], vector<int>& result)
{
    visited[v] = true;
    result.push_back(v);


    for (int i : adj[v])
    {
        if (!visited[i])
        {
            dfs(i, visited, adj, result);
        }
    }
}

vector<int> dfs(int n, vector<int> adj[])
{
    vector<bool> visited(n, false);
    vector<int> result;


    dfs(0, visited, adj, result);

    return result;
}

vector<int> bfs(int V, vector<int> adj[]) {
    vector<int> result;
    vector<bool> visited(V, false);
    queue<int> q;

    visited[0] = true;
    q.push(0);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        result.push_back(node);


        for (int i : adj[node])
        {
            if (!visited[i])
            {
                visited[i] = true;
                q.push(i);
            }
        }
    }

    return result;
}

int main()
{
    int n = 5;
    vector<int> adj[n] = {{2, 3, 1}, {0}, {0, 4}, {0}, {2}};
    int choice;
    cout << "ENter 1 for dfs \n2 for bfs" << endl;
    cin >> choice;
    if(choice == 1)
    {
        vector<int> dfsResult = dfs(n, adj);

        cout << "DFS Traversal: ";
        for (int i : dfsResult)
        {
            cout << i << " ";
        }

    }
    else
    {

        vector<int> bfsResult = bfs(n, adj);

        cout << "BFS Traversal: ";
        for (int i : bfsResult)
        {
            cout << i << " ";
        }
    }

    return 0;
}
