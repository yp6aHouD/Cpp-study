#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

// 定义二叉树节点结构
struct BinaryTree
{
    char key;
    BinaryTree *left;
    BinaryTree *right;
};

// 创建新节点
BinaryTree* createNode(char key)
{
    BinaryTree* newNode = new BinaryTree();
    newNode->key = key;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

// 根据前序和中序遍历序列重建二叉树
BinaryTree* buildTree(const string& preorder, int preStart, int preEnd, 
                      const string& inorder, int inStart, int inEnd, 
                      unordered_map<char, int>& inMap) 
{
    if (preStart > preEnd || inStart > inEnd)
    {
        return nullptr;
    }

    char rootKey = preorder[preStart];
    BinaryTree* root = createNode(rootKey);
    int inRoot = inMap[rootKey];
    int numsLeft = inRoot - inStart;

    root->left = buildTree(preorder, preStart + 1, preStart + numsLeft, inorder, inStart, inRoot - 1, inMap);
    root->right = buildTree(preorder, preStart + numsLeft + 1, preEnd, inorder, inRoot + 1, inEnd, inMap);

    return root;
}

// 计算二叉树的高度
int calculateHeight(BinaryTree* root) {
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

int main() 
{
    int n;
    cin >> n;

    string preorder, inorder;
    cin >> preorder >> inorder;

    unordered_map<char, int> inMap;
    for (int i = 0; i < n; i++)
    {
        inMap[inorder[i]] = i;
    }

    BinaryTree* root = buildTree(preorder, 0, n - 1, inorder, 0, n - 1, inMap);

    int height = calculateHeight(root);
    cout << height << endl;

    return 0;
}