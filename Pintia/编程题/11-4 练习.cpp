#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, p;
    cin >> n >> p;

    vector<int> hashTable(p, -1);
    vector<int> positions(n);

    for (int i = 0; i < n; ++i)
    {
        int key;
        cin >> key;
        int hash = key % p;
        int pos = hash;

        while (hashTable[pos] != -1)
        {
            pos = (pos + 1) % p;
        }

        hashTable[pos] = key;
        positions[i] = pos;
    }

    for (int i = 0; i < n; ++i)
    {
        if (i > 0)
        {
            cout << " ";
        }
        cout << positions[i];
    }

    return 0;
}