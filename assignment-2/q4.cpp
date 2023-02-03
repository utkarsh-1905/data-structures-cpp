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

    void Add(int data)
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
        itr = temp;
    }

    void Display()
    {

        Node *itr = head;

        if (itr == NULL)
        {
            return;
        }

        while (itr != NULL)
        {
            cout << itr->data << endl;
            itr = itr->next;
        }
    }

    void CountAndSum()
    {
        int count = 0, sum = 0;
        Node *itr = head;

        while (itr != NULL)
        {
            count++;
            sum += itr->data;
            itr = itr->next;
        }

        cout << "Sum = " << sum << endl
             << "Count = " << count << endl;
    }

    void Search(int key)
    {
        Node *itr = head;
        while (itr != NULL)
        {
            if (key == itr->data)
            {
                cout << "Found" << endl;
                return;
            }
            itr = itr->next;
        }
        cout << "Not Found" << endl;
        return;
    }

    void Delete(int key)
    {
        Node *itr = head;
        Node *temp = NULL;

        while (itr != NULL)
        {
            if (itr->data == key)
            {
                if (temp == NULL)
                {
                    head = itr->next;
                    delete itr;
                    return;
                }

                temp->next = itr->next;
                delete itr;
                return;
            }
            temp = itr;
            itr = itr->next;
        }
    }

    void IsSorted()
    {
        Node *itr = head;
        while (itr != NULL)
        {
            if (itr->next != NULL && itr->data > itr->next->data)
            {
                cout << "Not Sorted" << endl;
                return;
            }
            itr = itr->next;
        }
        cout << "Sorted" << endl;
        return;
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
    LinkedList myList;

    myList.Add(1);
    myList.Add(2);
    myList.Add(4);
    myList.Add(3);
    myList.Display();
    cout << "Reverse" << endl;
    myList.Reverse();
    myList.Display();
    // myList.CountAndSum();
    // myList.Search(5);
    // myList.Search(2);
    // myList.IsSorted();

    return 0;
}