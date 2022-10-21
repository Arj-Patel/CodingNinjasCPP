#include <iostream>
#include <queue>
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

void printAtDepthK(BinaryTreeNode<int> *root, int k)
{

    if (root == NULL || k < 0)
    {
        return;
    }

    if (k == 0)
    {
        cout << root->data << endl;
    }

    printAtDepthK(root->left, k - 1);
    printAtDepthK(root->right, k - 1);
}

int helper(BinaryTreeNode<int> *root, int element, int k)
{

    if (root == NULL)
    {
        return -1;
    }

    if (root->data == element)
    {
        printAtDepthK(root, k);
        return 0;
    }

    int lDistance = helper(root->left, element, k);

    if (lDistance != -1)
    {
        if (lDistance + 1 == k)
        {
            cout << root->data << endl;
        }
        else
        {
            printAtDepthK(root->right, k - lDistance - 2);
        }
        return 1 + lDistance;
    }

    int rDistance = helper(root->right, element, k);

    if (rDistance != -1)
    {
        if (rDistance + 1 == k)
        {
            cout << root->data << endl;
        }
        else
        {
            printAtDepthK(root->left, k - rDistance - 2);
        }
        return 1 + rDistance;
    }

    return -1;
}

void nodesAtDistanceK(BinaryTreeNode<int> *root, int node, int k)
{

    helper(root, node, k);

    // 8 3 10 1 6 -1 14 -1 -1 -1 -1 13 -1 -1 -1
    // 10 2
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
            BinaryTreeNode<int> *rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main()
{
    BinaryTreeNode<int> *root = takeInput();
    int targetNode, k;
    cin >> targetNode >> k;
    nodesAtDistanceK(root, targetNode, k);
    delete root;
}