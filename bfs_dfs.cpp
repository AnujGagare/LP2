#include <bits/stdc++.h>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;

   public:
    Graph(int V) {
        this->V = V;
        adj = vector<vector<int>>(V);
    }

    void addEdge(int v, int w) {
        adj[v].push_back(w);
        adj[w].push_back(v);

    }

    void BFS(int s)
    {
        int level = 0;
        vector<bool> visited(adj.size(),false);
        queue<int> q;
        q.push(s);
        visited[s] = true;
        BFSRecursive(q,adj,visited,level);
    }

    void BFSRecursive(queue<int> &q, vector<vector<int>> &adj, vector<bool> &visited, int level)
    {
        if(q.empty())
        {
            return;
        }

        cout << "Level : " << level << " -> ";

        int size = q.size();
        for(int i = 0; i < size; i++)
        {
            int node = q.front();
            q.pop();
            cout << node << " ";

            for(auto neighbor : adj[node])
            {
                if(!visited[neighbor])
                {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        cout << endl;  // 🟢 Add this newline to separate levels

        BFSRecursive(q, adj, visited, level + 1);
    }


   

    void DFSrec(int s,vector<bool> &visited)
    {
        visited[s] = true;
        cout << s << " ";

        for(int i = 0; i < adj[s].size(); i++)
        {
            int neighbour = adj[s][i];
            if(!visited[neighbour])
            {
                DFSrec(neighbour,visited);
            }
        }
       
    }
};

int main()
{
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(0,3);
    g.addEdge(1,2);

    g.BFS(2);
    cout<<"\n";
    cout<<"\n";
    vector<bool>visited(4,false);
    g.DFSrec(3,visited);

    return 0;
}