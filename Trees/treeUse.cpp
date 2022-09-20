#include <iostream>
#include <queue>
#include "treeNode_class.h"
using namespace std;

void takeInputLevelWise(queue<treeNode<int> *> q)
{
    if (q.empty())
    {
        return;
    }

    treeNode<int> *temp = q.front();
    // treeNode<int> *root = new treeNode<int>(temp);
    q.pop();

    int n;
    cout << "Enter the number of children of " << temp->data << ": ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cout << "Enter the " << i + 1 << "th children of " << temp->data << ": ";
        cin >> x;
        treeNode<int> *child = new treeNode<int>(x);
        q.push(child);
        temp->children.push_back(child);
    }

    takeInputLevelWise(q);

    return;
}

treeNode<int> *takeInput()
{
    int rootData;
    cout << "Enter rootData: ";
    cin >> rootData;

    treeNode<int> *root = new treeNode<int>(rootData);

    int n;
    cout << "Enter the number of children of " << rootData << ": ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        treeNode<int> *child = takeInput();
        root->children.push_back(child);
    }

    return root;
}

void print(treeNode<int> *root)
{
    // Note: this is an edge case and not a base case as we will never reach here while printing.
    if (root == NULL)
    {
        return;
    }
    cout << root->data << ":";
    for (int i = 0; i < root->children.size(); i++)
    {
        cout << root->children[i]->data << ",";
    }
    cout << endl;
    for (int i = 0; i < root->children.size(); i++)
    {
        print(root->children[i]);
    }
}

int main()
{

    // treeNode<int> *root = new treeNode<int>(1);
    // treeNode<int> *ch1 = new treeNode<int>(2);
    // treeNode<int> *ch2 = new treeNode<int>(3);

    // root->children.push_back(ch1);
    // root->children.push_back(ch2);

    // print(root);

    queue<treeNode<int> *> q;
    int rootData;
    cout << "Enter rootData: ";
    cin >> rootData;
    treeNode<int> *root = new treeNode<int>(rootData);
    q.push(root);
    takeInputLevelWise(q);
    print(root);

    return 0;
}