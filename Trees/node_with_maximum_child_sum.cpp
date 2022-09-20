#include <iostream>
#include <queue>
#include <vector>
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

TreeNode<int> *maxSumNode(TreeNode<int> *root)
{

    TreeNode<int> *ans = root;
    for (int i = 0; i < root->children.size(); i++)
    {
        ans = maxSumNode(root->children[i]);
    }

    int rootSum = root->data;
    for (int i = 0; i < root->children.size(); i++)
    {
        rootSum += root->children[i]->data;
    }

    int ansSum = ans->data;
    for (int i = 0; i < ans->children.size(); i++)
    {
        ansSum += ans->children[i]->data;
    }

    if (rootSum > ansSum)
    {
        return root;
    }
    else
    {
        return ans;
    }
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

    TreeNode<int> *ans = maxSumNode(root);

    if (ans != NULL)
    {
        cout << ans->data;
    }
}