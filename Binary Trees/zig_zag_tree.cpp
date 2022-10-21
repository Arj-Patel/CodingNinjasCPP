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
void reverseQueue(queue<BinaryTreeNode<int> *> &input)
{

    if (input.empty() == 1)
    {
        return;
    }

    BinaryTreeNode<int> *temp = input.front();
    input.pop();

    reverseQueue(input);

    input.push(temp);
}

void zigZagOrder(BinaryTreeNode<int> *root)
{

    if (root == NULL)
    {
        return;
    }

    int count = 0;

    queue<BinaryTreeNode<int> *> current;
    current.push(root);
    queue<BinaryTreeNode<int> *> child;

    while (!current.empty())
    {
        count++;
        while (!current.empty())
        {
            BinaryTreeNode<int> *temp = current.front();
            current.pop();
            cout << temp->data << " ";

            if (count % 2 == 1)
            {
                if (temp->left != NULL)
                {
                    child.push(temp->left);
                }
                if (temp->right != NULL)
                {
                    child.push(temp->right);
                }
            }
            else
            {
                if (temp->right != NULL)
                {
                    child.push(temp->right);
                }
                if (temp->left != NULL)
                {
                    child.push(temp->left);
                }
            }
        }
        reverseQueue(child);
        cout << endl;
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
    zigZagOrder(root);
}