#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

const int MAXN = 100;

vector<int> adj[MAXN];
int inDegree[MAXN];
string vertices[MAXN];

bool topologicalSort(int n, vector<int>& result) {
    queue<int> q;
    for (int i = 0; i < n; ++i) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        result.push_back(u);

        for (int v : adj[u]) {
            if (--inDegree[v] == 0) {
                q.push(v);
            }
        }
    }

    return result.size() == n;
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        cin >> vertices[i];
    }

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        inDegree[v]++;
    }

    vector<int> result;
    bool hasTopoSort = topologicalSort(n, result);

    cout << "该图拓扑序存在性为 " << (hasTopoSort ? 1 : 0) << endl;
    if (hasTopoSort) {
        for (int i : result) {
            cout << vertices[i] << " ";
        }
        cout << endl;
    } else {
        cout << "这里输出什么都不重要" << endl;
    }

    return 0;
}