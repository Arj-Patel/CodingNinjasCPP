#include <iostream>
#include "Node.cpp"
using namespace std;

void print(Node *head)
{

    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    delete temp;
    delete head;
}

Node *input()
{

    Node *head = NULL;
    Node *tail = NULL;
    char chk;

    while (true)
    {
        cout << "Do you want to input the next element? Y or N" << endl;
        cin >> chk;
        if (chk == 'N' || chk == 'n')
        {
            return head;
        }
        cout << "Enter the number" << endl;
        int data;
        cin >> data;

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
    }
}

int main()
{

    Node *head = input();
    print(head);

    return 0;
}