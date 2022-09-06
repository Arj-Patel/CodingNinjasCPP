#include <iostream>
#include "Node.cpp"
using namespace std;

Node *reverseLL(Node *head)
{
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

Node *kReverse(Node *head, int k)
{
    if (head == NULL || head->next == NULL || k == 1 || k == 0)
    {
        return head;
    }

    Node *temp = head;
    int count = 1;
    while (count < k && temp->next != NULL)
    {
        temp = temp->next;
        count++;
    }
    // cout<<temp->data<<endl;
    Node *ans = kReverse(temp->next, k);

    temp->next = NULL;
    Node *revAns = reverseLL(head);
    Node *temp2 = revAns;
    while (temp2->next != NULL)
    {
        temp2 = temp2->next;
    }
    temp2->next = ans;
    return revAns;
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
        int k;
        cin >> k;
        head = kReverse(head, k);
        print(head);
    }

    return 0;
}