#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <stack>

using namespace std;

const int MAXN = 500;
const int INF = INT_MAX;

int n, m, s, d;
int rescueTeams[MAXN];
int graph[MAXN][MAXN];
int dist[MAXN];
int maxRescue[MAXN];
int numPaths[MAXN];
bool visited[MAXN];
vector<int> pre[MAXN];

void Dijkstra(int s)
{
    fill(dist, dist + n, INF);
    fill(maxRescue, maxRescue + n, 0);
    fill(numPaths, numPaths + n, 0);
    fill(visited, visited + n, false);
    dist[s] = 0;
    maxRescue[s] = rescueTeams[s];
    numPaths[s] = 1;

    for (int i = 0; i < n; ++i)
    {
        int u = -1, minDist = INF;
        for (int j = 0; j < n; ++j)
        {
            if (!visited[j] && dist[j] < minDist)
            {
                u = j;
                minDist = dist[j];
            }
        }

        if (u == -1) break;
        visited[u] = true;

        for (int v = 0; v < n; ++v)
        {
            if (!visited[v] && graph[u][v] != INF)
            {
                if (dist[u] + graph[u][v] < dist[v])
                {
                    dist[v] = dist[u] + graph[u][v];
                    maxRescue[v] = maxRescue[u] + rescueTeams[v];
                    numPaths[v] = numPaths[u];
                    pre[v].clear();
                    pre[v].push_back(u);
                }
                else if (dist[u] + graph[u][v] == dist[v])
                {
                    if (maxRescue[u] + rescueTeams[v] > maxRescue[v])
                    {
                        maxRescue[v] = maxRescue[u] + rescueTeams[v];
                    }
                    numPaths[v] += numPaths[u];
                    pre[v].push_back(u);
                }
            }
        }
    }
}

void printPath(int v)
{
    stack<int> path;
    while (v != s)
    {
        path.push(v);
        v = pre[v][numPaths[v]-1];
    }
    path.push(s);
    while (!path.empty())
    {
        cout << path.top();
        path.pop();
        if (!path.empty())
        {
            cout << " ";
        }
    }
}

int main()
{
    cin >> n >> m >> s >> d;

    for (int i = 0; i < n; ++i)
    {
        cin >> rescueTeams[i];
    }

    fill(&graph[0][0], &graph[0][0] + MAXN * MAXN, INF);

    for (int i = 0; i < m; ++i)
    {
        int u, v, length;
        cin >> u >> v >> length;
        graph[u][v] = length;
        graph[v][u] = length;
    }

    Dijkstra(s);

    cout << numPaths[d] << " " << maxRescue[d] << endl;
    printPath(d);

    return 0;
}