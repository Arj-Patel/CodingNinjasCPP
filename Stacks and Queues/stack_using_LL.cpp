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

/************************************************************

    Following is the structure of the node class

    class Node {
        public :
        int data;
        Node *next;

        Node(int data) {
            this->data = data;
            next = NULL;
        }
    };

**************************************************************/

class Stack
{

    Node *head;
    int size;

public:
    Stack()
    {
        head = NULL;
        size = 0;
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    void push(int element)
    {
        Node *data = new Node(element);
        data->next = head;
        head = data;
        size++;
    }

    int pop()
    {
        if (size == 0)
        {
            return -1;
        }
        Node *temp = head->next;
        int data = head->data;
        delete head;
        head = temp;
        size--;
        return data;
    }

    int top()
    {
        if (size == 0)
        {
            return -1;
        }
        return head->data;
    }
};

int main()
{
    Stack st;

    int q;
    cin >> q;

    while (q--)
    {
        int choice, input;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cin >> input;
            st.push(input);
            break;
        case 2:
            cout << st.pop() << "\n";
            break;
        case 3:
            cout << st.top() << "\n";
            break;
        case 4:
            cout << st.getSize() << "\n";
            break;
        default:
            cout << ((st.isEmpty()) ? "true\n" : "false\n");
            break;
        }
    }
}