#include <iostream>

using namespace std;

typedef struct BinaryTree
{
    int data;
    BinaryTree* leftTree;
    BinaryTree* rightTree;
} BinaryTree;

BinaryTree* constructRoot(int data);
bool insertData(BinaryTree *root, int data);
int calculateHeight(BinaryTree *root);
void printTree(BinaryTree *root);
bool deleteData(BinaryTree *root, int data);
BinaryTree* searchData(BinaryTree *root, BinaryTree *prevPointer, int data);

int main()
{
    //cout << "Enter numbers of elements in tree: ";
    int elemNum = 3;
    //cin >> elemNum;
    
    //cout << "Enter elements in tree: ";
    int nums;
    cin >> nums;
    BinaryTree *tree = constructRoot(nums);
    BinaryTree *prevPointer = nullptr;


    for (int i = 1; i < elemNum; i++)
    {
        cin >> nums;
        insertData(tree, nums);
    }

    int height = calculateHeight(tree);
    cout << height;


    /* cout << "printTree: ";
    printTree(tree);
    cout << endl;
    
    cout << "Enter number to search: ";
    cin >> elemNum;

    cout << "Search result: ";
    BinaryTree *answer = searchData(tree, prevPointer, elemNum);
    if (answer == nullptr)
    {
        cout << "element " << elemNum << " not found" << endl;
    }
    else
    {
        cout << answer->data << endl;
    }

    cout << "Enter number to delete: ";
    cin >> elemNum;
    cout << endl;

    if (deleteData(tree, elemNum) != true)
    {
        cout << "Delete error" << endl;;
    }
    else printTree(tree);
 */
    return 0;
}

BinaryTree* constructRoot(int data)
{
    BinaryTree *root = (BinaryTree*)malloc(sizeof(BinaryTree));
    if (!root) return nullptr;
    root->data = data;
    root->leftTree = nullptr;
    root->rightTree = nullptr;
    return root;
}

void printTree(BinaryTree *root)
{
    if (root == nullptr) return;
    printTree(root->leftTree);
    cout << root->data << " ";
    printTree(root->rightTree);
}

bool insertData(BinaryTree *root, int data)
{
    BinaryTree *prevPointer = nullptr;
    if (searchData(root, prevPointer, data) == nullptr)
    {
        if (data < root->data)
        {
            if (root->leftTree) return insertData(root->leftTree, data);
            else
            {
                root->leftTree = (BinaryTree*)malloc(sizeof(BinaryTree));
                if (root->leftTree)
                {
                    root->leftTree->data = data;
                    return true;
                }
            }
        }
        else if (data > root->data)
        {
            if (root->rightTree) return insertData(root->rightTree, data);
            else
            {
                root->rightTree = (BinaryTree*)malloc(sizeof(BinaryTree));
                if (root->rightTree)
                root->rightTree->data = data;
                return true;
            }
        }
    }
    return false;
}

BinaryTree* searchData(BinaryTree *root, BinaryTree *prevPointer, int data)
{
    if (root != nullptr)
    {
        if (root->data == data)
        {
            prevPointer = nullptr;
            return root;
        }

        BinaryTree *leftAns = searchData(root->leftTree, prevPointer, data);
        BinaryTree *rightAns = searchData(root->rightTree, prevPointer, data);
        if (leftAns)
        {
            prevPointer = root;
            return leftAns;
        }
        if (rightAns)
        {
            prevPointer = root;
            return rightAns;
        }
    }
    return nullptr;
}

bool deleteData(BinaryTree *root, int data)
{
    BinaryTree *targetPtr;
    BinaryTree *prevPtr;
    targetPtr = searchData(root, prevPtr, data);
    if (targetPtr != nullptr)
    {
        if (nullptr == prevPtr)
        {
            // TODO: what if root is the deleting point
        }
        else
        {
            // if we're deleting leaves
            if (nullptr == targetPtr->leftTree && nullptr == targetPtr->rightTree)
            {
                if (prevPtr->leftTree == targetPtr)
                {
                    free(targetPtr);
                    prevPtr->leftTree = nullptr;
                    return true;
                }
                else
                {
                    free(targetPtr);
                    prevPtr->rightTree = nullptr;
                    return true;
                }
            }

            else // if we're deleting nodes
            {
                if (prevPtr->leftTree == targetPtr)
                {
                    if (!targetPtr->leftTree)
                    {
                        prevPtr->leftTree = targetPtr->rightTree;
                        free(targetPtr);
                        return true;
                    }
                    if (!targetPtr->rightTree)
                    {
                        prevPtr->leftTree = targetPtr->leftTree;
                        free(targetPtr);
                        return true;
                    }
                    BinaryTree *tempPtr = targetPtr->leftTree;
                    BinaryTree *secTemp = targetPtr->rightTree;
                    while (secTemp->leftTree != nullptr)
                    {
                        secTemp = secTemp->leftTree;
                    }
                    secTemp->leftTree = tempPtr;
                    prevPtr->leftTree = secTemp;
                    free(targetPtr);
                    return true;
                }
                else if (prevPtr->rightTree == targetPtr)
                {
                    if (!targetPtr->rightTree)
                    {
                        prevPtr->rightTree = targetPtr->leftTree;
                        free(targetPtr);
                        return true;
                    }
                    if (!targetPtr->leftTree)
                    {
                        prevPtr->rightTree = targetPtr->rightTree;
                        free(targetPtr);
                        return true;
                    }
                    BinaryTree *tempPtr = targetPtr->rightTree;
                    BinaryTree *secTemp = targetPtr->leftTree;
                    while (secTemp->rightTree != nullptr)
                    {
                        secTemp = secTemp->rightTree;
                    }
                    secTemp->rightTree = tempPtr;
                    prevPtr->rightTree = secTemp;
                    free(targetPtr);
                    return true;
                }
            }
        }
    }
    return false;
}

int calculateHeight(BinaryTree* root)
{
    if (root == nullptr) 
    {
        return 0;
    } 
    else 
    {
        int lHeight = calculateHeight(root->leftTree);
        int rHeight = calculateHeight(root->rightTree);
        return max(lHeight, rHeight) + 1;
    }
}