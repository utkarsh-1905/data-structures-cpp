#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        this->data = 0;
        this->next = NULL;
    }

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class LinkedList
{

public:
    Node *head;

    LinkedList()
    {
        head = NULL;
    }

    void Insert(int data)
    {

        Node *temp = new Node(data);

        if (head == NULL)
        {
            head = temp;
            return;
        }

        Node *itr = head;

        while (itr->next != NULL)
        {
            itr = itr->next;
        }

        itr->next = temp;

        return;
    }

    void Display()
    {

        Node *itr = head;

        while (itr != NULL)
        {
            cout << itr->data << endl;
            itr = itr->next;
        }
        return;
    }
};

int main()
{
    LinkedList ll;
    ll.Insert(5);
    ll.Insert(6);
    ll.Insert(7);
    ll.Display();
}