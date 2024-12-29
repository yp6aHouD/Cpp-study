#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAXN = 100;
const int INF = 1e9;

struct Edge
{
    int u, v, weight;
};

vector<Edge> adj[MAXN];
int inDegree[MAXN];
int earliest[MAXN];
int latest[MAXN];
vector<Edge> criticalEdges;

bool topologicalSort(int n, vector<int>& topoOrder)
{
    queue<int> q;

    for (int i = 0; i < n; ++i)
    {
        if (inDegree[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        topoOrder.push_back(u);

        for (const auto& edge : adj[u])
        {
            int v = edge.v;
            if (--inDegree[v] == 0)
            {
                q.push(v);
            }
        }
    }

    return topoOrder.size() == n;
}

void findCriticalPath(int n, const vector<int>& topoOrder)
{
    fill(earliest, earliest + n, 0);
    fill(latest, latest + n, INF);

    for (int u : topoOrder)
    {
        for (const auto& edge : adj[u])
        {
            int v = edge.v;
            earliest[v] = max(earliest[v], earliest[u] + edge.weight);
        }
    }

    latest[topoOrder.back()] = earliest[topoOrder.back()];

    for (int i = n - 1; i >= 0; --i)
    {
        int u = topoOrder[i];
        for (const auto& edge : adj[u])
        {
            int v = edge.v;
            latest[u] = min(latest[u], latest[v] - edge.weight);
        }
    }

    for (int u = 0; u < n; ++u)
    {
        for (const auto& edge : adj[u])
        {
            int v = edge.v;
            if (earliest[u] + edge.weight == earliest[v] &&
                latest[v] == earliest[v])
            {
                criticalEdges.push_back(edge);
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i)
    {
        int u, v, weight;
        cin >> u >> v >> weight;
        adj[u].push_back({u, v, weight});
        inDegree[v]++;
    }

    vector<int> topoOrder;
    bool hasTopoSort = topologicalSort(n, topoOrder);

    if (hasTopoSort) 
    {
        findCriticalPath(n, topoOrder);

        
        sort(criticalEdges.begin(), criticalEdges.end(), [](const Edge& a, const Edge& b) 
        {
            if (a.u != b.u) return a.u < b.u;
            return a.v < b.v;
        });

        for (const auto& edge : criticalEdges) 
        {
            cout << "<" << edge.u << ", " << edge.v << ">" << endl;
        }
        cout << "关键路径分析结果为 1";
    } 
    else 
    {
        cout << "关键路径分析结果为 0";
    }

    return 0;
}
