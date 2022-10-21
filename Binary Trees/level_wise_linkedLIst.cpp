#include <iostream>
#include <queue>
#include <vector>

template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;
    Node(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};

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

using namespace std;
#include <queue>
vector<Node<int> *> constructLinkedListForEachLevel(BinaryTreeNode<int> *root)
{

    if (root == NULL)
    {
        vector<Node<int> *> ll;
        return ll;
    }

    queue<BinaryTreeNode<int> *> current;
    current.push(root);
    queue<BinaryTreeNode<int> *> child;
    vector<Node<int> *> ll;

    while (!current.empty())
    {
        Node<int> *head = new Node<int>(current.front()->data);

        if (current.front()->left != NULL)
        {
            child.push(current.front()->left);
        }
        if (current.front()->right != NULL)
        {
            child.push(current.front()->right);
        }
        current.pop();
        Node<int> *templl = head;
        while (!current.empty())
        {
            BinaryTreeNode<int> *temp = current.front();
            current.pop();
            templl->next = new Node<int>(temp->data);
            templl = templl->next;
            if (temp->left != NULL)
            {
                child.push(temp->left);
            }
            if (temp->right != NULL)
            {
                child.push(temp->right);
            }
        }
        current = child;
        while (!child.empty())
        {
            child.pop();
        }
        ll.push_back(head);
    }
    return ll;
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

void print(Node<int> *head)
{
    Node<int> *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    BinaryTreeNode<int> *root = takeInput();
    vector<Node<int> *> ans = constructLinkedListForEachLevel(root);

    for (int i = 0; i < ans.size(); i++)
    {
        print(ans[i]);
    }
}