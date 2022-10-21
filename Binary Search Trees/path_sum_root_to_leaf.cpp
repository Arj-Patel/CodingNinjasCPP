#include <iostream>
#include <queue>
#include <vector>s
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

void helper(BinaryTreeNode<int> *root, int k, vector<int> vec)
{

    if (k <= 0 || root == NULL)
    {
        return;
    }

    vec.push_back(root->data);

    helper(root->left, k - root->data, vec);
    helper(root->right, k - root->data, vec);

    if (root->right == NULL && root->left == NULL && root->data == k)
    {
        for (int i = 0; i < vec.size(); i++)
        {
            cout << vec[i] << " ";
        }
        cout << endl;
    }
}

void rootToLeafPathsSumToK(BinaryTreeNode<int> *root, int k)
{

    vector<int> vec;
    helper(root, k, vec);
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
    int k;
    cin >> k;
    rootToLeafPathsSumToK(root, k);
    delete root;
}