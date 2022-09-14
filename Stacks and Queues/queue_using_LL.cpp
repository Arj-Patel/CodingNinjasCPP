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
        next = NULL;
    }
};

class Queue
{
    Node *first;
    Node *last;
    int size;

public:
    Queue()
    {
        size = 0;
        first = NULL;
        last = NULL;
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    void enqueue(int data)
    {
        Node *newData = new Node(data);
        if (first == NULL)
        {
            first = newData;
            last = newData;
        }
        else
        {
            last->next = newData;
            last = last->next;
        }
        size++;
    }

    int dequeue()
    {
        if (size == 0)
        {
            return -1;
        }
        int element = first->data;
        Node *temp = first;
        first = first->next;
        delete[] temp;
        size--;
        return element;
    }

    int front()
    {
        if (size == 0)
        {
            return -1;
        }
        return first->data;
    }
};

int main()
{
    Queue q;

    int t;
    cin >> t;

    while (t--)
    {
        int choice, input;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cin >> input;
            q.enqueue(input);
            break;
        case 2:
            cout << q.dequeue() << "\n";
            break;
        case 3:
            cout << q.front() << "\n";
            break;
        case 4:
            cout << q.getSize() << "\n";
            break;
        default:
            cout << ((q.isEmpty()) ? "true\n" : "false\n");
            break;
        }
    }
}