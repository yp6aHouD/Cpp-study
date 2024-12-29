#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void printOptimalParens(vector<vector<int>>& s, int i, int j)
{
    if (i == j)
    {
        cout << "M" << i;
    }
    else
    {
        cout << "(";
        printOptimalParens(s, i, s[i][j]);
        cout << ")x(";
        printOptimalParens(s, s[i][j] + 1, j);
        cout << ")";
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> p(n + 1);
    for (int i = 0; i <= n; ++i)
    {
        cin >> p[i];
    }

    vector<vector<int>> m(n + 1, vector<int>(n + 1, 0));
    vector<vector<int>> s(n + 1, vector<int>(n + 1, 0));

    for (int l = 2; l <= n; ++l)
    {
        for (int i = 1; i <= n - l + 1; ++i)
        {
            int j = i + l - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; ++k)
            {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    printOptimalParens(s, 1, n);
    cout << endl;
    cout << m[1][n];

    return 0;
}