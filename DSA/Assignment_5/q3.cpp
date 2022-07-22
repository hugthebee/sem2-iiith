#include <iostream>
#include <vector>

using namespace std;
typedef long long int ll;

void dfs(ll node, vector<ll> graph[], vector<ll> visited[])
{
    visited[node].push_back(1);

    // now iterate through the list of adjacent nodes of node
    for (int i = 0; i < graph[node].size(); i++)
    {
        if (visited[graph[node][i]].back() != 1)
        {
            dfs(graph[node][i], graph, visited);
        }
    }
}

int completeVisited(ll N, vector<ll> visited[])
{
    for(int i=0;i<N;i++)
    {
        if(visited[i+1].back() == 0)
        {
            return 0; //not completely visited
        }
    }
    return 1;
}

int tcompleteVisited(ll N, vector<ll> tvisited[])
{
    for(int i=0;i<N;i++)
    {
        if(tvisited[i+1].back() == 0)
        {
            return 0; //not completely visited
        }
    }
    return 1;
}

int main()
{
    ll N, M;
    cin >> N >> M;
    // N will be the size of the graph vector

    // we're making an array of N vectors of type ll
    vector<ll> graph[N + 2];  // zero indexed
    vector<ll> tgraph[N + 2]; // transpose graph
    vector<ll> visited[N+2];
    vector<ll> tvisited[N+2];

    ll u, v;
    for (int i = 0; i < M; i++)
    {
        cin >> u >> v;
        // we put v at the index 'u' of the graph
        graph[u].push_back(v);
        visited[u].push_back(0);

        // transpose graph will be the opposite
        graph[v].push_back(u);
        tvisited[v].push_back(0);
    }

    // building graphs is done
    dfs(u, graph, visited);

    // checking if graph has been completely visited during dfs -> if no then answer is directly NO
    if (completeVisited(N,visited) == 0)
    {
        cout << "N0\n";
    }
    else
    {
        // using the kosaraju's algo, we run dfs on the transpose of the graph to see if it is stringly connected
        dfs(u, tgraph, tvisited);

        if (tcompleteVisited(N,tvisited) == 0)
        {
            cout << "N0\n";
        }
        else
        {
            cout << "YES\n";
        }
    }
}