#include <iostream>
#include <sstream>
#include <string>
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

// 反序列化前序序列构建二叉树
BinaryTree* deserializePreOrder(string nodes[], int& index, int n)
{
    if (index >= n || nodes[index] == "#")
    {
        index++;
        return nullptr;
    }

    BinaryTree* root = createNode(stoi(nodes[index]));
    index++;
    root->left = deserializePreOrder(nodes, index, n);
    root->right = deserializePreOrder(nodes, index, n);
    return root;
}

// 前序遍历二叉树
void preOrderTraversal(BinaryTree* root)
{
    if (root == nullptr) return;
    cout << root->key << endl;
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(); // 忽略换行符

    string line;
    getline(cin, line);
    istringstream iss(line);
    string nodes[20]; // 使用固定大小的数组
    string node;
    int index = 0;

    while (iss >> node) {
        nodes[index++] = node;
    }

    index = 0;
    BinaryTree* root = deserializePreOrder(nodes, index, n);

    preOrderTraversal(root);

    return 0;
}