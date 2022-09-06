#include <iostream>
#include "Node.cpp"
using namespace std;

Node *midPoint(Node *head)
{
    if (head == NULL)
    {
        return head;
    }

    Node *fast = head->next;
    Node *slow = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

Node *takeinput()
{
    int data;
    cin >> data;
    Node *head = NULL, *tail = NULL;
    while (data != -1)
    {
        Node *newnode = new Node(data);
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
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
        Node *mid = midPoint(head);
        if (mid != NULL)
        {
            cout << mid->data;
        }
        cout << endl;
    }
    return 0;
}