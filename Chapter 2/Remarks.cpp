#include <iostream>

int main()
{
    int *pi = nullptr;
    int sizeOfArray = 5;

    pi = (int*)malloc(sizeOfArray * sizeof(int));
    if (!pi)
    {
        std::cout << "Memory allocation failed";
        return 1;
    }

    pi[0] = 5;
    pi[1] = 10;
    pi[sizeOfArray - 1] = 15;

    for (int i = 0; i < sizeOfArray; i++)
    {
        if (sizeOfArray - 1 == i)
        {
            std::cout << "pi[" << sizeOfArray - 1 << "] = " 
                << pi[sizeOfArray - 1] << std::endl;
            return 0;
        }
        std::cout << "pi[" << i << "] = " << pi[i] << ", ";
    }

    return 0;
}