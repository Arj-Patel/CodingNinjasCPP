#include <iostream>
#include "Node.cpp"
using namespace std;

Node *swapNodes(Node *head, int i, int j)
{

    if (head == NULL || i == j)
    {
        return head;
    }

    Node *add1 = head;
    Node *add2;
    Node *temp = head;

    for (int k = 0; k < (max(i, j)); k++, temp = temp->next)
    {
        if (k == i - 1)
        {
            add1 = temp;
        }
        if (k == j - 1)
        {
            add2 = temp;
        }
    }
    if (add1 == head)
    {
        Node *returnVal = add2->next;
        Node *temp1 = add2->next->next;
        add2->next->next = add2;
        add2->next = add1;
        add1->next = temp1;
        return returnVal;
    }
    else if (i - j == 1 || i - j == -1)
    {
        add1->next = add1->next->next;
        Node *temp1 = add2->next->next;
        add2->next->next = add2;
        add2->next = temp1;
    }
    else
    {
        Node *add1nxt = add1->next->next;
        Node *add2nxt = add2->next->next;
        Node *temp1 = add1->next;
        add1->next = add2->next;
        add1->next->next = add1nxt;
        add2->next = temp1;
        add2->next->next = add2nxt;
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
        int i, j;
        Node *head = takeinput();
        cin >> i;
        cin >> j;
        head = swapNodes(head, i, j);
        print(head);
    }
    return 0;
}