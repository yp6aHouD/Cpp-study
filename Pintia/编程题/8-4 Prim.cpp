#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Edge {
    int u, v, weight;
    bool operator<(const Edge& other) const {
        return weight > other.weight; // Для приоритетной очереди
    }
};

const int MAXN = 1000;
vector<Edge> adj[MAXN];
bool visited[MAXN];

int prim(int N, bool &unique) {
    priority_queue<Edge> pq;
    int mst_weight = 0;
    int edges_used = 0;
    unique = true;

    // Начинаем с вершины 1 (или 0, если нумерация с 0)
    visited[1] = true;
    for (const auto &edge : adj[1]) {
        pq.push(edge);
    }

    while (!pq.empty() && edges_used < N - 1) {
        Edge e = pq.top();
        pq.pop();

        if (visited[e.v]) continue;

        visited[e.v] = true;
        mst_weight += e.weight;
        edges_used++;

        for (const auto &next_edge : adj[e.v]) {
            if (!visited[next_edge.v]) {
                pq.push(next_edge);
            }
        }

        // Проверка на уникальность
        if (!pq.empty() && pq.top().weight == e.weight) {
            unique = false;
        }
    }

    if (edges_used != N - 1) {
        return -1; // MST не существует
    }

    return mst_weight;
}

int main() {
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; ++i) {
        int u, v, weight;
        cin >> u >> v >> weight;
        adj[u].push_back({u, v, weight});
        adj[v].push_back({v, u, weight});
    }

    fill(visited, visited + N + 1, false);

    bool unique;
    int mst_weight = prim(N, unique);

    if (mst_weight == -1) {
        cout << "No MST" << endl;
    } else {
        cout << mst_weight << endl;
        cout << (unique ? "Yes" : "No") << endl;
    }

    return 0;
}