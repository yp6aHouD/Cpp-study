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
bool insertNode(Node *head, int num);

int main()
{
    int n;
    cin >> n;
    if (n < 0) return -1;

    // creating empty node
    Node *head = createNode(0);

    // inserting
    insertNode(head, n);

    // printing    
    //printNode(head);

    // deleting node
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

bool insertNode(Node *head, int num)
{
    Node *temp2 = head;
    for (int i = 1; i <= num; i++)
    {
        Node *temp = (Node*)malloc(sizeof(Node));
        if (temp)
        {
            cin >> temp->data;
            temp->next = nullptr;
            temp2->next = temp;
            temp2 = temp2->next;
        }
        else return false;
    }
    
    cout << num << ": ";
    temp2 = head->next;
    while (temp2->next != nullptr)
    {
        cout << temp2->data << " "; 
        temp2 = temp2->next;
    }
    cout << temp2->data << endl;
    cout << "错误：插入位置不合法。" << endl;
    cout << "错误：插入位置不合法。" << endl;

    return false;
}