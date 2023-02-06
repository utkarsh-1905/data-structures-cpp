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
            // cout << "Inserted at: " << head << endl;
            return head;
        }
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        // cout << "Inserted at: " << temp->next << endl;
        return temp->next;
    }

    void Print()
    {
        if (head == NULL)
        {
            cout << "List is empty !!" << endl;
            return;
        }

        Node *itr = head;

        while (itr != NULL)
        {
            cout << itr->data << endl;
            itr = itr->next;
        }
    }

    void Delete(int key)
    {
        if (head == NULL)
        {
            cout << "Nothing to delete !!" << endl;
            return;
        }

        Node *itr = head, *prev = NULL;

        if (head->data == key)
        {
            head = head->next;
            return;
        }

        while (itr->next != NULL)
        {
            if (itr->data == key)
            {
                prev->next = itr->next;
                delete itr;
                return;
            }
            prev = itr;
            itr = itr->next;
        }
    }

    Node *GetHead()
    {
        return head;
    }

    Node *FindPrevious(Node *curr)
    {

        Node *prev = NULL;
        Node *itr = head;
        if (head->next == NULL && head->data == curr->data)
        {
            return head;
        }
        while (curr && itr->data != curr->data)
        {
            prev = itr;
            itr = itr->next;
        }
        return prev;
    }

    void Swap(Node *first, Node *second)
    {
        if (head == NULL || first == second)
        {
            return;
        }
        Node *itr = head;
        if (itr == first)
        {
            Node *temp = second;
            head = second;
            first->next = temp->next;
            second->next = first;
            return;
        }
        // implement swap from anywhere
    }

    void Reverse()
    {
        Node *itr = head;
        Node *prev = NULL, *next = NULL;

        while (itr != NULL)
        {
            next = itr->next;
            itr->next = prev;
            prev = itr;
            itr = next;
        }

        head = prev;
    }
};

int main()
{
    LinkedList firstList;
    Node *a = firstList.Insert(5);
    Node *b = firstList.Insert(6);
    Node *c = firstList.Insert(69);
    firstList.Print();
    // cout << a->data << endl;
    firstList.Delete(6);
    // firstList.Reverse();
    firstList.Print();
}