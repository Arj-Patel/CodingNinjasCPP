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

// bool isPresent(BinaryTreeNode<int>* root, int num1, int num2){

//     if(root == NULL){
//         return false;
//     }

//     bool ans1 = isPresent(root->left, num1, num2);
//     bool ans2 = isPresent(root->right, num1, num2);

//     return ans1 || ans2 || root->data == num1 || root->data == num2;

// }

// bool isPresent(BinaryTreeNode<int>* root, int num1){

//     if(root == NULL){
//         return false;
//     }

//     bool ans1 = isPresent(root->left, num1);
//     bool ans2 = isPresent(root->right, num1);

//     return ans1 || ans2 || root->data == num1;

// }

int getLCA(BinaryTreeNode<int> *root, int a, int b)
{
    /*
    if(root == NULL){
        return -1;
    }

    if(isPresent(root->left, a) && isPresent(root->right, b) || isPresent(root->left, b) && isPresent(root->right, a)){
        return root->data;
    }

    if(root->data == a || root->data == b){
        return root->data;
    }
    if(root->left != NULL){
        if(root->left->data == a || root->left->data == b){
            if(isPresent(root->right, a, b)){
                return root->data;
            }
        }
    }
    if(root->right != NULL){
        if(root->right->data == a || root->right->data == b){
            if(isPresent(root->left, a, b)){
                return root->data;
            }
        }
    }

    int ans1 = getLCA(root->left, a, b);
    int ans2 = getLCA(root->right, a, b);

    if(ans1 != -1){
        return ans1;
    }
    if(ans2 != -1){
        return ans2;
    }
    return -1
    */

    if (root == NULL)
    {
        return -1;
    }

    if (root->data == a || root->data == b)
    {
        return root->data;
    }

    int ans1 = getLCA(root->left, a, b);
    int ans2 = getLCA(root->right, a, b);

    if (ans1 == -1 && ans2 == -1)
    {
        return -1;
    }
    else if (ans1 == -1)
    {
        return ans2;
    }
    else if (ans2 == -1)
    {
        return ans1;
    }
    else if (ans1 != -1 && ans2 != -1)
    {
        return root->data;
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
    int a, b;
    cin >> a >> b;
    cout << getLCA(root, a, b);
    delete root;
}