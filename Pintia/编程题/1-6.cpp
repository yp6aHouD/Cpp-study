#include <iostream>

using namespace std;

int MultOfAandB1toNSum(int a, int b);

int main()
{
    int x, y;
    cin >> x >> y;
    cout << MultOfAandB1toNSum(x, y);
}

int MultOfAandB1toNSum(int a, int b)
{
    if (a < 1 || b < 1) return 0;
    int aSum = 0, bSum = 0;

    for (int i = 1; i <= a; i++)
    {
        aSum += i;
    }

    for (int i = 1; i <= b; i++)
    {
        bSum += i;
    }

    return aSum * bSum;
}