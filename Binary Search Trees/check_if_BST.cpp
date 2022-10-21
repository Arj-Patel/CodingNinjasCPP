#include <iostream>
#include <queue>
#include <climits>
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
};

int maxHelper(BinaryTreeNode<int> *root)
{

    if (root == NULL)
    {
        return INT_MIN;
    }

    int ans1 = maxHelper(root->left);
    int ans2 = maxHelper(root->right);

    if (root->data > ans1 && root->data > ans2)
    {
        return root->data;
    }
    else
    {
        return max(ans1, ans2);
    }
}

int minHelper(BinaryTreeNode<int> *root)
{

    if (root == NULL)
    {
        return INT_MAX;
    }

    int ans1 = minHelper(root->left);
    int ans2 = minHelper(root->right);

    if (root->data < ans1 && root->data < ans2)
    {
        return root->data;
    }
    else
    {
        return min(ans1, ans2);
    }
}

bool isBST(BinaryTreeNode<int> *root)
{

    if (root == NULL)
    {
        return true;
    }

    int max = maxHelper(root->left);
    int min = minHelper(root->right);

    bool ans1 = isBST(root->left);
    bool ans2 = isBST(root->right);

    if (root->data > max && root->data <= min)
    {
        return ans1 && ans2;
    }
    else
    {
        return false;
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
    cout << (isBST(root) ? "true" : "false");
}