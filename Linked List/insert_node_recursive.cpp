#include <iostream>
#include "Node.cpp"
using namespace std;


/*

*********Tatti methood but works just fine************

Node *helper(Node *head, int index)
{
    if (index == 1 || head == NULL)
    {
        return head;
    }

    helper(head->next, index - 1);
}

Node *insertNode(Node *head, int index, int data)
{
    if (index == 0)
    {
        Node *newNode = new Node(data);
        newNode->next = head;
        return newNode;
    }

    Node *reqNode = helper(head, index);

    if (reqNode != NULL)
    {
        Node *newNode = new Node(data);

        newNode->next = (reqNode->next);
        reqNode->next = newNode;
    }
    return head;
}
*/

Node* insertNode(Node *head, int i, int data) {
    if(head == NULL){
        return head;
    }    
    
    if(i == 0){
        Node * newNode = new Node(data);
        newNode->next = head;
        return newNode;
        
    }

    Node* reqNode = insertNode(head->next, i - 1, data);
	head->next = reqNode;
    return head;
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

    cout << "\n";
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        Node *head = takeinput();
        int pos, data;
        cin >> pos >> data;
        head = insertNode(head, pos, data);
        print(head);
    }
}