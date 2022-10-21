#include <iostream>
#include <queue>
#include <bits/stdc++.h>
using namespace std;

template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    ~BinaryTreeNode()
    {
        if (left)
            delete left;
        if (right)
            delete right;
    }
};

bool helper(BinaryTreeNode<int> *root, int min, int max)
{
    if (root == NULL)
    {
        return true;
    }

    if (root->data > max or root->data < min)
    {
        return false;
    }

    bool ans1 = helper(root->left, min, root->data - 1);
    bool ans2 = helper(root->right, root->data, max);
    return ans1 and ans2;
}
bool isBST(BinaryTreeNode<int> *root)
{
    bool ans = helper(root, INT_MIN, INT_MAX);
}

int largestBSTSubtree(BinaryTreeNode<int> *root)
{

    if (root == NULL)
    {
        return 0;
    }

    int ans1 = largestBSTSubtree(root->left);
    int ans2 = largestBSTSubtree(root->right);

    if (isBST(root))
    {
        return 1 + max(ans1, ans2);
    }
    else
    {
        return max(ans1, ans2);
    }
}

BinaryTreeNode<int> *takeInput()
{
    int rootData;

    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1)
        {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1)
        {
            BinaryTreeNode<int> *rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main()
{
    BinaryTreeNode<int> *root = takeInput();
    cout << largestBSTSubtree(root);
    delete root;
}