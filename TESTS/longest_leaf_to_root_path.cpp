#include <iostream>
#include <vector>
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
};

// Following is the Binary Tree node structure
/**************
class BinaryTreeNode {
    public :
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};
***************/

vector<int> *longestPath(BinaryTreeNode<int> *root)
{

    if (root == NULL)
    {
        vector<int> *temp = new vector<int>;
        return temp;
    }

    vector<int> *lVec = longestPath(root->left);
    vector<int> *rVec = longestPath(root->right);

    if (lVec->size() > rVec->size())
    {
        lVec->push_back(root->data);
    }
    else
    {
        rVec->push_back(root->data);
    }

    if (lVec->size() > rVec->size())
    {
        return lVec;
    }
    else
    {
        return rVec;
    }
}

BinaryTreeNode<int> *takeInput()
{
    int rootData;
    // cout << "Enter root data : ";
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
        // cout << "Enter left child of " << currentNode -> data << " : ";
        cin >> leftChild;
        if (leftChild != -1)
        {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }
        // cout << "Enter right child of " << currentNode -> data << " : ";
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
    vector<int> *output = longestPath(root);
    vector<int>::iterator i = output->begin();
    while (i != output->end())
    {
        cout << *i << endl;
        i++;
    }
}
