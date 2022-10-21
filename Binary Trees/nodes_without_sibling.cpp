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
#include <queue>
void printNodesWithoutSibling(BinaryTreeNode<int> *root)
{

    if (root == NULL)
    {
        return;
    }

    queue<BinaryTreeNode<int> *> current;
    queue<BinaryTreeNode<int> *> child;

    current.push(root);

    while (!current.empty())
    {

        while (!current.empty())
        {
            BinaryTreeNode<int> *temp = current.front();
            current.pop();
            if (temp->left == NULL)
            {
                if (temp->right != NULL)
                {
                    cout << temp->right->data << " ";
                }
            }
            else if (temp->right == NULL)
            {
                if (temp->left != NULL)
                {
                    cout << temp->left->data << " ";
                }
            }

            if (temp->left != NULL)
            {
                child.push(temp->left);
            }
            if (temp->right != NULL)
            {
                child.push(temp->right);
            }
        }
        // cout<<endl;
        current = child;
        while (!child.empty())
        {
            child.pop();
        }
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
    printNodesWithoutSibling(root);
}