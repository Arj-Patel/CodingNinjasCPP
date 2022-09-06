#include <iostream>
#include "Node.cpp"
using namespace std;

void print(Node *head)
{

    Node * temp = head;
    while (temp != NULL)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }

    delete temp;
    delete head;
}

int main()
{

    Node n1(1);
    Node n2(2);
    Node n3(3);
    Node n4(4);
    Node n5(5);

    Node *head = &n1;

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;

    print(head);

    return 0;
}