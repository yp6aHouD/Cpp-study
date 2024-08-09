#include <iostream>

/*
* 1.9 Вывести сумму чисел от 50 до 100 включительно
*/

int main()
{
    int sum = 0, num = 50;

    while (num <= 100)
    {
        sum += num;
        num++;
    }   

    std::cout << "Sum from 50 to 100 inclusive is "
        << sum << std::endl;

    return 0;
}