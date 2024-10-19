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
void insertNode(Node *head, int value);
bool deleteNode(Node *head, int pos);

int main()
{
    int n;
    cin >> n;
    if (n < 0) return -1;

    // creating empty node
    Node *head = createNode(0);

    // inserting
    int value = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> value;
        insertNode(head, value);
    }

    // deleting number in list
    int delNum = 0;
    cin >> delNum;
    if (!deleteNode(head, delNum))
    {
        cout << "错误：删除位置不合法。" << endl;
    }

    // printing
    printNode(head);

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
    int count = 0;
    Node *temp = head->next;

    while (temp)
    {
        count++;
        temp = temp->next;
    }
    cout << count << ":";

    if (0 == count)
    {
        return;
    }
    temp = head->next;
    while (temp->next)
    {
        cout << " " << temp->data;
        temp = temp->next;
    }
    cout << " " << temp->data;
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

void insertNode(Node *head, int value)
{
    Node *temp = (Node*)malloc(sizeof(Node));
    if (temp)
    {
        Node *temp2 = head->next;
        head->next = temp;
        temp->next = temp2;
        temp->data = value;
    }
}

bool deleteNode(Node *head, int pos)
{
    Node *temp1 = head;
    if (pos >= 1)
    {
        int i = 0;
        while(i != pos-1 && temp1->next != nullptr)
        {
            temp1 = temp1->next;
            i++;
        }
        if (temp1->next)
        {
            Node *temp2 = temp1->next;
            temp1->next = temp2->next;
            free(temp2);
            return true;
        }
    }

    return false;
}