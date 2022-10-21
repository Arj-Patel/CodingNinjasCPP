#include <iostream>
#include <queue>

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

using namespace std;
int height(BinaryTreeNode<int> *root)
{

    if (root == NULL)
    {
        return 0;
    }

    int ans1 = height(root->left);
    int ans2 = height(root->right);

    return 1 + max(ans1, ans2);
}

bool isBalanced(BinaryTreeNode<int> *root)
{

    if (root == NULL)
    {
        return true;
    }

    bool rAns = isBalanced(root->right);
    bool lAns = isBalanced(root->left);

    int rH = height(root->right);
    int lH = height(root->left);

    if ((lH - rH <= 1 && lH - rH >= -1) && rAns && lAns)
    {
        return true;
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
    cout << (isBalanced(root) ? "true" : "false");
}