#include <iostream>

/*
* 1.4 Ввести два числа и вычислить произведение
*/

int main()
{
    int v1 = 0; int v2 = 0;
    std::cout << "Input 2 numbers:" << std::endl;
    std::cin >> v1 >> v2;
    std::cout << v1 << " * " << v2 << " = " << v1 * v2 << std::endl;
    return 0; 
}