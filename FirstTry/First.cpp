#include <iostream>

int main()
{
    // endl == \n
    // << == "+" в строковых литералах
    // << для вывода, >> для ввода
    std::cout << "Hello, world!" << " How are you?" << std::endl;

    int v1 = 0, v2 = 0;

    std::cin >> v1 >> v2;
    std:: cout << "v1 = " << v1 << ", v2 = " << v2 << std::endl;

    return 0;
}