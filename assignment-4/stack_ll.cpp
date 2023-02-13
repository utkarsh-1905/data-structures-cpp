#include <iostream>

// stacks using linked list

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

class Stack
{
public:
    Node *head;
    int nodeCount;
    int size;

    Stack(int size)
    {
        head = NULL;
        nodeCount = 0;
        this->size = size;
    }

    void Push(int data)
    {
        Node *temp = new Node(data);
        if (IsEmpty())
        {
            head = temp;
            nodeCount++;
            return;
        }

        Node *nHead = head;
        while (nHead->next != NULL)
        {
            nHead = nHead->next;
        }

        nHead->next = temp;
        nodeCount++;
        return;
    }

    void Pop()
    {
        if (IsEmpty())
        {
            cout << "Stack is empty" << endl;
            return;
        }
        Node *itr = head;
        while (itr->next->next != NULL)
        {
            itr = itr->next;
        }
        delete (itr->next->next);
        itr->next = NULL;
        return;
    }

    bool IsFull()
    {
        if (nodeCount == size)
        {
            return true;
        }
        else
            return false;
    }

    bool IsEmpty()
    {
        if (head == NULL)
        {
            return true;
        }
        else
            return false;
    }

    void Display()
    {
        if (head == NULL)
        {
            return;
        }
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }

    int Peek()
    {
        Node *itr = head;
        while (itr->next != NULL)
        {
            itr = itr->next;
        }
        return itr->data;
    }
};

int main()
{
    int size;
    cout << "Enter the size of stack: " << endl;
    cin >> size;
    Stack s(size);
    s.Push(5);
    s.Push(6);
    s.Push(7);
    s.Push(8);
    cout << "Elements are = " << endl;
    s.Display();
    s.Pop();
    cout << "Popped" << endl;
    s.Display();
    cout << "Peek " << s.Peek() << endl;
}