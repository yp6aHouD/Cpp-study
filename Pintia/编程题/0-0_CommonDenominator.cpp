#include <iostream>

using namespace std;

int CommonDenominator(int a, int b);

int main()
{
    int x, y;
    cin >> x >> y;
    cout << CommonDenominator(x, y) << endl;
}

int CommonDenominator(int a, int b)
{
    if (a == 0 || b == 0) return 0;
    if (a % b == 0) return b;
    a %= b;
    return CommonDenominator(b, a);
}
