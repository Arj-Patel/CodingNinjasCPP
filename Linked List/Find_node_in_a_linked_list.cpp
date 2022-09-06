#include <iostream>
#include "Node.cpp"
using namespace std;
int findNode(Node *head, int n)
{

    Node *temp = head;
    int i = 0;

    while (temp != NULL)
    {
        if (temp->data == n)
        {
            return i;
        }
        temp = temp->next;
        i++;
    }
    return -1;
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
        cout << findNode(head, val) << endl;
    }
}