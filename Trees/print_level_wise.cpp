#include <iostream>
#include <vector>
#include <queue>
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

// void helper(queue<TreeNode<int>*> q){

// 	if(q.size() == 0){
//         return;
//     }

//     TreeNode<int>* temp = q.front();
//     cout<<temp->data<<":";
//     q.pop();
//     int i;
//     for(i = 0; i < temp->children.size(); i++){
//         if(i == temp->children.size() - 1){
//             cout<<temp->children[i]->data;
//         }
//         else{
//             cout<<temp->children[i]->data<<",";
//         }
//         q.push(temp->children[i]);
//     }

//     cout<<endl;
//     helper(q);
// }

void printLevelWise(TreeNode<int> *root)
{
    queue<TreeNode<int> *> q;

    q.push(root);

    while (!q.empty())
    {
        TreeNode<int> *temp = q.front();
        q.pop();
        cout << temp->data << ":";
        int i;
        for (i = 0; i < temp->children.size(); i++)
        {
            if (i == temp->children.size() - 1)
            {
                cout << temp->children[i]->data;
            }
            else
            {
                cout << temp->children[i]->data << ",";
            }
            q.push(temp->children[i]);
        }
        cout << endl;
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
    printLevelWise(root);
}