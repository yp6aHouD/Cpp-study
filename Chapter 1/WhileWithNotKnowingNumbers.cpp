#include <iostream>

/* 
* Reading numbers until EOF or reading error
* Press Ctrl + d to mark EOF at MAC OS (Ctrl+z on Win)
*/

int main()
{
    int value = 0, sum = 0;

    while (std::cin >> value)
        sum += value;

    std::cout << "Sum = " << sum << std::endl;
    return 0;
}