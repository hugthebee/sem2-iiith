#include <iostream>
#include <list>
#include <utility>
#include <vector>

using namespace std;
typedef long long int ll;

typedef struct s
{
    ll value;
    int visited;
    struct s *next;
} vertex;

int nodeExists(int size, vector<vertex> &graph, ll u)
{
    for (int i=0;i<size;i++)
    {
        if (graph[i].value == u)
        {
            return i; // the node already exists
        }
    }
    return -1;
}

void dfs(ll node, vector<vertex> &graph, int size)
{
    int index = nodeExists(size,graph, node);
    graph[index].visited = 1;
    int num;

    // now iterate through the list of adjacent nodes of node
    for (vertex *temp = graph[index].next; temp != NULL; temp->next)
    {
        num = nodeExists(size, graph, temp->value);
        if (graph[num].visited == 0)
        {
            dfs(graph[num].value, graph, size);
        }
    }
}

int completeVisited(int size, vector<vertex> &graph)
{
    for (int i=0;i<size;i++)
    {
        if (graph[i].visited != 1)
        {
            return 0; // the complete graph has not been visited
        }
    }

    return 1;
}

int main()
{
    // making an adjacency list to store all the values of the nodes and a pointer to the linked list of all the
    // we make a vector of a struct with value and pointer
    vector<vertex> graph;
    vector<vertex> tgraph;

    int size = 0;
    int tsize = 0;

    ll N, M, u, v;
    cin >> N >> M; // M is edges and N is number of nodes

    for (int i = 0; i < M; i++)
    {
        cin >> u >> v;
        int index = nodeExists(size, graph, u);
        int index1 = nodeExists(tsize, tgraph, v);
        if (index == -1)
        {
            vertex v1;
            v1.value = u;
            vertex *place = (vertex *)malloc(sizeof(vertex));
            v1.next = place;
            v1.visited = 0;

            place->value = v;
            place->next = NULL;
            place->visited = 0;

            graph.push_back(v1);
            size++;
        }
        else
        {
            vertex *temp;
            // the vertex already exists in the list and we just need to add v to the list
            for (temp = graph[index].next; temp != NULL; temp = temp->next)
            {
                // at the end of the loop, temp will be the last element in the list
            }
            vertex *v1;
            v1->value = v;
            vertex *place = (vertex *)malloc(sizeof(vertex));
            v1->next = NULL;
            v1->visited = 0;

            temp->next = v1;
        }

        //building the transpose graph
        if (index1 == -1)
        {
            vertex v1;
            v1.value = v;
            vertex *place = (vertex *)malloc(sizeof(vertex));
            v1.next = place;
            v1.visited = 0;

            place->value = u;
            place->next = NULL;
            place->visited = 0;

            tgraph.push_back(v1);
            tsize++;
        }
        else
        {
            vertex *temp;
            // the vertex already exists in the list and we just need to add v to the list
            for (temp = graph[index].next; temp != NULL; temp = temp->next)
            {
                // at the end of the loop, temp will be the last element in the list
            }
            vertex *v1;
            v1->value = u;
            vertex *place = (vertex *)malloc(sizeof(vertex));
            v1->next = NULL;
            v1->visited = 0;

            temp->next = v1;
        }
    }
    // the graph is done

    // now dfs'ing
    dfs(u, graph,size);

    // checking if graph has been completely visited during dfs -> if no then answer is directly NO
    int ans = completeVisited(size,graph);
    if (ans == 0)
    {
        // whole graph is not visited so print nO
        cout << "NO\n";
    }
    else
    {
        // using the kosaraju's algo, we run dfs on the transpose of the graph to see if it is stringly connected
        dfs(u,tgraph,tsize);
        ans = completeVisited(tsize,tgraph);
        if(ans == 0)
        {
            cout << "NO\n";
        }
        else
        {
            cout << "YES\n";
        }
    }
}