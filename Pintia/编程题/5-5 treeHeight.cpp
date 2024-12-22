#include <iostream>
using namespace std;

// 定义二叉树节点结构
struct BinaryTree
{
    int key;
    BinaryTree *left;
    BinaryTree *right;
};

// 创建新节点
BinaryTree* createNode(int key)
{
    BinaryTree* newNode = new BinaryTree();
    newNode->key = key;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

// 插入数据到二叉树
void insertData(BinaryTree* &root, int key)
{
    if (root == nullptr) 
    {
        root = createNode(key);
    } 
    else if (key < root->key) 
    {
        insertData(root->left, key);
    } 
    else 
    {
        insertData(root->right, key);
    }
}

// 计算二叉树的高度
int calculateHeight(BinaryTree* root) 
{
    if (root == nullptr) 
    {
        return 0;
    } else 
    {
        int leftHeight = calculateHeight(root->left);
        int rightHeight = calculateHeight(root->right);
        return max(leftHeight, rightHeight) + 1;
    }
}

int main() 
{
    int leftChild, rightChild, rootKey;
    cin >> leftChild >> rightChild >> rootKey;

    // 创建根节点
    BinaryTree* tree = createNode(rootKey);

    // 插入左孩子和右孩子
    insertData(tree->left, leftChild);
    insertData(tree->right, rightChild);

    // 计算并输出二叉树的高度
    int height = calculateHeight(tree);
    cout << height << endl;

    return 0;
}