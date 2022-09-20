#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T data;
    vector<TreeNode<T> *> children;

    TreeNode(T data) { this->data = data; }

    ~TreeNode()
    {
        for (int i = 0; i < children.size(); i++)
        {
            delete children[i];
        }
    }
};

#include <queue>
using namespace std;

TreeNode<int> *getSecondLargestNode(TreeNode<int> *root)
{

    queue<TreeNode<int> *> q;

    q.push(root);

    int max = -2147483648;
    int second = -2147483648;
    TreeNode<int> *maxNode = NULL;
    TreeNode<int> *secondNode = NULL;

    while (!q.empty())
    {
        TreeNode<int> *temp = q.front();
        q.pop();
        for (int i = 0; i < temp->children.size(); i++)
        {
            q.push(temp->children[i]);
            if (temp->children[i]->data > max)
            {
                second = max;
                secondNode = maxNode;
                max = temp->children[i]->data;
                maxNode = temp->children[i];
            }
            else if (temp->children[i]->data < max && temp->children[i]->data > second)
            {
                second = temp->children[i]->data;
                secondNode = temp->children[i];
            }
        }
    }

    if (root->data > max)
    {
        return maxNode;
    }
    else if (root->data < max && root->data > second)
    {
        return root;
    }
    else
    {
        return secondNode;
    }

    // return secondNode;
}

TreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);

    queue<TreeNode<int> *> pendingNodes;

    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++)
        {
            int childData;
            cin >> childData;
            TreeNode<int> *child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }

    return root;
}

int main()
{
    TreeNode<int> *root = takeInputLevelWise();

    TreeNode<int> *ans = getSecondLargestNode(root);

    if (ans != NULL)
    {
        cout << ans->data;
    }
    else
    {
        cout << INT_MIN;
    }
}