// C++ implementation of De-queue using circular
// array
#include <iostream>
using namespace std;

/**********

 Following is the main function we are using internally.
 Refer this for completing the Dequeue class.


 int main()
 {
 Deque dq(10);
 int choice,input;
 while(true) {
 cin >> choice;
 switch (choice) {
 case 1:
 cin >> input;
 dq.insertfront(input);
 break;
 case 2:
 cin >> input;
 dq.insertrear(input);
 break;
 case 3:
 dq.deletefront();
 break;
 case 4:
 dq.deleterear();
 break;
 case 5:
 cout << dq.getFront() << "\n";
 break;
 case 6:
 cout << dq.getRear() << "\n";
 break;
 default:
 return 0;
 }
 }

 return 0;
 }

 ************/

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

#include <iostream>
using namespace std;

class Deque
{
    int size;
    int currentSize;
    Node *head;
    Node *tail;

public:
    Deque(int size)
    {
        this->size = size;
        head = NULL;
        tail = NULL;
        currentSize = 0;
    }

    void insertFront(int element)
    {
        if (currentSize == 10)
        {
            cout << -1 << endl;
            return;
        }

        Node *newNode = new Node(element);
        if (head == NULL)
        {
            newNode->next = head;
            head = newNode;
            tail = newNode;
            currentSize++;
        }
        else
        {
            newNode->next = head;
            head = newNode;
            currentSize++;
        }
    }

    void insertRear(int element)
    {

        if (currentSize == 10)
        {
            cout << -1 << endl;
            return;
        }

        Node *newNode = new Node(element);
        if (tail == NULL)
        {
            tail = newNode;
            head = newNode;
            currentSize++;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        currentSize++;
    }
    void deleteFront()
    {

        if (currentSize == 0)
        {
            tail = NULL;
            head = NULL;
            cout << -1 << endl;
            return;
        }

        Node *temp = head->next;
        delete head;
        head = temp;
        currentSize--;
    }

    void deleteRear()
    {

        if (currentSize == 0)
        {
            tail = NULL;
            head = NULL;
            cout << -1 << endl;
            return;
        }

        Node *temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        Node *temp1 = temp->next;
        delete temp1;
        temp->next = NULL;
        tail = temp;
        currentSize--;
    }

    int getFront()
    {
        if (currentSize == 0)
        {
            return -1;
        }

        return head->data;
    }
    int getRear()
    {
        if (currentSize == 0)
        {
            return -1;
        }

        return tail->data;
    }
};

// Driver program to test above function
int main()
{
    Deque dq(10);
    int choice, input;
    while (true)
    {
        cin >> choice;
        switch (choice)
        {
        case 1:
            cin >> input;
            dq.insertFront(input);
            break;
        case 2:
            cin >> input;
            dq.insertRear(input);
            break;
        case 3:
            dq.deleteFront();
            break;
        case 4:
            dq.deleteRear();
            break;
        case 5:
            cout << dq.getFront() << "\n";
            break;
        case 6:
            cout << dq.getRear() << "\n";
            break;
        default:
            return 0;
        }
    }

    return 0;
}
