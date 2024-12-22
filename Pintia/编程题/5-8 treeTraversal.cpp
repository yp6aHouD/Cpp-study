#include <iostream>
#include <stack>
using namespace std;

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
    if (root == nullptr) {
        root = createNode(key);
    } else if (key < root->key) {
        insertData(root->left, key);
    } else {
        insertData(root->right, key);
    }
}

// 计算二叉树的高度
int calculateHeight(BinaryTree* root) 
{
    if (root == nullptr) 
    {
        return 0;
    } 
    else 
    {
        int leftHeight = calculateHeight(root->left);
        int rightHeight = calculateHeight(root->right);
        return max(leftHeight, rightHeight) + 1;
    }
}

void inOrderTraversal(BinaryTree* root) 
{
    stack<BinaryTree*> nodeStack;
    BinaryTree* current = root;

    while (current != nullptr || !nodeStack.empty()) 
    {
        while (current != nullptr) 
        {
            nodeStack.push(current);
            current = current->left;
        }

        current = nodeStack.top();
        nodeStack.pop();
        cout << current->key << endl;

        current = current->right;
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

    inOrderTraversal(tree);
    
    

    return 0;
}