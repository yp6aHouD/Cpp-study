#include <iostream>
#include <vector>
#include <limits> // std::numeric_limits
using namespace std;

vector<int> heap;

void siftUp(int index) 
{
    while (index > 0) 
    {
        int parent = (index - 1) / 2;
        if (heap[index] < heap[parent]) 
        {
            int temp = heap[index];
            heap[index] = heap[parent];
            heap[parent] = temp;
            index = parent;
        }
        else 
        {
            break;
        }
    }
}

void insert(int val) 
{
    heap.push_back(val);
    siftUp(heap.size() - 1);
}

vector<int> getPath(int index) 
{
    vector<int> path;
    while (index >= 0) 
    {
        if (index == 0)
        {
            path.push_back(heap[index]);
            break;
        }
        path.push_back(heap[index]);
        index = (index - 1) / 2;
    }
    return path;
}

int main() 
{
    int n, m;
    cin >> n >> m;

    if (n < 1 || m < 1)
    {
        return 1;
    }

    for (int i = 0; i < n; ++i) 
    {
        int val;
        cin >> val;
        insert(val);
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    for (int i = 0; i < m; ++i) 
    {
        int index;
        cin >> index;
        if (index <= 0 || index > heap.size()) 
        {
            continue;
        }
        vector<int> path = getPath(index - 1); // index starts from 1
        for (int j = 0; j < path.size(); ++j) 
        {
            if (j > 0) cout << " ";
            cout << path[j];
        }
        cout << endl;
    }

    return 0;
}