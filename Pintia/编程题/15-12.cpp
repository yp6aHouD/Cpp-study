#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Item
{
    double weight;
    double value;
    double ratio;
    int index;
};

bool compare(Item a, Item b)
{
    return a.ratio > b.ratio;
}

int main()
{
    int n;
    double W;
    cin >> n >> W;

    vector<Item> items(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> items[i].weight;
        items[i].index = i;
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> items[i].value;
        items[i].ratio = items[i].value / items[i].weight;
    }

    sort(items.begin(), items.end(), compare);

    double totalValue = 0.0;
    vector<double> fractions(n, 0.0);

    for (int i = 0; i < n; ++i)
    {
        if (W == 0)
        {
            break;
        }
        if (items[i].weight <= W)
        {
            W -= items[i].weight;
            totalValue += items[i].value;
            fractions[items[i].index] = 1.0;
        }
        else
        {
            totalValue += items[i].value * (W / items[i].weight);
            fractions[items[i].index] = W / items[i].weight;
            W = 0;
        }
    }

    cout << fixed << setprecision(2) << totalValue << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << fixed << setprecision(2) << fractions[i] << " ";
    }
    cout << endl;

    return 0;
}