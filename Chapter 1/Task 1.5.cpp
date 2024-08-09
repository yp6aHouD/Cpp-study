#include <iostream>

/*
* 1.5 Ввести два числа и вывести их произведение,
* При этом используя операторы вывода отдельно для каждой части
*/

int main()
{
    int v1 = 0; int v2 = 0;
    std::cout << "Input 2 numbers:" << std::endl;
    std::cin >> v1 >> v2;
    std::cout << v1 << " * ";
    std::cout << v2 << " = ";
    std::cout << v1 * v2 << std::endl;
    
    return 0;
}