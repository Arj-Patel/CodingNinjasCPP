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
/*
int isSibling(BinaryTreeNode<int>* root, int p, int q){
    if(root == NULL){
        return 0;
    }

    if(root->left && root->right){
        if((root->left->data == p && root->right->data == q) || (root->left->data == q && root->right->data == p)){
            return 1;
        }
    }
    return (isSibling(root->right, p, q) || isSibling(root->left, p, q));
}

int level(BinaryTreeNode<int>* root, int ptr, int lev){
    if(root == NULL){
        return 0;
    }
    if(root->data == ptr){
        return lev;
    }

    int l = level(root->left, ptr, lev+1);
    if(l != 0){
        return 1;
    }
    return level(root->right, ptr, lev+1);

}


bool isCousin(BinaryTreeNode<int> *root, int a, int b) {

    if((level(root, a, 1) == level(root, b, 1)) && !(isSibling(root, a, b))){
        return true;
    }
    else{
        return false;
    }

}*/

bool isSibling(BinaryTreeNode<int> *root, int data_one,
               int data_two)
{
    if (!root)
        return false;

    if (root->left && root->right)
    {
        int left = root->left->data;
        int right = root->right->data;

        if (left == data_one && right == data_two)
            return true;
        else if (left == data_two && right == data_one)
            return true;
    }

    if (root->left)
        isSibling(root->left, data_one,
                  data_two);

    if (root->right)
        isSibling(root->right, data_one,
                  data_two);
}

int level(BinaryTreeNode<int> *root, int ptr, int lev)
{
    if (root == NULL)
        return 0;
    if (root->data == ptr)
        return lev;

    int l = level(root->left, ptr, lev + 1);
    if (l != 0)
        return l;

    return level(root->right, ptr, lev + 1);
}

bool isCousin(BinaryTreeNode<int> *root, int a, int b)
{

    if ((level(root, a, 1) == level(root, b, 1)) && !(isSibling(root, a, b)))
        return true;
    else
        return false;
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
    BinaryTreeNode<int> *root = takeInput();
    int n1, n2;
    cin >> n1 >> n2;
    if (isCousin(root, n1, n2))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
}
