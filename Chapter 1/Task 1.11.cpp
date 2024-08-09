#include <iostream>

/*
* 1.11 напечатать все числа в диапазоне между
* введёнными пользователем числами
*/
int main()
{
    int num1 = 0, num2 = 0;
    std::cout << "Input 2 numbers: ";
    std::cin >> num1 >> num2;
    int min = num1 > num2 ? num2 : num1;
    int max = num1 > num2 ? num1 : num2;
    min++;

    while (min != max)
    {
        std::cout << min << " ";
        min++;
    }
    return 0;
}