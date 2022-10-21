#include <iostream>
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

class BST
{
    BinaryTreeNode<int> *root;

    void print(BinaryTreeNode<int> *root)
    {
        if (root == NULL)
        {
            return;
        }

        cout << root->data << ":";
        if (root->left == NULL && root->right == NULL)
        {
            cout << endl;
        }
        if (root->left != NULL)
        {
            cout << "L:" << root->left->data << ",";
            if (root->right == NULL)
            {
                cout << endl;
            }
        }
        if (root->right != NULL)
        {
            cout << "R:" << root->right->data << endl;
        }
        print(root->left);
        print(root->right);
    }

    bool search(BinaryTreeNode<int> *root, int num)
    {

        if (root == NULL)
        {
            return false;
        }

        bool ans1 = search(root->left, num);
        bool ans2 = search(root->right, num);

        return ans1 || ans2 || root->data == num;
    }

    BinaryTreeNode<int> *insert(BinaryTreeNode<int> *root, int num)
    {

        if (root == NULL)
        {
            BinaryTreeNode<int> *newNode = new BinaryTreeNode<int>(num);
            return newNode;
        }

        if (num > root->data)
        {
            BinaryTreeNode<int> *newNode = insert(root->right, num);
            root->right = newNode;
        }
        else
        {
            BinaryTreeNode<int> *newNode = insert(root->left, num);
            root->left = newNode;
        }

        return root;
    }

    BinaryTreeNode<int> *remove(BinaryTreeNode<int> *root, int num)
    {

        if (root == NULL)
        {
            return NULL;
        }

        if (root->data < num)
        {
            root->right = remove(root->right, num);
        }
        else if (root->data > num)
        {
            root->left = remove(root->left, num);
        }
        else if (root->data == num)
        {
            if (root->right == NULL && root->left == NULL)
            {
                root = NULL;
            }
            else if (root->right == NULL)
            {
                root = root->left;
            }
            else if (root->left == NULL)
            {
                root = root->right;
            }
            else
            {
                BinaryTreeNode<int> *temp = root->left;
                root = root->right;
                root->left = temp;
            }
        }
        return root;
    }

public:
    BST()
    {
        root = NULL;
    }

    void remove(int data)
    {

        root = remove(root, data);
    }

    void print()
    {
        print(root);
    }

    void insert(int data)
    {
        root = insert(root, data);
    }

    bool search(int data)
    {
        return search(root, data);
    }
};

int main()
{
    BST *tree = new BST();
    int choice, input, q;
    cin >> q;
    while (q--)
    {
        cin >> choice;
        switch (choice)
        {
        case 1:
            cin >> input;
            tree->insert(input);
            break;
        case 2:
            cin >> input;
            tree->remove(input);
            break;
        case 3:
            cin >> input;
            cout << ((tree->search(input)) ? "true\n" : "false\n");
            break;
        default:
            tree->print();
            break;
        }
    }
}