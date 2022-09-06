#include <iostream>
#include "Node.cpp"
using namespace std;

Node *merge(Node *head1, Node *head2)
{
    if (head1 == NULL)
    {
        return head2;
    }
    else if (head2 == NULL)
    {
        return head1;
    }

    Node *finalHead = NULL;
    Node *finalTail = NULL;

    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data <= head2->data)
        {
            if (finalHead == NULL)
            {
                finalHead = head1;
                finalTail = head1;
            }
            else
            {
                finalTail->next = head1;
                finalTail = finalTail->next;
            }
            head1 = head1->next;
        }
        else if (head1->data > head2->data)
        {
            if (finalHead == NULL)
            {
                finalHead = head2;
                finalTail = head2;
            }
            else
            {
                finalTail->next = head2;
                finalTail = finalTail->next;
            }
            head2 = head2->next;
        }
    }

    if (head1 == NULL && head2 != NULL)
    {
        finalTail->next = head2;
    }
    else if (head2 == NULL && head1 != NULL)
    {
        finalTail->next = head1;
    }

    return finalHead;
}

Node *mergeSort(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *fast = head->next;
    Node *slow = head;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    Node *other = slow->next;
    slow->next = NULL;

    Node *ans1 = mergeSort(head);
    Node *ans2 = mergeSort(other);
    Node *ans = merge(ans1, ans2);

    return ans;
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
        head = mergeSort(head);
        print(head);
    }

    return 0;
}