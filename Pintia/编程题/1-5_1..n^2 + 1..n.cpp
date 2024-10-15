#include <iostream>

using namespace std;

int SumOf1toNSquare(int a);

int main()
{
    int x;
    cin >> x;
    cout << SumOf1toNSquare(x);
}

int SumOf1toNSquare(int a)
{
    if (a == 0) return 0;
    
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i <= a * a; i++)
    {
        if (i <= a) sum1 += i;
        sum2 += i;
    }
    return sum1 + sum2;
}
