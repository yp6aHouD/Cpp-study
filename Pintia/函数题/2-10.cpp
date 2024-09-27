#include <stdio.h>
#include <stdlib.h>

typedef int ElemSet;
typedef struct ListNode *Position; /* 指针即结点位置 */

struct ListNode
{
    ElemSet data;  /* 存储数据*/
    Position next; /* 线性表中下一个元素的位置 */
};

typedef struct HeadNode *List;
struct HeadNode
{
    Position head; /* 单链表头指针 */
    int length;    /* 表长 */
};

void Insert (List list, int i, ElemSet x);
void Remove (List list, int i);

int main(void)
{
    int i, n, x;
    Position p;
    List list;
    
    list = (List)malloc(sizeof(struct HeadNode));
    list->head = (Position)malloc(sizeof(struct ListNode)); /* 创建空头结点 */;
    list->head->next = NULL;
    list->length = 0;

    scanf("%d: ", &n);

    for (i = 1; i <= n; i++)
    {
        scanf("%d", &x);
        Insert(list, i, x);
    }
    scanf("%d", &i);

    if (scanf("%d", &x) != EOF)
    {
        Insert(list, i, x);
    }
    else
    {
        Remove(list, i);
    }

    printf("%d:", list->length);
    p = list->head->next;
    while (p != NULL)
    {
        printf(" %d", p->data);
        p = p->next;
    }
    return 0;
}

void Insert (List list, int i, ElemSet x)
{
    if (i <= 0)
    {
        printf("ERROR\n");
        return;
    }

    int j = 1;
    Position pInsert = list->head;
    
    while (pInsert->next != NULL && j < i)
    {
        pInsert = pInsert->next;
        j++;
    }

    if (j != i)
    {
        printf("ERROR\n");
        return;
    }
    
    if (pInsert->next == NULL) 
    {
        pInsert->next = (Position)malloc(sizeof(struct ListNode));
        if (pInsert->next)
        {
            pInsert = pInsert->next;
            pInsert->next = NULL;
            pInsert->data = x;
            list->length++;
        }
        else
        {
            printf("ERROR\n");
            return;
        }
    }
    else
    {
        Position temp = &(*pInsert->next);
        pInsert->next = (Position)malloc(sizeof(struct ListNode));
        if (pInsert->next)
        {
            pInsert->next->data = x;
            pInsert->next->next = temp;
            list->length++;
        }
        else 
        {
            printf("ERROR\n");
            return;
        }
    }
}

void Remove (List list, int i)
{
    if (i <= 0 || i > list->length)
    {
        printf("ERROR\n");
        return;
    }

    int j = 1;
    Position pRemove = list->head;
    
    while (pRemove->next != NULL && j < i)
    {
        pRemove = pRemove->next;
        j++;
    }

    Position temp = &(*pRemove->next);
    pRemove->next = pRemove->next->next;
    free(temp);
    list->length--;
}
