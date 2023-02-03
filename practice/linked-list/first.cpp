#include <iostream>
using namespace std;

class Node
{

public:
    int data;
    Node *next;

    Node()
    {
        data = 0;
        next = NULL;
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

    Node *Insert(int data)
    {
        Node *newNode = new Node(data);

        if (head == NULL)
        {
            head = newNode;
            return NULL;
        }
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        return newNode;
    }

    int Print()
    {
        if (head == NULL)
        {
            cout << "List is empty !!" << endl;
            return -1;
        }

        Node *itr = head;

        while (itr != NULL)
        {
            cout << itr->data << endl;
            itr = itr->next;
        }
        return 0;
    }

    int Delete(int key)
    {
        if (head == NULL)
        {
            cout << "Nothing to delete !!" << endl;
            return -1;
        }

        Node *itr = head, *temp = head;

        while (itr->next != NULL)
        {
            if (itr->data == key)
            {
            }
            itr = itr->next;
        }
        return 0;
    }

    void Swap(Node *first, Node *second)
    {
        Node *temp = second;
        second = first;
        first = temp;
    }
};

int main()
{
    LinkedList firstList;
    Node *a = firstList.Insert(5);
    Node *b = firstList.Insert(6);
    firstList.Insert(69);
    firstList.Print();
    firstList.Swap(a, b);
    firstList.Print();
}