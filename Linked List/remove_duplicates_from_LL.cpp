#include <iostream>
#include "Node.cpp"
using namespace std;

Node *removeDuplicates(Node *head)
{
    if (head == NULL)
    {
        return head;
    }

    Node *temp = head;
    while (temp->next != NULL)
    {
        if (temp->data == (temp->next)->data)
        {
            temp->next = (temp->next)->next;
        }
        else
        {
            temp = temp->next;
        }
    }
    return head;
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
        head = removeDuplicates(head);
        print(head);
    }
    return 0;
}