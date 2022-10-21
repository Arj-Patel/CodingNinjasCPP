#include <iostream>
#include <queue>
#include <vector>
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

vector<int> *getPath(BinaryTreeNode<int> *root, int num)
{

    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == num)
    {
        vector<int> *temp = new vector<int>;
        temp->push_back(root->data);
        return temp;
    }

    vector<int> *ans1 = getPath(root->left, num);
    vector<int> *ans2 = getPath(root->right, num);

    if (ans1 != NULL)
    {
        ans1->push_back(root->data);
        return ans1;
    }
    else if (ans2 != NULL)
    {
        ans2->push_back(root->data);
        return ans2;
    }

    return ans1;
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
    vector<int> *output = getPath(root, k);

    if (output != NULL)
    {
        for (int i = 0; i < output->size(); i++)
        {
            cout << output->at(i) << " ";
        }
    }

    delete root;
}