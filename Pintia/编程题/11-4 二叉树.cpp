#include <iostream>

using namespace std;

struct TreeNode
{
    int key;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : key(x), left(nullptr), right(nullptr) {}
};

class BST
{
public:
    BST() : root(nullptr) {}

    void insert(int key)
    {
        root = insert(root, key);
    }

    bool search(int key)
    {
        return search(root, key);
    }

    void remove(int key)
    {
        if (!search(key))
        {
            cout << "错误：" << key << "不在树中。" << endl;
        }
        else
        {
            root = remove(root, key);
        }
    }

private:
    TreeNode* root;

    TreeNode* insert(TreeNode* node, int key)
    {
        if (node == nullptr)
        {
            return new TreeNode(key);
        }
        if (key < node->key)
        {
            node->left = insert(node->left, key);
        }
        else if (key > node->key)
        {
            node->right = insert(node->right, key);
        }
        return node;
    }

    bool search(TreeNode* node, int key)
    {
        if (node == nullptr)
        {
            return false;
        }
        if (key == node->key)
        {
            return true;
        }
        else if (key < node->key)
        {
            return search(node->left, key);
        }
        else
        {
            return search(node->right, key);
        }
    }

    TreeNode* remove(TreeNode* node, int key)
    {
        if (node == nullptr)
        {
            return nullptr;
        }
        if (key < node->key)
        {
            node->left = remove(node->left, key);
        }
        else if (key > node->key)
        {
            node->right = remove(node->right, key);
        }
        else
        {
            if (node->left == nullptr)
            {
                TreeNode* rightNode = node->right;
                delete node;
                return rightNode;
            }
            else if (node->right == nullptr)
            {
                TreeNode* leftNode = node->left;
                delete node;
                return leftNode;
            }
            TreeNode* minNode = findMin(node->right);
            node->key = minNode->key;
            node->right = remove(node->right, minNode->key);
        }
        return node;
    }

    TreeNode* findMin(TreeNode* node)
    {
        while (node->left != nullptr)
        {
            node = node->left;
        }
        return node;
    }
};

int main()
{
    int n;
    cin >> n;
    BST tree;
    for (int i = 0; i < n; ++i)
    {
        int key;
        cin >> key;
        tree.insert(key);
    }

    int testKey;
    cin >> testKey;

    if (tree.search(testKey))
    {
        cout << "Found key = " << testKey << endl;
    }
    else
    {
        cout << "NotFound." << endl;
    }

    tree.remove(testKey);

    if (tree.search(testKey))
    {
        cout << "Found key = " << testKey;
    }
    else
    {
        cout << "NotFound.";
    }

    return 0;
}