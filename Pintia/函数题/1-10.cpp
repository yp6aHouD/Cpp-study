#include <iostream>

#define kMaxSize 10
#define NotFound -1

typedef int ElemSet;
typedef int Position;  /* 整型下标，表示元素的位置 */
typedef struct ArrNode *ArrPtr;

struct ArrNode
{
    ElemSet *data; /* 存储数据的数组；ElemSet是用户定义的数据类型 */
    int size;      /* 数组的大小 */
};

Position BinarySearch(ArrPtr array, ElemSet x)
{
    if (array->data == nullptr) return NotFound;

    int low = 0;
    int up = array->size - 1;

    if (low == up && array->data[0] == x) return low;

    while (low <= up)
    {
        if (x < array->data[((up - low) / 2) + low])
        {
            up = ((up - low) / 2) + low - 1;
        }
        else if (x > array->data[(up - low) / 2 + low])
        {
            low = ((up - low) / 2) + low + 1;
        }
        else return (up - low) / 2 + low;
    }
    return NotFound;
}

int main(void)
{
    int i, n;
    ArrPtr array;
    ElemSet x;
    
    array = (ArrPtr)malloc(sizeof(struct ArrNode));
    scanf("%d", &n);
    array->size = n;
    array->data = (int *)malloc(sizeof(int)*array->size); 
    for (i=0; i<n; i++)
    {
        scanf("%d", &array->data[i]);
    }
    scanf("%d", &x);
    printf("%d\n", BinarySearch(array, x));
    return 0;
}