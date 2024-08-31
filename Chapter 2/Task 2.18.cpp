#include <iostream>

int main()
{
    int i; // variable (переменная, 变量)
    int *pi; // pointer (указатель， 指针)
    int &ri = i; // reference (ссылка， 链接)
    void *vpi; // void pointer (указатель на void, 指向void的指针)
    i = 10;
    std::cout << "i before change = "<< i << std::endl;

    pi = &i;
    vpi = pi;
    *pi = 20; 
    std::cout << "i after change using *pi = " << i << std::endl; // i = 20
    std::cout << "pi = " << pi << std::endl; // pi = address of i
    std::cout << "cout using *pi = " << *pi << std::endl; // access to i using *pi
    std::cout << "cout using vpi = " << *(int*)vpi << std::endl; // access to i using *vpi
    std::cout << "cout using ri = " << ri << std::endl; // access to i using ri

    return 0;
}