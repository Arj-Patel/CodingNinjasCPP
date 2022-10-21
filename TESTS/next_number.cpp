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
};

Node *reverse(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *curr1 = head;
    Node *curr2 = head->next;

    while (curr2 != NULL)
    {
        Node *curr3 = curr2->next;
        curr2->next = curr1;
        curr1 = curr2;
        curr2 = curr3;
    }

    head->next = NULL;
    return curr1;
}

Node *increase(Node *head)
{
    int carry = 0;
    Node *temp = head;
    // temp->data += 1;
    // if(temp->data >= 10){
    //     temp->data = temp->data%10;
    //     carry = 1;
    // }
    while (temp->next != NULL)
    {
        int x;
        if (temp == head)
        {
            // cout<<1<<endl;
            x = temp->data + carry + 1;
            // cout<<x<<endl;
        }
        else
        {
            x = temp->data + carry;
        }

        if (x >= 10)
        {
            temp->data = x % 10;
            carry = 1;
        }
        else
        {
            temp->data = x;
            carry = 0;
        }
        temp = temp->next;
    }
    temp->data += carry;
    if (temp->data >= 10)
    {
        temp->data = temp->data % 10;
        Node *newNode = new Node(1);
        temp->next = newNode;
    }
    if (temp == head)
    {
        temp->data++;
    }
    return head;
}

Node *NextLargeNumber(Node *head)
{

    head = reverse(head);
    head = increase(head);
    head = reverse(head);
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
    cout << endl;
}

int main()
{
    Node *head = takeinput();

    head = NextLargeNumber(head);
    print(head);
    return 0;
}
