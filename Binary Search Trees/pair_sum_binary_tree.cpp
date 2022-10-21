#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
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

void getVector(BinaryTreeNode<int> *root, vector<int> &vec)
{

    if (root == NULL)
    {
        return;
    }

    getVector(root->left, vec);
    vec.push_back(root->data);
    getVector(root->right, vec);
}

void pairSum(BinaryTreeNode<int> *root, int sum)
{

    vector<int> vec;

    getVector(root, vec);
    // cout<<vec.size()<<endl;

    sort(vec.begin(), vec.end());

    int i = 0, j = vec.size() - 1;

    while (i < j)
    {
        if (vec.at(i) + vec.at(j) == sum)
        {
            cout << vec.at(i) << " " << vec.at(j) << endl;
            i++;
            j--;
        }
        else if (vec.at(i) + vec.at(j) > sum)
        {
            j--;
        }
        else
        {
            i++;
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
    int sum;
    cin >> sum;
    pairSum(root, sum);
    delete root;
}