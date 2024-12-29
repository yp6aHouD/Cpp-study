#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

bool CreateList(Node *&head)
{
    head = new Node;
    if (head == nullptr)
    {
        return false;
    }
    head->next = nullptr;
    return true;
}

bool Search(Node *&head, int key, Node *&pos)
{
    Node *p = head->next;
    while (p && p->data != key) {p = p->next;}
    if (p)
    {
        pos = p;
        return true;
    }
    return false;
}


bool InsertList(Node *&head, int pos, int key)
{
    Node *p = head;
    for (int i = 0; i < pos && p->next; i++) {p = p->next;}
    if (p)
    {
        Node *q = new Node;
        if (q)
        {
            q->data = key;
            q->next = p->next;
            p->next = q;
            return true;
        }
        else return false;
    }
    else
    {
        Node *q = new Node;
        if (q)
        {
            q->data = key;
            q->next = p->next;
            p->next = q;
            return true;
        }
        else return false;
    }
    return false;
}

int main()
{
    Node *head;
    int n[5] = {1, 2, 3, 4, 5};

    if (CreateList(head))
    {
        for (int i = 1; i <= 5; i++)
        {
            InsertList(head, i, n[i-1]);
        }
    }
    return 0;
}