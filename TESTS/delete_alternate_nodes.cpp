// delete alternate Node in a linked list
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    ~Node()
    {
        if (next)
        {
            delete next;
        }
    }
};

void deleteAlternateNodes(Node *head)
{
    Node *temp = head;
    while (temp->next != NULL && temp->next->next != NULL)
    {
        Node *temp1 = temp->next;
        temp->next = temp->next->next;
        temp = temp1->next;
    }

    if (temp->next != NULL)
    {
        temp->next = NULL;
    }
}

Node *takeinput()
{
    int data;
    cin >> data;
    Node *head = NULL, *tail = NULL;
    while (data != -1)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
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
    deleteAlternateNodes(head);
    print(head);
    delete head;
    return 0;
}