#include <iostream>
#include "Node.cpp"
using namespace std;

int findNodeRec(Node *head, int n)
{

    if (head == NULL)
    {
        return -1;
    }

    int ans = findNodeRec(head->next, n);

    if (head->data == n)
    {
        return 0;
    }

    if (ans == -1)
    {
        return ans;
    }
    else
    {
        return ans + 1;
    }
}
Node *takeinput()
{
    int data;
    cin >> data;
    Node *head = NULL, *tail = NULL;
    while (data != -1)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Node *head = takeinput();
        int val;
        cin >> val;
        cout << findNodeRec(head, val) << endl;
    }
}