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

Node* insertNode(Node *head, int index, int data)
{   
    if(index == 0){
        Node* newNode = new Node(data);
        newNode->next = head;
        return newNode;
    }   


    Node *temp = head;

    for (int i = 0; i < index - 1; i++)
    {
        if(temp == NULL){
            cout<<"Linked List ended"<<endl;
            return head;
        }
        temp = temp->next;
    }
    Node newNode(data);

    Node *currTemp = temp;
    currTemp = currTemp->next;
    temp->next = &newNode;
    newNode.next = currTemp;
    return head;
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

    print(head);
    head = insertNode(head, 0, 99);
    print(head);

    return 0;
}