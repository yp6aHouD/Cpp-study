#include <iostream>

using namespace std;

typedef struct Node
{
    int data;
    Node *next;
} Node;

Node* createNode(int n);
void printNode(Node *head);
Node* searchNode(Node *head, int value);

int main()
{
    int n, searchValue;
    cin >> n;
    if (n < 0) return -1;

    Node *head = createNode(n);
    cin >> searchValue;

    Node* result = searchNode(head, searchValue);
    if (result) 
    {
        cout << result->data;
    } 
    else 
    {
        cout << searchValue << " 未找到。";
    }

    Node *current = head;
    while (current)
    {
        Node *next = current->next;
        free(current);
        current = next;
    }

    return 0;
}

Node* createNode(int n)
{
    Node *head = (Node*)malloc(sizeof(Node));
    if (!head) return NULL;
    Node *temp1 = head;

    for (int i = 0; i < n; i++)
    {
        Node *temp2 = (Node*)malloc(sizeof(Node));
        if (temp2)
        {
            cin >> temp2->data;
            temp1->next = temp2;
            temp1 = temp1->next; 
        }
    }

    return head;
}

void printNode(Node *head)
{
    if (head == NULL) return;
    Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
        cout << temp->data << " ";
    }
}

Node* searchNode(Node *head, int value)
{
    if (!head) return nullptr;

    Node *temp = head;

    while (temp->next)
    {
        temp = temp->next;
        if (temp->data == value)
        {
            return temp;
        }
    }
    return nullptr;
}