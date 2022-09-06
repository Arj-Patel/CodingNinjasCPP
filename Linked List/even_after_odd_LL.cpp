#include <iostream>
#include "Node.cpp"
using namespace std;

Node *evenAfterOdd(Node *head)
{

    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *oddHead = NULL;
    Node *oddTail = NULL;
    Node *evenHead = NULL;
    Node *evenTail = NULL;
    Node *temp = head;

    while (temp != NULL)
    {
        if (temp->data % 2 == 0)
        {
            if (evenHead == NULL)
            {
                evenHead = temp;
                evenTail = temp;
                temp = temp->next;
            }
            else
            {
                evenTail->next = temp;
                evenTail = temp;
                temp = temp->next;
            }
        }
        else
        {
            if (oddTail == NULL)
            {
                oddHead = temp;
                oddTail = temp;
                temp = temp->next;
            }
            else
            {
                oddTail->next = temp;
                oddTail = temp;
                temp = temp->next;
            }
        }
    }

    if (oddTail != NULL)
    {
        oddTail->next = evenHead;
        if (evenTail != NULL)
        {
            evenTail->next = NULL;
        }
    }
    if (oddHead == NULL)
    {
        return evenHead;
    }
    else
    {
        return oddHead;
    }
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
        head = evenAfterOdd(head);
        print(head);
    }
    return 0;
}