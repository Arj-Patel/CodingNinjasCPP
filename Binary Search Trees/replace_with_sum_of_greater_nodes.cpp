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

/*
#include<climits>
int maxSum(BinaryTreeNode<int>* root, int num){
    if(root == NULL){
        return 0;
    }

    int ans1 = maxSum(root->left, num);
    int ans2 = maxSum(root->right, num);
    int sum = 0;
    if(root->data >= num){
        sum += root->data;
    }
    return ans1+ans2+sum;
}

void replaceWithLargerNodesSumHelper(BinaryTreeNode<int>* node, BinaryTreeNode<int>* root){
    if(node == NULL){
        return;
    }

    int ans1 = maxSum(root->left, node->data);
    int ans2 = maxSum(root->right, node->data);
    node->data = ans1 + ans2 + node->data;

    replaceWithLargerNodesSumHelper(node->left, root);
    // replaceWithLargerNodesSumHelper(node->left, root->right);
    replaceWithLargerNodesSumHelper(node->right, root);
    // replaceWithLargerNodesSumHelper(node->right, root->right);
}

void replaceWithLargerNodesSum(BinaryTreeNode<int> *root) {

    if(root == NULL){
        return;
    }

    replaceWithLargerNodesSumHelper(root, root);

}
*/

/*
#include <bits/stdc++.h>
void getVec(BinaryTreeNode<int>* root, vector<int> &vec){

    if(root == NULL){
        return;
    }

    getVec(root->left, vec);
    vec.push_back(root->data);
    getVec(root->right, vec);

}

void replaceWithLargerNodesSumHelper(BinaryTreeNode<int>* root, vector<int> const &vec, vector<int> const &vec2){

    if(root == NULL){
        return;
    }
    int i;
    for(i = 0; i < vec.size(); i++){
        if(vec.at(i) == root->data){
            break;
        }
    }

    root->data = vec2.at(i);
    replaceWithLargerNodesSumHelper(root->left, vec, vec2);
    replaceWithLargerNodesSumHelper(root->right, vec, vec2);

}

void getSumVector(vector<int> &vec){

    for(int i = 0; i < vec.size(); i++){
        vector<int>::iterator iter = vec.begin() + i;
        vec.at(i) = accumulate(iter, vec.end(), 0);
    }

}

void replaceWithLargerNodesSum(BinaryTreeNode<int> *root) {

    vector<int> vec;
    getVec(root, vec);
    sort(vec.begin(), vec.end());
    vector<int> vec2 = vec;
    getSumVector(vec2);


    replaceWithLargerNodesSumHelper(root, vec, vec2);

}
*/
// #include <bits/stdc++.h>
// int getFullSum(BinaryTreeNode<int>* root){
//     if(root == NULL){
//         return 0;
//     }
//     int ans = 0;
//     ans += getFullSum(root->left);
//     ans+=root->data;
//     ans+=getFullSum(root->right);
//     return ans;

// }

// int replaceWithLargerNodesSumHelper(BinaryTreeNode<int>* root, int sum){
//     if(root == NULL){
//         return 0;
//     }
//     int temp = root->data;
// 	int ans1 = replaceWithLargerNodesSumHelper(root->right, sum- root->data);
//     root->data += ans1;
//     int ans2 = replaceWithLargerNodesSumHelper(root->left, ans1+temp);
//     return ans1 + ans2;
// }

// void replaceWithLargerNodesSum(BinaryTreeNode<int> *root) {

//     if(root == NULL){
//         return;
//     }

//     int sum = getFullSum(root->right);
//     // cout<<sum<<endl;

//     replaceWithLargerNodesSumHelper(root, sum+root->data);

// }

int replaceWithLargerNodesSumHelper(BinaryTreeNode<int> *root, int sum)
{
    if (root == NULL)
    {
        return 0;
    }

    int rightSum = replaceWithLargerNodesSumHelper(root->right, sum);
    root->data = rightSum + root->data;
    int leftSum = replaceWithLargerNodesSumHelper(root->left, rightSum + root->data);

    return leftSum + rightSum + root->data;
}

void replaceWithLargerNodesSum(BinaryTreeNode<int> *root)
{

    if (root == NULL)
    {
        return;
    }

    replaceWithLargerNodesSumHelper(root, 0);
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
    if (root == NULL)
    {
        return;
    }
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
    replaceWithLargerNodesSum(root);
    printLevelATNewLine(root);
    delete root;
}