#include <iostream>
#include "Node.cpp"
using namespace std;

bool isPalindrome(Node *head)
{
    if (head == NULL)
    {
        return true;
    }

    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    temp = head;
    Node *end;

    for (int i = 0; i < count / 2; i++)
    {
        end = head;
        for (int j = 0; j < count - i - 1; j++)
        {
            // cout<<j<<endl;
            end = end->next;
        }

        if (end->data != temp->data)
        {
            return false;
        }
        temp = temp->next;
    }
    return true;
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
        bool ans = isPalindrome(head);

        if (ans)
            cout << "true";
        else
            cout << "false";

        cout << endl;
    }

    return 0;
}