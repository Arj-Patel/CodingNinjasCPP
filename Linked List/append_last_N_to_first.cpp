#include <iostream>
#include "Node.cpp"
using namespace std;

Node *appendLastNToFirst(Node *head, int n)
{
    if (head == NULL || n == 0)
    {
        return head;
    }

    Node *temp = head;
    int count = 0;
    while (temp->next != NULL)
    {
        count++;
        temp = temp->next;
    }
    int first = count - n;
    Node *temp1 = head;
    while (first > 0)
    {
        temp1 = temp1->next;
        first--;
    }

    Node *newHead = temp1->next;
    temp1->next = NULL;
    temp->next = head;
    return newHead;
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
        int n;
        cin >> n;
        head = appendLastNToFirst(head, n);
        print(head);
    }
    return 0;
}