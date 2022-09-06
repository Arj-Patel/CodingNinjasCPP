#include <iostream>
#include "Node.cpp"
using namespace std;

Node *skipMdeleteN(Node *head, int M, int N)
{
    if (M == 0)
    {
        return NULL;
    }

    if (head == NULL || N == 0)
    {
        return head;
    }

    int mCount = 0;
    int nCount = 0;
    Node *temp = head;
    bool delGo = 0;
    bool keepGo = 1;
    Node *start = head;
    Node *tail = NULL;

    while (temp != NULL)
    {
        if (keepGo)
        {
            if (tail == NULL)
            {
                tail = temp;
            }
            else
            {
                tail->next = temp;
                tail = temp;
            }
            mCount++;
        }

        if (delGo)
        {
            nCount++;
        }

        if (mCount == M)
        {
            // tail = temp;
            mCount = 0;
            keepGo = 0;
            delGo = 1;
        }

        if (nCount == N)
        {
            nCount = 0;
            keepGo = 1;
            delGo = 0;
            // tail->next = temp->next;
        }

        temp = temp->next;
    }

    tail->next = NULL;
    return start;
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
        int m, n;
        cin >> m >> n;
        head = skipMdeleteN(head, m, n);
        print(head);
    }
    return 0;
}