#include <stdio.h>
#include <stdlib.h>

#define kMaxSize 100

typedef struct ArrNode *ArrPtr;
typedef int ElemSet;

struct ArrNode 
{
    ElemSet *data; /* 存储数据的数组；ElemSet是用户定义的数据类型 */
    int size;      /* 数组的大小 */
};

typedef struct ArrNode *ArrPtr;

bool DecrSeqInsert(ArrPtr array, ElemSet x);

int main(void)
{
    int i, n;
    ArrPtr array;
    ElemSet x;
    
    array = (ArrPtr)malloc(sizeof(struct ArrNode));
    scanf("%d", &n);
    array->size = n;
    array->data = (int *)malloc(sizeof(int) * kMaxSize);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &array->data[i]);
    }
    scanf("%d", &x);

    if (DecrSeqInsert(array, x) == false)
    {
        printf("Insertion failed.\n");
    }
    printf("%d", array->data[0]);

    for (i = 1; i < array->size; i++)
    {
        printf(" %d", array->data[i]);
    }
    printf("\n");
    printf("Array size = %d\n", array->size);
    
    return 0;
}

bool DecrSeqInsert(ArrPtr array, ElemSet x)
{
    if (array->size == 0) 
    {
        array->data[0] = x;
        array->size++;
        return true;
    }
    else if (array->size == kMaxSize) return false;
    
    int temp1, temp2;
    int i = 0;

    while (x < array->data[i] && i != array->size)
    {
        i++;
    }

    if (i == array->size)
    {
        array->data[i] = x;
        array->size++;
        return true;
    }
    if (x != array->data[i])
    {
        temp1 = array->data[i];
        array->data[i] = x;
        i++;

        while (i <= array->size)
        {
            temp2 = array->data[i];
            array->data[i] = temp1;
            temp1 = temp2;
            i++;
        }
        array->size++;
        return true;
    }

    return false;
    
}