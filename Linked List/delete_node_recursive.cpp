#include <iostream>
#include "Node.cpp"
using namespace std;

Node *deleteNodeRec(Node *head, int index)
{
    if (head == NULL)
    {
        return head;
    }

    if (index == 0)
    {
        return head->next;
    }

    Node *reqNode = deleteNodeRec(head->next, index - 1);
    head->next = reqNode;
    return head;
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

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        Node *head = takeinput();
        int pos;
        cin >> pos;
        head = deleteNodeRec(head, pos);
        print(head);
    }

    return 0;
}