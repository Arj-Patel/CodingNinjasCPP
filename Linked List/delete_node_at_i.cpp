#include <iostream>
#include "Node.cpp"
using namespace std;

void print(Node *head)
{

    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }

    delete temp;
    delete head;
}

Node *deleteNode(Node *head, int index)
{
    if (head == NULL)
    {
        return head;
    }
    if (index == 0)
    {
        return head->next;
    }

    Node *temp = head;
    for (int i = 0; i < index - 1; i++)
    {
        if (temp == NULL)
        {
            return head;
        }
        temp = temp->next;
    }

    if (temp->next == NULL)
    {
        return head;
    }
    else
    {
        Node *delNode = temp->next;
        temp->next = (temp->next)->next;
        delete delNode;
        return head;
    }
}

int main()
{

    Node n1(10);
    Node n2(20);
    Node n3(30);
    Node n4(40);
    Node n5(50);

    Node *head = &n1;
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;

    deleteNode(head, 2);

    return 0;
}