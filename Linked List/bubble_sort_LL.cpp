#include <iostream>
#include "Node.cpp"
using namespace std;

void swap(Node *head)
{

    int temp = head->data;
    head->data = head->next->data;
    head->next->data = temp;
}

Node *bubbleSort(Node *head)
{

    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *temp = head;
    int count = 0;

    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    // cout<<count<<endl;
    temp = head;
    for (int i = 0; i < count - 1; i++)
    {
        Node *temp1 = temp;
        for (int j = 0; j < count - i - 1; j++)
        {

            if (temp1->data > temp1->next->data)
            {
                swap(temp1);
            }

            temp1 = temp1->next;
        }

        // temp = temp->next;
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
    Node *head = takeinput();
    head = bubbleSort(head);
    print(head);
}