#include <iostream>

typedef struct Node
{
    int data;
    Node *next;
} Node;

int main()
{
    Node *head = new Node; // головной указатель, название
    Node *pointer; // указатель для опроса

    Node first; // первый элемент
    Node second; // второй элемент

    head = &first;
    pointer = head;

    first.data = 1;
    first.next = &second;
    second.data = 2;
    second.next = nullptr;

    while (pointer != nullptr)
    {
        std::cout << pointer->data << std::endl;
        pointer = pointer->next;
    }
    
    delete(head);


    return 0;
}