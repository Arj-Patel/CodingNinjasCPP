#include <iostream>
#include "Node.cpp"
using namespace std;

Node *reverseLinkedList(Node *head)
{
    // If the linked list is empty or contains only 1 element, return
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *curr1 = head;
    Node *curr2 = head->next;

    while (curr2 != NULL)
    {
        Node *curr3 = curr2->next; // We do this so that the adress of the next node of LL is not lost
        curr2->next = curr1;
        curr1 = curr2;
        curr2 = curr3;
    }
    head->next = NULL;
    return curr1;
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

    cout << "\n";
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        Node *head = takeinput();
        head = reverseLinkedList(head);
        print(head);
    }

    return 0;
}