#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

double knapsack(int i, double W, const vector<double>& weights, const vector<double>& values, vector<vector<double>>& memo, vector<vector<int>>& keep)
{
    if (i == 0 || W == 0)
    {
        return 0;
    }

    if (memo[i][(int)W] != -1)
    {
        return memo[i][(int)W];
    }

    double withoutItem = knapsack(i - 1, W, weights, values, memo, keep);
    double withItem = 0;
    if (weights[i - 1] <= W)
    {
        withItem = values[i - 1] + knapsack(i - 1, W - weights[i - 1], weights, values, memo, keep);
    }

    if (withItem > withoutItem)
    {
        keep[i][(int)W] = 1;
        memo[i][(int)W] = withItem;
    }
    else
    {
        keep[i][(int)W] = 0;
        memo[i][(int)W] = withoutItem;
    }

    return memo[i][(int)W];
}

int main()
{
    int n;
    double W;
    cin >> n >> W;

    vector<double> weights(n);
    vector<double> values(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> weights[i];
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> values[i];
    }

    vector<vector<double>> memo(n + 1, vector<double>((int)W + 1, -1));
    vector<vector<int>> keep(n + 1, vector<int>((int)W + 1, 0));

    double maxValue = knapsack(n, W, weights, values, memo, keep);

    cout << fixed << setprecision(2) << maxValue << endl;

    vector<int> solution(n, 0);
    double remainingWeight = W;
    for (int i = n; i > 0; --i)
    {
        if (keep[i][(int)remainingWeight] == 1)
        {
            solution[i - 1] = 1;
            remainingWeight -= weights[i - 1];
        }
    }

    for (int i = 0; i < n; ++i)
    {
        cout << solution[i] << " ";
    }
    cout << endl;

    return 0;
}