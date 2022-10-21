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
BinaryTreeNode<int> *createTree(int *preorder, int preLength, int *inorder, int inLength, BinaryTreeNode<int> *root)
{
    if (preLength == 0 || inLength == 0)
    {
        return root;
    }
    int leftInStart = 0;
    int leftInEnd = 0;
    while (inorder[leftInEnd] != preorder[0])
    {
        leftInEnd++;
    }
    leftInEnd--;
    int leftPreStart = 1;
    int leftPreEnd = 1 + leftInEnd;

    root = new BinaryTreeNode<int>(preorder[0]);
    root->left = createTree(preorder + 1, leftPreEnd - leftPreStart + 1, inorder, leftInEnd - leftInStart + 1, root->left);
    root->right = createTree(preorder + leftPreEnd + 1, preLength - leftPreEnd - 1, inorder + leftInEnd + 2, inLength - leftInEnd - 2, root->right);
    return root;
}

BinaryTreeNode<int> *buildTree(int *preorder, int preLength, int *inorder, int inLength)
{

    BinaryTreeNode<int> *root;

    root = createTree(preorder, preLength, inorder, inLength, root);

    return root;
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

void printLevelATNewLine(BinaryTreeNode<int> *root)
{
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        BinaryTreeNode<int> *first = q.front();
        q.pop();
        if (first == NULL)
        {
            if (q.empty())
            {
                break;
            }
            cout << endl;
            q.push(NULL);
            continue;
        }
        cout << first->data << " ";
        if (first->left != NULL)
        {
            q.push(first->left);
        }
        if (first->right != NULL)
        {
            q.push(first->right);
        }
    }
}

int main()
{
    int size;
    cin >> size;
    int *pre = new int[size];
    int *in = new int[size];
    for (int i = 0; i < size; i++)
        cin >> pre[i];
    for (int i = 0; i < size; i++)
        cin >> in[i];
    BinaryTreeNode<int> *root = buildTree(pre, size, in, size);
    printLevelATNewLine(root);
}